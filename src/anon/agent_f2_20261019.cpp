#include "../common/types.h"

// 128-bit quadword type: plain assignments compile to lq/sq.
typedef int u128 __attribute__((mode(TI)));

extern u8 D_0034a458;
extern u8 D_0034a9c0;
extern u8 D_0034a9d0;
extern u8 D_0034a9e0;
extern u8 D_0034a9e4;

// FUN_00146680 (48 bytes)
// Code: if dst != src, copy 64 bytes (four quadwords) from src to dst.
// Guess: copy a 4x4 float matrix (or 64-byte block) between objects, skipping self-copies.
// Note: the quadwords are pinned to t0..t3 and each load/store is separated by an empty
// memory barrier, so the original load order and store order (0, 16, 32, 48) are kept.
void func_00146680(u128* d, u128* s) {
    register u128 q0 asm("$8");
    register u128 q1 asm("$9");
    register u128 q2 asm("$10");
    register u128 q3 asm("$11");
    if (d != s) {
        q0 = s[0];
        __asm__ volatile("" ::: "memory");
        q1 = s[1];
        __asm__ volatile("" ::: "memory");
        q2 = s[2];
        __asm__ volatile("" ::: "memory");
        q3 = s[3];
        d[0] = q0;
        __asm__ volatile("" ::: "memory");
        d[1] = q1;
        __asm__ volatile("" ::: "memory");
        d[2] = q2;
        __asm__ volatile("" ::: "memory");
        d[3] = q3;
    }
}

// FUN_0014fba0 (84 bytes)
// Code: zero a table of 19 entries, 3 u16 each, starting at D_0034a458 (6 bytes per entry).
// Guess: clear a 19 x 3 halfword table (for example per-slot counters or flags).
// Note: the base address is built as lui into t7 then addiu into t4 (asm, to keep the
// original pair). The loop index i is pinned to t5, the inner counter to t6. h = i*2 is
// computed at the top of each pass (GCC then rotates it into the delay slot of a bnezl).
// The byte offset is ((i*2 + i) << 1), with an empty asm stopping GCC from making it i*6.
void func_0014fba0(void) {
    register u8* base asm("$12");
    register u8* tmp asm("$15");
    register s32 i asm("$13");
    register s32 j asm("$14");
    s32 h;
    u16* p;
    __asm__ volatile("lui %0, %%hi(D_0034a458)" : "=r"(tmp));
    i = 0;
    __asm__ volatile("addiu %0, %1, %%lo(D_0034a458)" : "=r"(base) : "r"(tmp));
    do {
        h = i << 1;
        __asm__ volatile("" : "+r"(h));
        j = 2;
        __asm__ volatile("" : "+r"(j));
        s32 k = h + i;
        __asm__ volatile("" : "+r"(k));
        k <<= 1;
        p = (u16*)((u8*)((u32)k + (u32)base));
        do {
            *p = 0;
            p++;
            j--;
        } while (j >= 0);
        i++;
    } while (i < 19);
}

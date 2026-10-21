#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 D_0036e928[];
extern u8 D_0036e92c[];
extern u32 D_0036eb28[];

// FUN_001e1df8 (72 bytes)
// Code: if the float constant at 0x36e928 (20.0) is <= the float at a0+3556, then
// zero a0+3560, a0+3580 and a0+3556 (as int bits), load the float constant at 0x36e92c
// (10.0), store it to a0+3576 and a0+3572, and set the int at a0+3520 to 4.
// Guess: a gauge or timer that resets to a fixed step once its value reaches a limit.
// Matching: the object is built with -fno-sched-interblock, which stops GCC from hoisting the
// second address's lui into the c.le.s/bc1f gap. The first address is pinned to t7 with a
// lui asm and a memory-clobbered addiu asm so the addiu follows the field load. The second
// address and the constant 4 are pinned the same way to keep the store order.
void func_001e1df8(u8* a0) {
    register u8* p asm("$15");
    __asm__ volatile("lui %0,%%hi(D_0036e928)" : "=r"(p));
    register f32 fld asm("$f1") = *(f32*)(a0 + 3556);
    __asm__ volatile("addiu %0,%0,%%lo(D_0036e928)" : "+r"(p) :: "memory");
    register f32 k1 asm("$f0") = *(f32*)p;
    __asm__ volatile("" : "+f"(fld), "+f"(k1));
    if (k1 <= fld) {
        register u8* q asm("$15") = D_0036e92c;
        *(s32*)(a0 + 3560) = 0;
        __asm__ volatile("" : "+r"(q));
        *(s32*)(a0 + 3580) = 0;
        __asm__ volatile("" ::: "memory");
        f32 k2 = *(f32*)q;
        *(s32*)(a0 + 3556) = 0;
        {
            register s32 four asm("$15") = 4;
            __asm__ volatile("" : "+r"(four));
            __asm__ volatile("" ::: "memory");
            *(f32*)(a0 + 3576) = k2;
            __asm__ volatile("" ::: "memory");
            *(s32*)(a0 + 3520) = four;
        }
        __asm__ volatile("" ::: "memory");
        *(f32*)(a0 + 3572) = k2;
    }
}

// FUN_001e2660 (84 bytes)
// Code: loops over up to 10 records of 16 bytes, starting at a0. It stops at the first
// record whose byte at +172 is zero. The record gets a 16-byte copy of a1 at +160 (skipped
// when the two addresses are equal), then byte +173 = 0, +175 = 30, +172 = 0x80 and +174 = 0.
// If no record is free the function returns with no change.
// Guess: slot allocator that claims the first free entry of a small pool.
// Matching: the 16-byte copy is one lq/sq asm block on a pinned destination (t7) so the
// loop and the branch-likely shape match. The constants are pinned so the stores come
// out in the original order (30 in t7 before the byte 173 store, -128 in t6 after it).
void func_001e2660(u8* a0, u8* a1) {
    s32 n = 0;
    u8* p = a0;
loop:
    n++;
    if (p[172] != 0) goto tail;
    {
        register u8* d asm("$15") = p + 160;
        __asm__ volatile("" : "+r"(d));
        if (d != a1) {
            __asm__ volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(d), "r"(a1) : "$8", "memory");
        }
    }
    {
        register s32 c asm("$15") = 30;
        __asm__ volatile("" : "+r"(c));
        __asm__ volatile("" ::: "memory");
        p[173] = 0;
        __asm__ volatile("" ::: "memory");
        register s32 m asm("$14") = -128;
        __asm__ volatile("" : "+r"(m));
        p[175] = c;
        __asm__ volatile("" ::: "memory");
        p[172] = m;
    }
    __asm__ volatile("" ::: "memory");
    p[174] = 0;
    return;
tail:
    if (n >= 10) return;
    p += 16;
    goto loop;
}

// FUN_001e35f0 (96 bytes)
// Code: switch on the byte at a0+168. Even values 2..12 return v/2 (1..6). Odd values,
// 0 and anything >= 13 return 0. The jump table is at 0x36eb28, kept in place with a
// computed goto. Same shape as FUN_001e3590 (table at 0x36eaf8).
// The empty asm takes every label's address so the blocks stay in the original order:
// 1,2,3,4,5,0,6.
s32 func_001e35f0(u8* a0) {
    u32 i = *(u8*)(a0 + 168);
    __asm__ volatile("" :: "X"(&&L6), "X"(&&L0), "X"(&&L5), "X"(&&L4), "X"(&&L3), "X"(&&L2), "X"(&&L1));
    if (i >= 13) goto L0;
    goto *(void*)D_0036eb28[i];
L1: return 1;
L2: return 2;
L3: return 3;
L4: return 4;
L5: return 5;
L0: return 0;
L6: return 6;
}

#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_00258dc8 (40 bytes)
// Code: stores -1 as a halfword into four consecutive s16 slots at 0x35F090..0x35F096
//       (D_00360000 - 3952 .. - 3946). Stores run in the order 090, 096, 092, 094.
// Guess: resets a four-entry table of signed 16-bit ids to "none".
// Matching tricks: the base is a literal 0x00360000 pinned to a register. Each store
//       then folds its offset into the displacement, so gcc emits one lui per pair
//       (two lui per pair, two bases in $14 and $15). Empty "+r" asm barriers stop the
//       stores being reordered. The -1 value is pinned to $13 (t5).
void func_00258dc8(void) {
    register s32 m asm("$13") = -1;
    register u8* p asm("$15") = (u8*)0x00360000;
    register u8* q asm("$14") = (u8*)0x00360000;
    __asm__ volatile("" : "+r"(p), "+r"(q));
    *(s16*)(p - 3952) = m;
    *(s16*)(q - 3946) = m;
    p = (u8*)0x00360000;
    q = (u8*)0x00360000;
    __asm__ volatile("" : "+r"(p), "+r"(q));
    *(s16*)(p - 3950) = m;
    *(s16*)(q - 3948) = m;
}

// ---------------------------------------------------------------------------
// FUN_002594b8 (88 bytes)
// Code: looks up a0 among 4-byte records {s16 key, u16 val} starting at D_00372be0 (the
//       table's first key must be non-negative). Records are scanned until a negative key.
//       A matching key returns its u16 val; otherwise the result is -1.
// Guess: id -> value lookup in a small table (same shape as FUN_00259460 at 0x372b50).
// Matching tricks: the table is an extern struct array so gcc emits lui/addiu with paired
//       relocations. The return value is pinned to $2 (v0 = -1 at the top).
extern u8 D_00360000[];
struct E2594b8 { s16 key; u16 val; };
extern E2594b8 D_00372be0[];

s32 func_002594b8(s32 a0) {
    register s32 r asm("$2") = -1;
    s32 i = 0;
    while (D_00372be0[i].key >= 0) {
        if (D_00372be0[i].key == a0) return D_00372be0[i].val;
        i++;
    }
    return r;
}

// ---------------------------------------------------------------------------
// FUN_002671e8 (96 bytes)
// Code: n = signed byte at +32 of the object at the pointer stored at D_00360000 - 3868,
//       mask = word at +24. For i in 0..9, k = n*10 + i. If bit k of mask is set, the
//       a0-th such bit (counting from 0) returns k. Otherwise the result is -1.
// Guess: finds the index of the a0-th set flag in a 10-bit window whose base is n*10.
// Matching tricks: pinned registers for each value (one = 1 in $8, index $12, cnt $10,
//       k $11, bit $15, mask $9, n*10 $13, return $2). Empty asm barriers keep the
//       loads, the constant 1, the index increment, and the k/bit updates in their
//       original order. A do/while (the first iteration is always taken) avoids the
//       extra entry test.
s32 func_002671e8(s32 a0) {
    register s32 r asm("$2") = -1;
    register u32 one asm("$8");
    register u32 mask asm("$9");
    register s32 n10 asm("$13");
    register s32 cnt asm("$10");
    register s32 i asm("$12");
    register s32 k asm("$11");
    register u32 bit asm("$15");
    u8* p = *(u8**)((u32)&D_00360000[0] - 3868u);
    __asm__("" : "+r"(r));
    __asm__("" : "+r"(p));
    cnt = 0;
    __asm__ volatile("" : "+r"(cnt));
    i = 0;
    __asm__ volatile("" : "+r"(i));
    one = 1;
    __asm__ volatile("" : "+r"(one));
    n10 = (s8)p[32] * 10;
    mask = *(u32*)(p + 24);
    do {
        k = n10 + i;
        __asm__ volatile("" : "+r"(k));
        i++;
        __asm__ volatile("" : "+r"(i));
        bit = one << k;
        __asm__ volatile("" : "+r"(bit));
        if (mask & bit) {
            if (cnt == a0) { r = k; break; }
            cnt++;
        }
    } while (i < 10);
    return r;
}

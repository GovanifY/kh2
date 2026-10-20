#include "../common/types.h"

// FUN_00160488 (76 bytes)
// Code: three byte products. a0[680+i] = ((a0[420+i] * (a_{i+1} & 0xff)) >> 7) for i = 0..2.
// Guess: scales three colour/volume bytes by three 0..255 factors (result 0..255 range /128).
// Note: the original has a 16-byte frame whose "addiu sp,-16" the scheduler floated down
//       after the first mult and whose release sits in the jr delay slot. gcc only does that
//       when a stack slot exists but is never touched. The empty volatile asm with an "=m"
//       output on an otherwise unused local creates the slot without emitting any access,
//       and placing it after the last store keeps the rest of the schedule untouched.
void func_00160488(u8* a0, u32 a1, u32 a2, u32 a3) {
    u32 buf;
    u8* p = a0 + 420;
    u32 c0 = a0[420];
    u32 c1 = p[1];
    u32 c2 = p[2];
    a1 = a1 & 0xffu;
    a2 = a2 & 0xffu;
    a3 = a3 & 0xffu;
    a1 = a1 * c0;
    a2 = a2 * c1;
    a3 = a3 * c2;
    a0[680] = (u8)((s32)a1 >> 7);
    a0[681] = (u8)((s32)a2 >> 7);
    a0[682] = (u8)((s32)a3 >> 7);
    __asm__ volatile("" : "=m"(buf));
}

// FUN_00114490 (88 bytes)
// Code: p = a0->[8]. Returns NULL if p is NULL or its count (+176) is <= 0.
//       Otherwise walks count entries of 128 bytes that start at p + (+180), and
//       returns the first entry whose first word equals a1. Returns NULL if none match.
// Guess: a keyed linear search over a table of 128-byte records owned by the object at
//        a0->[8].
// Note: r starts as 0 and is only assigned on a hit, so v0 stays zero across the loop and
//       the hit path becomes "jr ra; move v0,e". The empty asm on the shifted offset (not on
//       the index) stops strength reduction while leaving the sll as the first loop insn,
//       so the delay slot filler copies it into the back-branch. i, n and the loop bound m
//       are pinned to t4, t5 and t3 (m is an asm-opaque copy of n, giving "move t3,t5").
void* func_00114490(u8* a0, s32 a1) {
    void* r = 0;
    register s32 i asm("$12");
    register s32 n asm("$13");
    register s32 m asm("$11");
    u8* p = *(u8**)(a0 + 8);
    if (p) {
        i = 0;
        n = *(s32*)(p + 176);
        u8* base = p + *(u32*)(p + 180);
        if (n > 0) {
            m = n;
            __asm__("" : "+r"(m));
            do {
                u32 off = i << 7;
                __asm__("" : "+r"(off));
                u8* e = (u8*)(off + (u32)base);
                i++;
                if (*(u32*)e == (u32)a1) {
                    r = e;
                    break;
                }
            } while (i < m);
        }
    }
    return r;
}

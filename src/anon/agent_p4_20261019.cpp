#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_001aae28 (60 bytes), 11 parameters: a0 = out pointer, a1..a10 values.
//   a4..a7 come in t0..t3; a8..a10 are on the stack (sp+0, sp+8, sp+16).
// Code: stores the values into a 28-byte record: words at +0, +4, +8, +12,
//       +20, +24; bytes at +16..+19.
// Matching: plain C in parameter order, one store per field.
// ---------------------------------------------------------------------------
void func_001aae28(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9, u32 a10) {
    a0[0] = a1;
    a0[1] = a2;
    a0[2] = a3;
    a0[3] = a4;
    *((u8*)a0 + 16) = (u8)a5;
    *((u8*)a0 + 17) = (u8)a6;
    *((u8*)a0 + 18) = (u8)a7;
    *((u8*)a0 + 19) = (u8)a8;
    a0[5] = a9;
    a0[6] = a10;
}

// ---------------------------------------------------------------------------
// FUN_001aaf98 (76 bytes). Range test on (a1 + a3 < 0x7000), (a1 > 0x9000),
//   (a2 < 0x7300), (a2 - a4 > 0x8d00). Returns 1 if any test is true, else 0.
// Matching: r starts at 0 and is pinned by an empty asm after the first test,
//   which keeps `move v0,zero` in the delay slot of the first branch and
//   gives the branch-likely returns. The file is built with
//   -fno-sched-interblock (per-object flag in the Makefile); without it GCC
//   hoists the 0x9000 constant above the first branch.
// ---------------------------------------------------------------------------
u32 func_001aaf98(u32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u32 r = 0;
    if (a1 + a3 < 0x7000) goto one;
    asm volatile("" : "+r"(r));
    if (a1 > 0x9000) goto one;
    if (a2 < 0x7300) goto one;
    if (a2 - a4 > 0x8d00) goto one;
    return r;
one:
    r = 1;
    return r;
}

// ---------------------------------------------------------------------------
// FUN_001aebf0 (80 bytes). Looks up a pointer table at 0x1c94040 with byte
//   idx0 and reads the signed word at its base. If idx1 (byte) is less than
//   that word, stores base + 4 + idx1 * 24 at 0x1c9408c; otherwise stores 0.
// Matching: the hit case is a goto so the branch is taken on hit (bnez with
//   li in its delay slot). The table and store targets are extern symbols so
//   GCC emits lui/addiu and lui/sw pairs with relocations.
// ---------------------------------------------------------------------------
extern u32* D_01c94040[];
extern u32 D_01c9408c[];

void func_001aebf0(u8* a0) {
    u32 idx0 = a0[0];
    s32 idx1 = a0[1];
    u32* base = D_01c94040[idx0];
    if (idx1 < (s32)base[0]) goto hit;
    D_01c9408c[0] = 0;
    return;
hit:
    D_01c9408c[0] = (u32)((u8*)base + 4 + idx1 * 24);
}

#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_00360000[];
extern u8 D_00363410[];
extern u8 D_01e2bfa0[];
extern u8 D_01e2bfa4[];

// FUN_002e98b0 (60 bytes)
// Code: decrements the word at D_01e2bfa4 (stored back first), loads the pointer at
// D_01e2bfa0 as base, computes (a0 - base) >> 6 (arithmetic), then appends it to the
// table at base+1920 using the count at base+2040 as the index and bumps that count.
// Guess: a bookkeeping hook that records a shifted offset into a per-frame ring of
// words. The counter is read and written before the base load and the subtraction,
// and the index is shifted before the count is bumped, which gives the same order.
// Register pins: the value stays in $4 and the base in $13; idx/off use $15/$14.
// The base and off add use the operand order (off + base), which gives addu t6,t6,t5.
void func_002e98b0(s32 a0) {
    register u8* base asm("$13");
    register u32 cv asm("$14");
    register u32 idx asm("$15");
    register u32 off asm("$14");
    register s32 v asm("$4") = a0;
    cv = *(u32*)D_01e2bfa4;
    base = *(u8**)D_01e2bfa0;
    cv -= 1;
    *(u32*)D_01e2bfa4 = cv;
    asm volatile("" ::: "memory");
    v = (v - (s32)base) >> 6;
    asm volatile("" : "+r"(v), "+r"(base));
    idx = *(u32*)(base + 2040);
    off = idx << 2;
    asm volatile("" : "+r"(off));
    idx += 1;
    *(u32*)(base + 2040) = idx;
    *(s32*)(off + (u32)base + 1920) = v;
}

// FUN_002ea2d8 (32 bytes)
// Code: a0[1] = 1; a0[0] = &D_00363410 (a vtable-style pointer); a0[2] = 385.
// Guess: constructor-like init of a 3-word object (vtable, flag, value 385).
// The stores must stay in the order flag, vptr, value. Two empty asm barriers
// keep the stores in that order, and the vptr lives in $15 so the 385 reuses t7.
void func_002ea2d8(u32* a0) {
    register u32 vt asm("$15");
    register u32 one asm("$14");
    vt = (u32)D_00363410;
    one = 1;
    asm volatile("" : "+r"(one), "+r"(vt));
    a0[1] = one;
    asm volatile("" ::: "memory");
    a0[0] = vt;
    vt = 385;
    asm volatile("" : "+r"(vt));
    a0[2] = vt;
}

// FUN_002eaba8 (64 bytes)
// Code: loads the float at D_00360000+13376, advances a2 by 16, returns a0 in v0,
// loads the 16-byte vector at a2 and multiplies it by the float (VU0 vmulx.wxyz)
// into a 16-byte stack temp. The temp is copied to a0 unless a0 is the temp itself.
// Guess: scales a vec4 by a global float and writes it to a destination.
// Only the VU0 sequence is inline asm. The v0 move is hoisted before the VU0 block
// through a pinned return register, and the copy's delay slot is an explicit nop.
// Because gas would fill that slot with sqc2, the copy is wrapped in .set noreorder.
u8* func_002eaba8(u8* a0, u32 a1, u8* a2) {
    u128 tmp;
    register u8* ret asm("$2");
    register u128 v asm("$8");
    f32 c = *(f32*)(D_00360000 + 13376);
    a2 = a2 + 16;
    ret = a0;
    asm volatile("" : "+r"(ret));
    asm volatile("lqc2 $vf1,0(%1)\n\tmfc1 $8,%2\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,%0"
                 : "=m"(tmp) : "r"(a2), "f"(c) : "$8");
    asm volatile(".set noreorder");
    if (a0 != (u8*)&tmp) {
        asm volatile("nop" : "+r"(a0));
        v = tmp;
        *(u128*)a0 = v;
    }
    asm volatile(".set reorder");
    return ret;
}

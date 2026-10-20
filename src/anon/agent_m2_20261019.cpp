#include "../common/types.h"

extern u8 D_00350000;

typedef int u128 __attribute__((mode(TI)));

// FUN_0019fb70 (84 bytes)
// Code: copies the 16-byte vector at a1+32 to a stack temp, zeroes its y word,
// takes the length of the xz part with VU0 (vmul, vaddy, vaddz, vsqrt), multiplies it
// by the float at +28 of the object at global D_00350000+8496, and stores the result
// at a1+244 with a zero word at a1+248.
// Guess: horizontal distance (xz plane) scaled by a per-game factor.
// Notes: the VU0 part is one inline asm block. Empty barriers keep the address
//        computation (addiu t7) and the store order. The object is built with
//        -falign-functions=1 (84 bytes, no padding). Only the lui/lo16 relocation differs in the .o.
void func_0019fb70(void* a0, u8* a1) {
    u32 tmp[4] __attribute__((aligned(16)));
    register f32 len asm("$f1");
    register u8* src asm("$15") = a1 + 32;   // addiu t7,a1,32
    __asm__ volatile("" : "+r"(src));
    register u128 v asm("$8");
    f32 scale, prod;
    v = *(u128*)src;
    *(u128*)tmp = v;
    __asm__ volatile("" ::: "memory");
    tmp[1] = 0;
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%1)\n\t"
        "vmul.xyz $vf1,$vf1,$vf1\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "vsqrt Q,$vf1x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "mtc1 $8,$f1\n\t"
        ".set reorder\n\t"
        : "=f"(len)
        : "r"(tmp), "m"(*(u128*)tmp)
        : "$8", "memory");
    scale = *(f32*)(*(u8**)(&D_00350000 + 8496) + 28);
    prod = len * scale;
    __asm__ volatile("" ::: "memory");
    *(u32*)(a1 + 248) = 0;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a1 + 244) = prod;
}

// FUN_001a1910 (64 bytes)
// Code: a0 is an array of 12-byte records {cur, hi, lo}. Picks record a2. Reads lo
// first, then t = cur + a1. Starts with v = lo; if t >= lo, v = t, and if hi < t,
// v = hi. Stores v back in cur and returns it.
// Guess: move a value by a delta and clamp it to a [lo, hi] window.
// Notes: lo is pinned to t7 ($15) so it is loaded first and copied to v0, as in the original.
typedef struct {
    s32 cur;  // +0
    s32 hi;   // +4
    s32 lo;   // +8
} Clamp12;

s32 func_001a1910(u8* a0, s32 a1, s32 a2) {
    Clamp12* r = (Clamp12*)(a0 + a2 * 12);
    register s32 lo asm("$15");
    s32 t;
    s32 v;
    lo = r->lo;
    t = r->cur + a1;
    v = lo;
    if (t >= lo) {
        v = t;
        if (r->hi < t) v = r->hi;
    }
    r->cur = v;
    return v;
}

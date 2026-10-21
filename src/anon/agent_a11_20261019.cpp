#include "../common/types.h"

extern u8 D_00370000[];

typedef struct {
    f32 f[4];
} vec4_a11 __attribute__((aligned(16)));

// FUN_00222568 (60 bytes)
// Code: VU0 pseudo-random number, same seed and advance as FUN_00207260 but with one
// vrxor/vrnext pair. The VU result is converted to float (mtc1), multiplied by the
// float constant at D_00370000+3016, then rounded to int with cvt.w.s and returned.
// Guess: returns a random integer in a small range, used by a random-choice helper.
// The constant address is built with a lui/addiu %hi/%lo pair pinned to t7, the same
// register the original uses. cvt.w.s is an asm block because C's cast truncates.
s32 func_00222568(void) {
    register f32 fa asm("$f0");
    register f32 fk asm("$f1");
    register u8* kp asm("$15");
    s32 res;
    __asm__ volatile(
        "addi $8,$0,-1\n\t"
        "qmtc2 $8,vf2\n\t"
        "vrxor R,vf2x\n\t"
        "vitof0.x vf2,vf2\n\t"
        "vrnext.x vf1,R\n\t"
        "vadd.x vf1,vf1,vf2\n\t"
        "qmfc2 $15,vf1\n\t"
        "mtc1 $15,%0\n\t"
        : "=f"(fa)
        :
        : "$8", "$15");
    __asm__ volatile("lui %0,%%hi(D_00370000+3016)\n\taddiu %0,%0,%%lo(D_00370000+3016)" : "=r"(kp));
    fk = *(f32*)kp;
    fa = fa * fk;
    __asm__ volatile("cvt.w.s %0,%1" : "=f"(fk) : "f"(fa));
    union {
        f32 f;
        s32 i;
    } conv;
    conv.f = fk;
    res = conv.i;
    return res;
}

// FUN_00222678 (36 bytes)
// Code: stores the float arguments in f12 and f13 into a 16-byte stack block, loads it
// as a VU0 vector, takes vmaxy.x (max of x and y) and stores it back. Returns x in $f0.
// Guess: max of two floats done through VU0.
f32 func_00222678(f32 a, f32 b) {
    vec4_a11 v;
    v.f[0] = a;
    v.f[1] = b;
    __asm__ volatile(
        "lqc2 $vf1,%0\n\t"
        "vmaxy.x $vf1,$vf1,$vf1y\n\t"
        "sqc2 $vf1,%0"
        : "+m"(v));
    return v.f[0];
}

// FUN_00222868 (48 bytes)
// Code: loads the vector at a1, computes the length of its xy part with VU0
// (vmul, vaddy, vsqrt, then vdiv for the reciprocal), multiplies xy by it, and stores
// the vector at a0.
// Guess: normalizes a 2D vector (x, y) from a1 into a0.
// The store is followed by a separate nop asm so the nop, not the store, fills the
// jr delay slot (the original has sqc2 before jr and nop after it).
void func_00222868(u8* a0, u8* a1) {
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "vmul.xy $vf31,$vf1,$vf1\n\t"
        "vaddy.x $vf31,$vf31,$vf31y\n\t"
        "vsqrt Q,$vf31x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf31,$vf0,Q\n\t"
        "vdiv Q,$vf0w,$vf31x\n\t"
        "vwaitq\n\t"
        "vmulq.xy $vf31,$vf1,Q\n\t"
        "sqc2 $vf31,0(%0)"
        :
        : "r"(a0), "r"(a1)
        : "memory");
    __asm__ volatile("nop");
}

#include "../common/types.h"

// 128-bit value type. A plain assignment compiles to lq/sq.
typedef int u128 __attribute__((mode(TI)));

// FUN_002f3ef8 (20 bytes)
// Code: lqc2 vf4 <- *a1, lqc2 vf5 <- *a2, vadd.xyzw vf6 = vf4 + vf5, sqc2 vf6 -> *a0.
// The sqc2 sits in the jr delay slot. Guess: 4-float vector add, dst = a + b.
// The VU0 instructions have no C form, so they stay as asm pieces.
void func_002f3ef8(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n\t"
        "lqc2 $vf5,0(%1)\n\t"
        "vadd.xyzw $vf6,$vf4,$vf5"
        :
        : "r"(a), "r"(b));
    __asm__ volatile("sqc2 $vf6,0(%0)" : : "r"(d) : "memory");
}

// FUN_002f3f10 (20 bytes)
// Same shape as FUN_002f3ef8, with vsub.xyzw in place of vadd. dst = a - b.
void func_002f3f10(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n\t"
        "lqc2 $vf5,0(%1)\n\t"
        "vsub.xyzw $vf6,$vf4,$vf5"
        :
        : "r"(a), "r"(b));
    __asm__ volatile("sqc2 $vf6,0(%0)" : : "r"(d) : "memory");
}

// FUN_002f3f58 (44 bytes)
// Code: loads vf4 from *a2 and vf5 from a1+48. Copies the three quads at a1+0, +16, +32
// to a0 through $7 (a3), $8 (t0), $9 (t1). Then vadd.xyz vf5 = vf5 + vf4 (w lane kept),
// and sqc2 vf5 -> a0+48. The sqc2 sits in the jr delay slot.
// Guess: copy a 52-byte struct header and update the xyz part of a vector at +48
// by adding a second vector (a position plus an offset, say).
// The quad registers are pinned so the loads and stores use the original a3/t0/t1.
// Empty memory barriers keep the loads in offset order (GCC otherwise hoists +32).
void func_002f3f58(void* dv, void* sv, void* ov) {
    register u128 q0 asm("$7");
    register u128 q1 asm("$8");
    register u128 q2 asm("$9");
    u128* d = (u128*)dv;
    u128* s = (u128*)sv;
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,48(%1)" : : "r"(ov), "r"(sv) : "memory");
    q0 = s[0];
    __asm__ volatile("" ::: "memory");
    q1 = s[1];
    __asm__ volatile("" ::: "memory");
    q2 = s[2];
    __asm__ volatile("vadd.xyz $vf5,$vf5,$vf4");
    d[0] = q0;
    d[1] = q1;
    d[2] = q2;
    __asm__ volatile("sqc2 $vf5,48(%0)" : : "r"(dv) : "memory");
}

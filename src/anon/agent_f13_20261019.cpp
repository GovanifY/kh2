#include "../common/types.h"

// 16-byte vector copy helper: lq/sq through a pinned temp.
typedef int u128 __attribute__((mode(TI)));

extern u8 D_0036ac28[];
extern u8 D_00347c00[];

// FUN_00132270 (60 bytes, object built with -falign-functions=1)
// Code: stores a1 at +4, zero at +8, +12, +16, +20, +28, +32; loads float at D_0036ac28
// and stores it at +24; stores the address of D_00347c00 at +0.
// The address halves are pinned to t7 with lui/addiu asm so that GCC keeps the
// original order (the lui for the second address sits between the sw at +12 and the swc1).
// Guess: initializes a 9-word state record with a default float and a table pointer.
void func_00132270(u32 a0, u32 a1) {
    volatile u32* p = (volatile u32*)a0;
    register u32 t asm("$15");
    asm volatile("lui %0, %%hi(D_0036ac28)" : "=r"(t));
    p[1] = a1;
    asm volatile("addiu %0, %0, %%lo(D_0036ac28)" : "+r"(t));
    p[2] = 0;
    f32 f0 = *(volatile f32*)t;
    p[3] = 0;
    asm volatile("lui %0, %%hi(D_00347c00)" : "=r"(t));
    *(volatile f32*)(a0 + 24) = f0;
    asm volatile("addiu %0, %0, %%lo(D_00347c00)" : "+r"(t));
    p[4] = 0;
    p[0] = t;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
}

// FUN_00134d60 (24 bytes)
// Code: if a0 != a1, copies the 16 bytes at a1 to a0 with lq/sq through t0.
// Guess: vector copy with a self-copy check.
void func_00134d60(u32 a0, u32 a1) {
    if (a0 != a1) {
        register u128 t asm("$8");
        t = *(u128*)a1;
        *(u128*)a0 = t;
    }
}

// FUN_00134d78 (24 bytes)
// Code: if a1 != a0, copies the 16 bytes at a0 to a1 with lq/sq through t0.
// Guess: reverse-direction vector copy with a self-copy check.
void func_00134d78(u32 a0, u32 a1) {
    if (a1 != a0) {
        register u128 t asm("$8");
        t = *(u128*)a0;
        *(u128*)a1 = t;
    }
}

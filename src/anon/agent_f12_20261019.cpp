#include "../common/types.h"

// 128-bit integer (lq/sq) type
typedef int u128 __attribute__((mode(TI)));

extern u8 D_003478F0[];

// FUN_0011a918 (28 bytes)
// Code: a0 += 64; if (a0 != a1), copies 16 bytes (lq/sq) from a1 to the new a0.
// Guess: copies a quadword into a sub-block at +64 unless source and destination are the same.
// The temp is pinned to $8 (t0) to match the original register.
void func_0011a918(u8* a0, u8* a1) {
    register u128 t0 asm("$8");
    a0 += 64;
    if (a0 != a1) {
        t0 = *(u128*)a1;
        *(u128*)a0 = t0;
    }
}

// FUN_0011b6a8 (48 bytes)
// Code: loads four quadwords from the fixed table at 0x3478f0 (base in t7 via lui/addiu),
// then stores them to arg0 at +0, +16, +32, +48.
// Guess: copies a 64-byte constant block (a 4x4 matrix) into an object.
// Layout: the four loads are pinned to $8..$11 and the base to $15 via an asm lui/addiu
// pair. Empty asm barriers keep the four loads before the stores and the stores in order.
// The final "nop" asm takes the jr ra delay slot so the last sq stays before the jump.
void func_0011b6a8(void* p) {
    u8* a0 = (u8*)p;
    register u8* b asm("$15");
    __asm__ volatile("lui %0,%%hi(%1)\n\taddiu %0,%0,%%lo(%1)" : "=r"(b) : "i"(D_003478F0));
    register u128 t0 asm("$8");
    register u128 t1 asm("$9");
    register u128 t2 asm("$10");
    register u128 t3 asm("$11");
    t0 = ((u128*)b)[0];
    __asm__ volatile("" : "+r"(t0));
    t1 = ((u128*)b)[1];
    __asm__ volatile("" : "+r"(t1));
    t2 = ((u128*)b)[2];
    __asm__ volatile("" : "+r"(t2));
    t3 = ((u128*)b)[3];
    __asm__ volatile("" : "+r"(t3));
    ((u128*)a0)[0] = t0;
    __asm__ volatile("" ::: "memory");
    ((u128*)a0)[1] = t1;
    __asm__ volatile("" ::: "memory");
    ((u128*)a0)[2] = t2;
    __asm__ volatile("" ::: "memory");
    ((u128*)a0)[3] = t3;
    __asm__ volatile("nop" ::: "memory");
}

// FUN_0011c138 (16 bytes)
// Code: two quadword stores of zero, at arg0 +0 and +16 (sq $0).
// Guess: clears a 32-byte block (two vectors) of an object.
// A C zero store compiles to a pinned copy of $0 (por), so the two sq are one asm block
// with the zero register. The trailing "nop" asm takes the jr ra delay slot.
void func_0011c138(u8* a0) {
    __asm__ volatile("sq $0,0(%0)\n\tsq $0,16(%0)" :: "r"(a0) : "memory");
    __asm__ volatile("nop" ::: "memory");
}

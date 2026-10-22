#include "../common/types.h"

// Agent W05 (2026-10-22): FUN_00168008, FUN_0016ac38, FUN_0016ac80 (SLPM_666.75).

typedef int u128 __attribute__((mode(TI)));

extern "C" u32 func_00167f38(u32 a0);
extern "C" u32 func_001de168(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0);
extern "C" u32 func_0016abf8(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 func_001dc5f8(u32 a0);

extern u8 D_00350000;
extern u8 D_004f5258;

// FUN_00168008 (56 bytes): decrement the counter at D_00350000-10368, then tail-call
// func_00167f38 with entry [new counter] of the table at D_004f5258.
u32 func_00168008(void) {
    s32 n = *(s32*)((u32)&D_00350000 - 10368u) - 1;
    *(s32*)((u32)&D_00350000 - 10368u) = n;
    return func_00167f38(*(u32*)((u32)&D_004f5258 + n * 4));
}

// FUN_0016ac38 (72 bytes): t1 = t0 ? t0 : a0 (dead in the original, kept by a volatile movz).
// If the word at a0+128 is zero, return 0. Otherwise tail-call func_001de168(a0+128, a1, a2, 1, a3).
u32 func_0016ac38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    register u32 t1 asm("$9");
    register u32 k asm("$14");
    register u32 p asm("$15");
    register u32 v asm("$13");
    register u32 one asm("$7");
    register u32 kk asm("$8");
    t1 = t0;
    asm volatile("move	%0,%1" : "=r"(k) : "r"(a3));
    asm volatile("movz	%0,%1,%2" : "+r"(t1) : "r"(a0), "r"(t0));
    p = a0 + 128;
    asm volatile("" : "+r"(p));
    v = *(u32*)(a0 + 128);
    asm volatile("li	%0,1" : "=r"(one));
    asm volatile("move	%0,%1" : "=r"(kk) : "r"(k));
    if (v != 0) return func_001de168(p, a1, a2, one, kk);
    asm volatile("" : "+r"(v));
    return 0;
}

// FUN_0016ac80 (92 bytes): p = func_0016abf8(a0, a1, a3, t0). If p is non-zero, r = func_001dc5f8(p);
// if r != a2, copy 16 bytes from a2 to r (through t0 = $8). Returns p.
u32 func_0016ac80(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    u32 p = func_0016abf8(a0, a1, a3, t0);
    if (p) {
        u32 r = func_001dc5f8(p);
        if (r != a2) {
            register u128 tmp asm("$8");
            tmp = *(u128*)a2;
            asm volatile("" : "+r"(tmp));
            *(u128*)r = tmp;
        }
    }
    return p;
}

#include "../common/types.h"

// Agent R46k_3 (2026-10-23): three functions from SLPM_666.75.

extern "C" void func_00185138(...);
extern "C" void func_001cfac0(...);
extern "C" u32 func_0016cf00(...);
extern "C" void func_00177460(...);
extern u8 D_00350000[];
extern u8 D_01c60000[];

// FUN_00171640 (80 bytes).
void func_00171640(u8* a0) {
    register u32 s0 asm("$16");
    register u8* s1 asm("$17");
    asm volatile("" ::: "memory");
    s0 = 0x01c60000u;
    asm volatile("" : "+r"(s0));
    s1 = a0;
    asm volatile("" : "+r"(s1));
    s0 = s0 - 2944u;
    asm volatile("" : "+r"(s0));
    u32 t7 = *(u32*)a0;
    u32 a1 = s0;
    u32 a2 = *(u32*)(a0 + 8);
    f32 f12 = *(f32*)(s1 + 4);
    u32 arg0 = *(u32*)(t7 + 4);
    ((void(*)(u32, u32, u32, f32))func_00185138)(arg0, a1, a2 != 0, f12);
    *(u32*)s1 = s0;
}

// FUN_00171a40 (48 bytes).
void func_00171a40(u8* a0) {
    register u32 t6 asm("$14");
    register u8* t7 asm("$15");
    t7 = a0;
    asm volatile("" : "+r"(t7));
    t6 = *(u32*)a0;
    asm volatile("" : "+r"(t6));
    f32 f15 = *(f32*)(a0 + 16);
    asm volatile("" : "+f"(f15));
    f32 f12 = *(f32*)(t7 + 4);
    asm volatile("" : "+f"(f12));
    u32 arg0 = *(u32*)(t6 + 4);
    asm volatile("" : "+r"(arg0));
    f32 f13 = *(f32*)(t7 + 8);
    asm volatile("" : "+f"(f13));
    f32 f14 = *(f32*)(t7 + 12);
    ((void(*)(u32, f32, f32, f32, f32))func_001cfac0)(arg0, f12, f13, f14, f15);
}

// FUN_00171fa8 (96 bytes).
void func_00171fa8(u8* a0) {
    u32 buf[2];
    u32 t7 = *(u32*)a0;
    u32 s0 = *(u32*)(t7 + 4);
    u32 t6 = *(u32*)(a0 + 8);
    u32 n = 1;
    buf[0] = s0;
    if (t6 != 0) {
        buf[1] = t6;
        n = 2;
    }
    u32 v = ((u32(*)(u32, u32, u32, u32*, u32))func_0016cf00)(*(u32*)(u32)&D_00350000[-10080], 0, *(u32*)(a0 + 4), buf, n);
    ((void(*)(u32, u32))func_00177460)(s0, v);
}

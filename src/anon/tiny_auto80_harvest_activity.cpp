#include "../common/types.h"


void func_00106450(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r5 = r4;
    if (r4 != 0u) {
        r4 = *(volatile u32*)((u32)r4 + (s32)(-4));
        r14 = *(volatile u32*)((u32)r4 + (s32)(0));
        r15 = *(volatile u32*)((u32)r14 + (s32)(4));
        ((void(*)(u32,u32,u32,u32))(u32)r15)(r4, r5, r6, r7);
    }
}

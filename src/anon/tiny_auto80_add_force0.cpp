#include "../common/types.h"

u32 func_00236560(u32, u32, u32, u32);


u32 func_00236440(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(32)) = r6;
    *(volatile u32*)((u32)r4 + (s32)(4)) = r5;
    return ((u32(*)())func_00236560)();
}

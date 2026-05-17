#include "../common/types.h"

u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_002520f0(u32, u32, u32, u32, u32, u32, u32, u32);

extern u8 D_0033cc18;
extern u8 D_0033cc50;
extern u8 D_00347940;
extern u8 D_00347b88;
extern u8 D_00347c00;
extern u8 D_00348698;
extern u8 D_00348d58;
extern u8 D_0035ead8;
extern u8 D_0035eae8;
extern u8 D_0035eb40;
extern u8 D_00362d20;
extern u8 D_00363410;
extern u8 D_003637e0;
extern u8 D_00367878;

void func_001022c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    *(volatile u32*)((u32)r4 + (s32)(36)) = r5;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r8;
    *(volatile u32*)((u32)r4 + (s32)(40)) = r6;
    *(volatile u32*)((u32)r4 + (s32)(44)) = r7;
    *(volatile u32*)((u32)r4 + (s32)(68)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(48)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(52)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(64)) = 0u;
}

u32 func_00106158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0033cc18;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_001070f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0033cc50;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0011ee78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347940;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00124c28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347b88;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00132310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347c00;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_002361e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035ead8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00237258(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035eae8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0023cd98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035eb40;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00252110(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    if ((s32)r4 > 0) {
        r2 = ((u32(*)())func_002520f0)();
        r15 = (u32)((s32)r16 + (1));
        if (r2 == 0u) r16 = r15;
    }
    r2 = r16;
    return r2;
}

u32 func_00252148(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    if ((s32)r4 > 0) {
        r2 = ((u32(*)())func_002520f0)();
        r15 = (u32)((s32)r16 + (-1));
        if (r2 == 0u) r16 = r15;
    }
    r2 = r16;
    return r2;
}

void func_00288f48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    *(volatile u16*)((u32)r4 + (s32)(6)) = (u16)r5;
    *(volatile u16*)((u32)r4 + (s32)(12)) = (u16)r8;
    *(volatile u16*)((u32)r4 + (s32)(8)) = (u16)r6;
    *(volatile u16*)((u32)r4 + (s32)(10)) = (u16)r7;
}

u32 func_002deaa0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00362d20;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00315608(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00367878;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031b7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031b8f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031b920(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031ba88(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348d58;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bb28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bb58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bb78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bba8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bbd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bc08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_0031bc38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_003256c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00363410;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

u32 func_00325818(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_003637e0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}

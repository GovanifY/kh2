#include "types.h"

u32 func_001058e8(u32, u32, u32, u32);
u32 func_00112570(u32, u32, u32, u32);
u32 func_00114690(u32, u32, u32, u32);
u32 func_0013b508(u32, u32, u32, u32);
u32 func_0013cb08(u32, u32, u32, u32);
u32 func_0013db60(u32, u32, u32, u32);
u32 func_00143ee8(u32, u32, u32, u32);
u32 func_0015dfd8(u32, u32, u32, u32);
u32 func_0016a020(u32, u32, u32, u32);
u32 func_0016a070(u32, u32, u32, u32);
u32 func_0016d110(u32, u32, u32, u32);
u32 func_0016f7d0(u32, u32, u32, u32);
u32 func_00170240(u32, u32, u32, u32);
u32 func_001702e0(u32, u32, u32, u32);
u32 func_0017f3d8(u32, u32, u32, u32);
u32 func_00181500(u32, u32, u32, u32);
extern "C" u32 func_001849b8(u32, u32, u32, u32) asm("_ZN2YS3OBJ10get_groundEv");
u32 func_00186008(u32, u32, u32, u32);
u32 func_00187ab8(u32, u32, u32, u32);
u32 func_00189068(u32, u32, u32, u32);
u32 func_001947c0(u32, u32, u32, u32);
u32 func_00195468(u32, u32, u32, u32);
u32 func_00198bd0(u32, u32, u32, u32);
u32 func_0019b260(u32, u32, u32, u32);
u32 func_001a3018(u32, u32, u32, u32);
u32 func_001a3570(u32, u32, u32, u32);
u32 func_001a8b28(u32, u32, u32, u32);
u32 func_001a9018(u32, u32, u32, u32);
u32 func_001b83f0(u32, u32, u32, u32);
u32 func_001bd570(u32, u32, u32, u32);
u32 func_001c0c80(u32, u32, u32, u32);
u32 func_001d52c0(u32, u32, u32, u32);
u32 func_001d7730(u32, u32, u32, u32);
u32 func_002431c0(u32, u32, u32, u32);
u32 func_00257770(u32, u32, u32, u32);
u32 func_002632d0(u32, u32, u32, u32);
u32 func_0026eda8(u32, u32, u32, u32);
u32 func_00276368(u32, u32, u32, u32);
u32 func_0027bba0(u32, u32, u32, u32);
u32 func_002b79cc(u32, u32, u32, u32);
u32 func_002b99a0(u32, u32, u32, u32);
u32 func_002bc1e8(u32, u32, u32, u32);
u32 func_002cec08(u32, u32, u32, u32);
u32 func_002ef7a0(u32, u32, u32, u32);
u32 func_002f35e8(u32, u32, u32, u32);
u32 func_002f79c8(u32, u32, u32, u32);
u32 func_003058a0(u32, u32, u32, u32);

u32 func_001125b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00112570(r4, r5, r6, r7);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(0)));
    return r2;
}

u32 func_00114600(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00114690(r4, r5, r6, r7);
    r2 = (u32)((s32)r2 + (7));
    return r2;
}

u32 func_0013b320(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0013b508(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-31584));
    *(u8*)((u32)r14 + (s32)(680)) = (u8)0u;
    return r2;
}

u32 func_0013dad0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0013db60(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u8*)((u32)r15 + (s32)(-31236)) = (u8)0u;
    return r2;
}

u32 func_00143f28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)(r4 & 0xffffu);
    r5 = (u32)(r5 & 0x00ffu);
    r2 = func_00143ee8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(0));
    r2 = (u32)(r2 & 0x000fu);
    return r2;
}

u32 func_00149db8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0015dfd8(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(-19848)) = 0u;
    return r2;
}

u32 func_0014a268(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_002b99a0(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_0014a2c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)((s32)0u + (1));
    r2 = func_002f79c8(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0002u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_0014cba0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(9284));
    return r2;
}

u32 func_0014cbc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(9288));
    return r2;
}

u32 func_0014d8a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r4 = (u32)((s32)0u + (2));
    r2 = func_002f35e8(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(-24840)) = r2;
    return r2;
}

u32 func_0016c770(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0016d110(r4, r5, r6, r7);
    r15 = (u32)(0x0033u << 16);
    r13 = *(u32*)((u32)r15 + (s32)(-18148));
    r14 = (u32)(0x004fu << 16);
    *(u32*)((u32)r14 + (s32)(25224)) = r13;
    return r2;
}

u32 func_00170950(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_001702e0(r4, r5, r6, r7);
    r15 = (u32)(*(u16*)((u32)r2 + (s32)(2)));
    r15 = (u32)((s32)r15 + (-1));
    *(u16*)((u32)r2 + (s32)(2)) = (u16)r15;
    return r2;
}

u32 func_00170d18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001702e0(r4, r5, r6, r7);
    r2 = (u32)((s32)r2 + (56));
    return r2;
}

u32 func_00170db0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)((s32)0u + (-1));
    r2 = func_00170240(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(40));
    return r2;
}

u32 func_0017f5f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0017f3d8(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r2 + (s32)(16));
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r2 + (s32)(16)) = r15;
    return r2;
}

u32 func_001883d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(140));
    r2 = func_00187ab8(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 func_00189108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00189068(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(0));
    return r2;
}

u32 func_00194a08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)((s32)0u + (-1));
    r5 = (u32)((s32)0u + (-1));
    r2 = func_001947c0(r4, r5, r6, r7);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(52)));
    return r2;
}

u32 func_00195530(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00195468(r4, r5, r6, r7);
    r2 = (u32)(~(0u | r2));
    r2 = (u32)(r2 >> 31);
    return r2;
}

u32 func_00198d00(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00198bd0(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 func_0019c470(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0016a070(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0065u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_001a3168(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001a3018(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

extern "C" u32 func_001a9080(u32, u32, u32, u32) asm("_ZNK2YS6MEMBER8is_existEi");

u32 func_001a9758(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0016f7d0(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (-13));
    r2 = (u32)(r2 & r15);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_001b8420(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_001b83f0(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r2 + (s32)(4));
    r15 = (u32)(0x01d5u << 16);
    r2 = *(u32*)((u32)r15 + (s32)(-29500));
    r2 = (u32)(r2 + r14);
    return r2;
}

u32 func_001bfca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0016a020(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0883u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_001c0ca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_001c0c80(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(4924)) = r2;
    return r2;
}

u32 func_001d01e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001a8b28(r4, r5, r6, r7);
    r2 = (u32)(*(u16*)((u32)r2 + (s32)(36)));
    return r2;
}

u32 func_001d52a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001d52c0(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 func_001d76c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001d7730(r4, r5, r6, r7);
    r2 = (u32)((s32)0u + (1));
    return r2;
}

u32 func_0020de08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r4 = (u32)((s32)0u + (2));
    r2 = func_002f35e8(r4, r5, r6, r7);
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(-28216)) = r2;
    return r2;
}

u32 func_00242a68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)(r2 >> 1);
    r2 = (u32)(r2 & 0x0003u);
    return r2;
}

u32 func_00242ce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)((s32)r2 >> 7);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 func_00242d58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)((s32)r2 >> 8);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}

u32 func_00242dc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)(r2 >> 9);
    r2 = (u32)(r2 & 0x0003u);
    return r2;
}

u32 func_00263160(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00257770(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(796));
    r2 = (u32)(r2 ^ 0x012cu);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_00263660(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_002632d0(r4, r5, r6, r7);
    r2 = (u32)(*(u16*)((u32)r2 + (s32)(14)));
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 func_0026ed20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0026eda8(r4, r5, r6, r7);
    r14 = (u32)((s32)0u + (-1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-3799)) = (u8)r14;
    return r2;
}

u32 func_00276398(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_00276368(r4, r5, r6, r7);
    r15 = (u32)(0x0036u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-3580));
    r2 = *(u32*)((u32)r14 + (s32)(388));
    r2 = (u32)(r2 ^ 0x0098u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

u32 func_002c60f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001849b8(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 func_002d0070(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_00186008(r4, r5, r6, r7);
    r14 = (u32)(0x0036u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(8104));
    r15 = (u32)((s32)r15 + (-1));
    *(u32*)((u32)r14 + (s32)(8104)) = r15;
    return r2;
}

u32 func_002e7850(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = (u32)((s32)r2 + (21920));
    return r2;
}

u32 func_002ef778(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r4 = (u32)((s32)0u + (2));
    r2 = func_003058a0(r4, r5, r6, r7);
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(14528)) = (u8)r14;
    return r2;
}
u32 func_002cef58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(8032));
    r2 = func_002cec08(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
u32 func_0022bb38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)((s32)0u + (5));
    r5 = 0u;
    r2 = func_002ef7a0(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0005u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
u32 func_001bd590(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)((s32)0u + (3));
    r2 = func_001bd570(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
u32 func_002baa20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r6 = r4;
    r5 = 0u;
    r4 = 0u;
    r2 = func_002b79cc(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

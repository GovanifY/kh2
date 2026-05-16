#include "types.h"

namespace YI {

extern u32 D_0035e370 asm("D_0035e370");
extern u8 D_01dae480[] asm("D_01dae480");

class MCARD {
public:
    static u32 isIdle();
    static u32 GetResultInfoRoot();
    static u32 GetResultChangeDir();
    static u32 GetConnectionStatus(s32, s32);
    static u32 GetFileTableMax(s32, s32);
};

u32 MCARD::isIdle() {
    u32 v = D_0035e370;
    return (v < 1u);
}

u32 MCARD::GetResultInfoRoot() {
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7108)));
}

u32 MCARD::GetResultChangeDir() {
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7092)));
}

u32 MCARD::GetConnectionStatus(s32 a0, s32 a1) {
    u32 r4 = (u32)a0;
    u32 r5 = (u32)a1;
    u32 r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);
    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    return *(volatile u32*)((u32)r4 + 12);
}

u32 MCARD::GetFileTableMax(s32 a0, s32 a1) {
    u32 r4 = (u32)a0;
    u32 r5 = (u32)a1;
    u32 r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);
    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    return *(volatile u32*)((u32)r4 + 28);
}

}  // namespace YI

#include "field2dd.hpp"

namespace dk {

extern u32 D_00347fb0 asm("D_00347fb0");
extern u32 D_00347fe4 asm("D_00347fe4");



extern "C" u32 func_0013a4c8(...);
extern "C" u32 func_0013d498(...);
extern "C" u32 func_0013b538(...);
extern "C" u32 func_0013a6b8(...);
extern "C" u32 func_00242c70(...) asm("_ZN2Tz6Config12isCommandKH2Ev");
extern u8 D_00347ff4 asm("D_00347ff4");

u32 Field2DD::getImd(s32 index) {
    u32 base = (u32)&D_00347fb0;
    u32 off = (u32)index << 3;
    return *(u32*)((u32)(base + off) + 8);
}

void Field2DD::readConfigCommand() {
    if (func_0013a4c8() != 0u) {
        if (func_0013d498() == 0u) {
            *(volatile u8*)((u32)&D_00347ff4 + (s32)(0)) = (u8)1u;
            func_0013b538();
            return;
        }
    }
}

void Field2DD::ensureMonochrome() {
    if (func_00242c70() == 0u) {
        func_0013a6b8();
        return;
    }
}

u32 Field2DD::getSqd(s32 index) {
    u32 base = (u32)&D_00347fb0;
    u32 off = (u32)index << 3;
    return *(u32*)((u32)(base + off) + 12);
}

u32 Field2DD::getSqdCommand() { return D_00347fe4; }

}  // namespace dk

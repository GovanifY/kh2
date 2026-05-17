#include "sheet.hpp"

namespace YS {



extern u32 D_00352130 asm("D_00352130");

void SHEET::start_drive(s32 a1, s32 a2) {
    a2 += 3;
    *(u8*)((u32)this + 0x1AF) = (u8)a1;
    *(u8*)((u32)this + 0x1B3) = (u8)a2;
    f32 v = *(f32*)(D_00352130 + 0x68) * (f32)a2;
    *(f32*)((u32)this + 0x1B8) = v;
    *(f32*)((u32)this + 0x1B4) = v;
}

extern "C" void func_001a1d40(u32, f32);

void SHEET::mpdrive(f32 ratio) {
    f32 f0 = ratio;
    u32 t7 = *(u32*)((u32)this + (s32)(300));
    f32 f12 = *(f32*)((u32)t7 + (s32)(28));
    u32 a0 = *(u32*)((u32)this + (s32)(1164));
    f12 = (f32)(f12 * f0);
    func_001a1d40(a0, f12);
}

}  // namespace YS

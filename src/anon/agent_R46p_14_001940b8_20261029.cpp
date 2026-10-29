#include "../common/types.h"

extern "C" void func_001ad990(u32, f32, f32, f32);

// FUN_001940b8 (56 bytes): stores three byte arguments at a0+1664..1666, then tail-calls
// FUN_001ad990(a0+2240, the float at a0+2240, f12, f13) with the two float arguments shifted one slot.
void func_001940b8(u32 a0, u32 a1, u32 a2, u32 a3, f32 f12, f32 f13) {
    *(u8*)(a0 + 1664) = (u8)a1;
    *(u8*)(a0 + 1665) = (u8)a2;
    *(u8*)(a0 + 1666) = (u8)a3;
    func_001ad990(a0 + 2240, *(f32*)(a0 + 2240), f12, f13);
}

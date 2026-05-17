#include "musical_target.hpp"

namespace sa {

extern u32 D_0035e298 asm("D_0035e298");
extern u32 D_00347e80 asm("D_00347e80");
extern u32 D_00340000 asm("D_00340000");

extern "C" void func_002361a0(u32);
extern "C" u32 func_0022b9b8();
extern "C" u32 func_00138650(u32, u32, u32, u32);



void* MUSICAL_TARGET::getImage() {
    u32 p = D_0035e298;
    return (void*)((s32)p + 32);
}

u32 MUSICAL_TARGET::init() {
    u32 p;
    u32 a0;
    u32 vtbl;
    u32 fnp;
    u32 obj;
    u32 v0;
    u32 (*fn)(u32, u32, u32);

    p = *(u32*)((u32)&D_00340000 + 32640);
    a0 = *(u32*)(p + 20);
    vtbl = *(u32*)(a0 + 0);
    fnp = *(u32*)(vtbl + 0);
    fn = (u32 (*)(u32, u32, u32))fnp;
    obj = fn(a0, 448, 0);

    *(u32*)(obj + 12) = 0;
    *(u32*)(obj + 0) = (u32)&D_00347e80;
    func_002361a0(obj + 32);
    D_0035e298 = obj;
    v0 = func_0022b9b8();
    return func_00138650(D_0035e298, 2000, v0, 11);
}

void MUSICAL_TARGET::free() {
    u32 s0 = (u32)&D_0035e298;
    u32 t7 = *(volatile u32*)((u32)s0 + 0);
    if (t7 != 0u) {
        u32 a0 = t7;
        u32 t6 = *(volatile u32*)((u32)*(volatile u32*)((u32)t7 + 0) + 16);
        ((void(*)(u32))t6)(a0);
        *(volatile u32*)((u32)s0 + 0) = 0u;
    }
}

}  // namespace sa

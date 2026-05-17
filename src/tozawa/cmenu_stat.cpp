#include "cmenu_stat.hpp"

namespace Tz {

extern u8 D_0035f0e8 asm("D_0035f0e8");

u32 CmStat::ChgSelector() {
    (void)D_0035f0e8;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-3864)));
}

extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287db0(...);
extern "C" u32 func_00257070(...);
extern "C" void func_00257050(...);
extern "C" u32 func_002670f8(...);
extern "C" u32 func_002674b8(...);
extern "C" u32 func_002670a0(...);
extern "C" u32 func_00267408(...);
extern "C" u32 func_0028fb28(...);
extern "C" u32 func_00266b58(...);
extern "C" void func_00256e80(...);
extern "C" void func_0027a108(...);
extern "C" void func_0027a7e0(...);
extern "C" void func_0027ac38(...);
extern "C" void func_0027b4e8(...);

u32 CmStat::ChgSelChara(bool a0) {
    u32 s0 = (u32)a0 & 0xFF;
    u32 t = func_00257070(23);
    t = func_002670f8(t);
    u32 v0 = func_002674b8();
    u32 s1 = t;
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    u32 idx = func_002670a0(s1);
    func_00257050(23, idx, 0);
    func_0028fb28(1, func_00267408(s1));
    return func_00266b58();
}

void CmStat::FadeOutAll() {
    u32 mode = func_00287bc0();
    if ((u32)(mode - 15) >= 5) {
        return;
    }

    func_0027a108();
    func_0027a7e0(1);
    func_0027ac38();

    if (func_00287db0() != 0) {
        func_00256e80();
    }

    if (func_00287db0() == 0) {
        return;
    }

    func_00256e80();
    func_0027b4e8();
}

}  // namespace Tz

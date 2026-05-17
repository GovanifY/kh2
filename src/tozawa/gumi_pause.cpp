#include "gumi_pause.hpp"

namespace Tz {

extern u32 D_0035f244 asm("D_0035f244");
extern u32 D_0035f24c asm("D_0035f24c");
extern u32 D_00374050 asm("D_00374050");
extern u32 D_0035f250 asm("D_0035f250");
extern u32 D_0035f254 asm("D_0035f254");
extern u32 D_00374168 asm("D_00374168");
extern u32 D_0035f264 asm("D_0035f264");
extern u32 D_0035f260 asm("D_0035f260");
extern u32 D_003740c0 asm("D_003740c0");

extern "C" u32 func_00139d78(u32);
extern "C" u32 func_00192048(u32);
extern "C" u32 func_00192c40(u32, u32);
extern "C" void func_00192cc0(u32, u32, s32);
extern "C" void func_0028d7f0(u32, u32, u32, u32, u32, s32, u32, u32, u32);
extern "C" void func_0023ef50(u32);
extern "C" void func_0027ff00();
extern "C" void func_00287bd0(u32, u32);
extern "C" void func_0027f4a8();
extern "C" u32 func_00253918();
extern "C" u32 func_002806a0();
extern "C" void func_002804f0();
extern "C" void func_00280420(void*, s32);
extern "C" void func_002539e8(u32, void*);
extern "C" void func_00280678();
extern "C" void func_002593b8(u32, u32);
extern "C" void func_00102448(u32, u32);
extern "C" void func_002806c8();
extern "C" void func_00236d60();
extern "C" u32 func_0027f3d8();
extern "C" void func_0027fba0();

void GumiPause::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002593b8(5, s0);
    func_00102448(s0, 1);
    func_002806c8();
    SetupTop();
    while (true) {
        func_00236d60();
        if (func_0027f3d8() != 0) {
            break;
        }
        func_0027fba0();
        func_00102448(s0, 0);
    }
}

void GumiPause::SetupTop() {
    func_0028d7f0(D_0035f250, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0023ef50(D_0035f250);
    func_0027ff00();
    func_00287bd0(0, 0);
    func_0027f4a8();
}

void GumiPause::UpdateAdvice() {
    u32 s0 = D_0035f264;
    u32 r = func_00192048(18694);
    s0 += 1304;
    s0 += func_00192c40(r, s0);

    u8* p = (u8*)D_0035f260;
    s8 o = ((s8*)p)[5];
    u32 q = (u32)(s32)o + (u32)p;
    s32 val = (s32)*(s8*)(q + 48);
    func_00192cc0(s0, (u32)&D_003740c0, val);

    p = (u8*)D_0035f260;
    p[6] = p[5];
    func_00280678();
}

void GumiPause::ChkLoadRequest() {
    u8 buf[64];
    if (func_00253918() != 0) {
        return;
    }

    u8* p = (u8*)D_0035f260;
    if ((s8)p[6] < 0) {
        return;
    }
    if ((s8)p[7] >= 0) {
        return;
    }

    if (func_002806a0() != 0) {
        return;
    }

    func_002804f0();
    u8* p1 = (u8*)D_0035f260;
    func_00280420(buf, (s32)(s8)p1[6]);
    func_002539e8(6, buf);

    u8* p2 = (u8*)D_0035f260;
    u8 b = p2[6];
    p2[7] = b;
    u8* p3 = (u8*)D_0035f260;
    p3[6] = 0xff;
}

}  // namespace Tz

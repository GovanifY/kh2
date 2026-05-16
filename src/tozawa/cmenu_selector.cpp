#include "types.h"

namespace dk {
class Sprite;
}

struct TASK;

namespace YI {
class SEQUENCE;
}

namespace Tz {

extern u32 D_0035f3fc asm("D_0035f3fc");
extern u32 D_0035f3f8 asm("D_0035f3f8");
extern u32 D_0035f40c asm("D_0035f40c");
extern u32 D_0035f124 asm("D_0035f124");
extern "C" u32 func_0026db60(...);
extern "C" void func_0027dc20(...);
extern "C" void func_00290738(...);
extern "C" void func_00290668(...);
extern "C" void func_00287bd0(...);
extern "C" void func_00287cc0(...);
extern "C" u32 func_00167f18(...);
extern "C" u32 func_00287cd0(...);
extern "C" u32 func_00290740(...);
extern "C" u32 func_00242618(...);
extern "C" void func_0028dac8(...);
extern "C" void func_0026ec70(...);
extern "C" void func_00102448(...);
extern "C" void func_0026dda0(...);
extern "C" u32 func_0026e5b8(...);
extern "C" void func_0026e940(...);
extern "C" void func_001396b0(...);
extern "C" void func_0031ac78(...);

class MenuCursor {
public:
    static u32 GetPri(s32);
    static dk::Sprite* GetSprite(s32);
    static bool isInit();
    static void SetParentSeq(s32, YI::SEQUENCE*);
};

u32 MenuCursor::GetPri(s32 index) {
    return *(u32*)(D_0035f40c + (u32)index * 4);
}

class Selector {
public:
    static u32 SelExit();
    static void SetupHelpGra();
    static void Control(TASK*);
    static void PauseThread(TASK*);
};

dk::Sprite* MenuCursor::GetSprite(s32 index) {
    u32 base = D_0035f3fc;
    return reinterpret_cast<dk::Sprite*>(base + ((u32)index * 408));
}

bool MenuCursor::isInit() { return D_0035f3f8 != 0; }

void MenuCursor::SetParentSeq(s32 index, YI::SEQUENCE* seq) {
    u32 p = D_0035f3fc + (u32)index * 408;
    *(u32*)(p + 400) = (u32)seq;
    func_001396b0(p);
    if (*(u32*)(p + 400) != 0) {
        *(u32*)(p + 396) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 396) != 0) {
            func_0031ac78(p, 0);
        }
    }
}

u32 Selector::SelExit() { return func_0026db60(); }

void Selector::SetupHelpGra() {
    u32 a;
    u32 b;
    func_0027dc20((u32)&a, (u32)&b);
    func_00290738(D_0035f124, 30027);
    func_00290668(D_0035f124, a, b, 0);
    func_00287bd0(1, 0);
    func_00287cc0(1);
}

void Selector::Control(TASK*) {
    u32 s0 = func_00167f18(0);
    u32 v = func_00287cd0();
    if (v == 2) {
        if (func_00290740(D_0035f124) == 0) {
            func_00287bd0(0, 0);
            func_00287cc0(1);
        }
        return;
    }
    u64 f = *(u64*)(s0 + 8);
    if ((f & 0xC) == 0) {
        return;
    }
    func_00242618(9, 1);
    func_0028dac8(D_0035f124, 1);
    func_00287cc0(2);
}

void Selector::PauseThread(TASK* task) {
    u32 s0 = (u32)task;
    func_0026ec70(s0);
    func_00102448(s0, 1);
    func_0026dda0();
    while (1) {
        if (func_0026e5b8(s0) != 0) {
            return;
        }
        func_0026e940();
        func_00102448(s0, 0);
    }
}

}  // namespace Tz

#include "cmenu_selector.hpp"
#include "cmenu_slbase.hpp"
#include "menu_sound.hpp"

namespace Tz {

extern u32 D_0035f3fc asm("D_0035f3fc");
extern u32 D_0035f3f8 asm("D_0035f3f8");
extern u32 D_0035f40c asm("D_0035f40c");
extern u32 D_0035f124 asm("D_0035f124");
extern "C" void func_001396b0(...);
extern "C" void func_0028dac8(...);
u32 MenuCursor::GetPri(s32 index) {
    return *(u32*)(D_0035f40c + (u32)index * 4);
}

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
                MenuCursor::SetFlag(p, 0);
            }
        }
}

u32 Selector::SelExit() { return SelExitImpl(); }

void Selector::SetupHelpGra() {
    u32 a;
    u32 b;
    GetHelpGraPos((u32)&a, (u32)&b);
    SetHelpGraMsg(D_0035f124, 30027);
    CreateHelpGra(D_0035f124, a, b, 0);
    MenuBase::NextModeToMode(1, 0);
    SetState(1);
}

void Selector::Control(TASK*) {
    u32 s0 = MenuCursor::GetInputState(0);
    u32 v = GetState();
    if (v == 2) {
        if (HelpGraDone(D_0035f124) == 0) {
            MenuBase::NextModeToMode(0, 0);
            SetState(1);
        }
        return;
    }
    u64 f = *(u64*)(s0 + 8);
    if ((f & 0xC) == 0) {
        return;
    }
    MenuSound::PlaySE(9, true);
    func_0028dac8(D_0035f124, 1);
    SetState(2);
}

void Selector::PauseThread(TASK* task) {
    u32 s0 = (u32)task;
    PauseTaskSetup(s0);
    TaskYield(s0, 1);
    PauseTaskBegin();
    while (1) {
        if (PauseTaskIsDone(s0) != 0) {
            return;
        }
        PauseTaskUpdate();
        TaskYield(s0, 0);
    }
}

}  // namespace Tz

#include "cmenu_selector.hpp"
#include "cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../harata/libdk/sprite.hpp"

namespace dk {
class Sprite;
}

namespace Tz {

extern u32 D_0035ef78 asm("D_0035ef78");
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f028 asm("D_0035f028");
extern u32 D_0035f038 asm("D_0035f038");
extern u32 D_00372978 asm("D_00372978");
extern u32 D_003729c8 asm("D_003729c8");
extern u32 D_003729e0 asm("D_003729e0");
extern u32 D_003729f0 asm("D_003729f0");
extern u16 D_00372a28 asm("D_00372a28");
extern u32 D_0035f024 asm("D_0035f024");
extern u32 D_0035f034 asm("D_0035f034");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f03c asm("D_0035f03c");
extern u8 D_00372a00 asm("D_00372a00");
extern u8 D_00372a08 asm("D_00372a08");
extern u8 D_0035f055 asm("D_0035f055");

extern "C" u32 func_0028f690(...);
extern "C" u32 func_00139d78(...);
extern "C" void func_001396b0(...);
extern "C" u32 func_0028acc8(...);
extern "C" void func_0028abe0(...);
extern "C" void func_0028da70(...);
extern "C" void func_0028dac8(...);
extern "C" void func_0031a260(...);

u32 CmTop::ExitParty() { return ExitPartyImpl(); }

u32 CmTop::isExistListAll() {
    u32 r16 = GetTopBase();
    u32 r2 = func_00139d78(r16);
    u32 r4 = 0u;
    if (r2 != 0u) {
        u32 r15 = *(volatile u32*)((u32)r16 + (s32)(388));
        r15 = (u32)(r15 ^ 0x00eau);
        r4 = ((u32)r15 < 0x00000001u);
    }
    return r4;
}

dk::Sprite* CmTop::GetBaseSprite(s32 index) {
    u32 base = D_0035f028;
    return reinterpret_cast<dk::Sprite*>(base + ((u32)index * 408));
}

void CmTop::CreateShortCutInfo(dk::Sprite* sprite) {
    u32 s1 = (u32)sprite;
    u32 s0 = GetTopBase() + 2504;
    if (func_00139d78(s0) == 0) {
        u32 v0 = MenuCursor::GetPri(0);
        MenuCursor::Create(s0, v0, D_0035ef68, D_0035ef64, D_0035f03c, 24, -1, 0x8454, 0);
        *(u32*)(s0 + 432) = 2;
    }
    MenuCursor::AttachSprite(s0, s1);
}

void CmTop::LeaveShortCutInfo() {
    u32 s0 = GetTopBase() + 2504;
    if (func_00139d78(s0) != 0) {
        *(u32*)(s0 + 396) = 0;
        func_001396b0(s0);
        if (*(u32*)(s0 + 396) != 0) {
            *(u32*)(s0 + 400) = 0;
            func_001396b0(s0);
            if (*(u32*)(s0 + 400) != 0) {
                func_0031a260(s0, 0);
            }
        }
        ((dk::Obj2D*)s0)->leave();
    }
}

void CmTop::FadeOutPadHelp() {
    func_0028dac8(GetTopBase() + 2940, 239);
}

void CmTop::LoopPadHelp() {
    u32 s0 = GetTopBase() + 2940;
    u32 v0 = func_00139d78(s0);
    if (v0 != 0) {
        func_0028da70(s0, 238);
    }
}

extern u8 D_0035f054 asm("D_0035f054");

void CmTop::SetHideCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    *(u8*)&D_0035f054 = (u8)v;
}

extern u32 D_0035f050 asm("D_0035f050");

void CmTop::DelCursor() {
    MenuCursor::DeleteAll();
    if (MenuCursor::isAlive(D_0035f050) != 0) {
        u32 t7 = D_0035f050;
        u32 t6 = *(u32*)t7;
        u32 t5 = *(u32*)(t6 + 20);
        ((void(*)(u32))t5)(t7);
    }
}

s32 CmTop::GetCurPos(s32 index) {
    return (s32)(*(s16*)((u32)&D_0035ef78 + ((u32)index << 1)));
}

s32 CmTop::GetCurTopPos(s32 index) {
    u32 p = (u32)&D_0035ef78 + ((u32)index << 1);
    return (s32)(*(s16*)(p + 76));
}

s32 CmTop::GetSelectPos(s32 index) {
    return (s32)(GetCurPos(index) + GetCurTopPos(index));
}

void CmTop::LeaveWarningWin() {
    if (func_00139d78(D_0035f034) != 0) {
        ObjCmTopWarningWin* obj = (ObjCmTopWarningWin*)D_0035f034;
        obj->vtbl->fn20(obj);
    }

    if (func_0028acc8(D_0035f024) != 0) {
        func_0028abe0(D_0035f024);
    }
}

void CmTop::LoopWarningWin(s32 which) {
    u32 s0 = (u32)which;
    if (IsWarningEnabled(s0) == 0) {
        return;
    }

    u8* p;
    if (s0 != 0u) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    func_0028da70(D_0035f034, *(s16*)(p + 4));
}

void CmTop::LeavePadHelp() {
    u32 s0 = GetTopBase() + 2940;
    if (func_00139d78(s0) != 0) {
        ((dk::Obj2D*)s0)->leave();
    }
}



extern "C" u32 getSaveRam() asm("_Z10getSaveRamv");

u32 CmTop::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 16808);
    return r2;
}

u16* CmTop::GetTopSelSeqTbl() { return (u16*)&D_00372a28; }

void CmTop::SetDelCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    D_0035f055 = (u8)v;
}

void* CmTop::GetScrBarSeqTbl() { return &D_003729c8; }

void* CmTop::GetTopPlateSeqTbl(s32 index) {
    return reinterpret_cast<void*>((u32)&D_003729e0 + ((u32)index << 3));
}

void* CmTop::GetTopPlate2SeqTbl(s32 index) {
    return reinterpret_cast<void*>((u32)&D_003729f0 + ((u32)index << 3));
}

void* CmTop::GetPartyInfo() { return reinterpret_cast<void*>(D_0035f010); }

void* CmTop::GetItemInfo() {
    return reinterpret_cast<void*>(*(u32*)((u32)&D_0035f010 + 4));
}

s32 CmTop::GetFontColorSeqNum(s32 index) {
    return (s32)(*(s16*)((u32)&D_00372978 + ((u32)index << 1)));
}

void* CmTop::GetListBuffer() { return reinterpret_cast<void*>(D_0035f038); }

}  // namespace Tz

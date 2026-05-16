#include "types.h"

namespace dk {
class Sprite;
}

struct ALLOCATOR;

namespace Tz {

class Select;

extern u8 D_00360000 asm("D_00360000");

extern u32 D_0035f158 asm("D_0035f158");
extern u32 D_0035f204 asm("D_0035f204");
extern u32 D_0035f200 asm("D_0035f200");
extern u32 D_0035f144 asm("D_0035f144");
extern u32 D_0035f138 asm("D_0035f138");
extern u32 D_0035f140 asm("D_0035f140");
extern u32 D_0035f1fc asm("D_0035f1fc");
extern u8 D_0035f220 asm("D_0035f220");
extern u32 D_0035f21c asm("D_0035f21c");
extern u32 D_0035f20c asm("D_0035f20c");
extern u32 D_0035f214 asm("D_0035f214");
extern u32 D_0035f218 asm("D_0035f218");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u32 D_00373d88 asm("D_00373d88");
extern u32 D_00373d80 asm("D_00373d80");
extern u32 D_00373da0 asm("D_00373da0");
extern "C" void func_00293bd0(u32, u32, u32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00274db8();
extern "C" u32 func_00274e50(...);
extern "C" void func_00274e08();
extern "C" void func_00275d10();
extern "C" u32 func_0028acc8(...);
extern "C" void func_0028abe0(...);
extern "C" u32 func_0028be58(...);
extern "C" void func_0028be18(...);
extern "C" void func_002766e0();
extern "C" void func_00293e00(u32);
extern "C" void func_0028d980(...);
extern "C" void func_00293fc0();
extern "C" void func_00294020(u32);
extern "C" u32 func_0028d6e8(...);
extern "C" void func_0028d1c0(...);
extern "C" void func_0028d660(...);
extern "C" void func_00293eb0() asm("_ZN2Tz6JmInfo4ExitEv");
extern "C" u32 func_00293d80(...);

class Jiminy {
public:
    static void DrawSelector(Select*, s32, s32);
    static void JmCommonLeave();
    static void CreateLightCursor(::dk::Sprite*);
    static void SetupMainFrame();
    static u32 GetAccomplishmentRate();
    static u32 WMRead();
    static u32 WMExit();
    static void WMInit(ALLOCATOR*);
    static void InitWorldNo(s32);
    static void SetCover(s32);
    static void SetHideCursor(bool);
    static void SetHideLightCursor(bool);
    static void SaveCurPos(s32, s32, s32);
    static void* GetParent();
    static s32 GetParentAnimMode();
    static void* GetMenuInfo();
    static s32 GetCurPos(s32);
    static s32 GetCurTopPos(s32);
    static s32 GetSelectPos(s32);
    static void* GetSeqTbl();
    static void* GetScrBarSeqTbl();
    static s32 GetFontColorSeqNum(s32);
};

extern "C" u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
extern "C" void func_00296ed0() asm("_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii");
extern "C" u32 func_002ad018(...);

void Jiminy::DrawSelector(Select*, s32, s32) {
    if (func_00289310() != 0u) {
        func_00296ed0();
    }
}

void Jiminy::JmCommonLeave() {
    if (func_0028acc8(D_0035f200) != 0) {
        func_0028abe0(D_0035f200);
    }

    if (func_00139d78(D_0035f204) != 0) {
        u32 obj = D_0035f204;
        u32 vtbl = *(u32*)obj;
        u32 fn = *(u32*)(vtbl + 20);
        ((void (*)(u32))fn)(obj);
    }

    if (func_0028be58(D_0035f214) != 0) {
        func_0028be18(D_0035f214);
    }

    func_002766e0();
}

void Jiminy::CreateLightCursor(::dk::Sprite* a0) {
    u32 s0 = (u32)a0;
    u32 v0 = func_0028d6e8(D_0035f218);
    if (v0 == 0) {
        func_0028d1c0(D_0035f218, 30065, D_0035f14c, D_0035f148, D_0035f210, (u32)&D_00373d80, 0);
    } else {
        u32 p = D_0035f218;
        if (*(u32*)(p + 396) == s0) {
            return;
        }
        func_0028d660(p, s0);
        return;
    }
    func_0028d660(D_0035f218, s0);
}

void Jiminy::SetupMainFrame() {
    if (func_00139d78(D_0035f20c + 872) == 0) {
        func_0028d980(D_0035f20c + 872, 30040, D_0035f14c, D_0035f148, D_0035f210, 53, 54, -1, 0);
        *(u32*)(D_0035f20c + 1304) = 2;
    }
    func_00275d10();
}

u32 Jiminy::GetAccomplishmentRate() {
    return func_002ad018();
}

u32 Jiminy::WMRead() {
    D_0035f140 = 0;
    func_00293bd0(0, 0, 1);
    u32 r2 = func_00274db8();
    D_0035f140 |= 4u;
    return r2;
}

u32 Jiminy::WMExit() {
    *(u32*)((u8*)&D_00360000 - 3776) &= (u32)-13;
    ((u32(*)())func_00274e50)();
    func_00293eb0();
    u32 v0 = ((u32(*)(u32))func_00293d80)(0);
    *(u32*)((u8*)&D_00360000 - 3776) = 0;
    return v0;
}

void Jiminy::WMInit(ALLOCATOR* a0) {
    if ((D_0035f140 & 8) == 0) {
        u32 s0 = (u32)a0;
        func_00274e08();
        func_00293e00(s0);
        func_00293fc0();
        func_00294020(0);
        D_0035f140 |= 8;
    }
}


void Jiminy::InitWorldNo(s32 value) {
    D_0035f138 = (u32)value;
}

void Jiminy::SetCover(s32 value) {
    u32 p = D_0035f1fc;
    *(u8*)((u32)p + 1) = (u8)value;
}

void Jiminy::SetHideLightCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    *(u8*)((u32)&D_0035f1fc + 37) = (u8)v;
}

void Jiminy::SetHideCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    D_0035f220 = (u8)v;
    SetHideLightCursor(value);
}

void Jiminy::SaveCurPos(s32 index, s32 pos, s32 topPos) {
    u32 p = (u32)&D_0035f158 + ((u32)index << 1);
    *(u16*)(p + 0) = (u16)pos;
    *(u16*)(p + 82) = (u16)topPos;
}

void* Jiminy::GetParent() {
    return reinterpret_cast<void*>(D_0035f204);
}

s32 Jiminy::GetParentAnimMode() {
    return static_cast<s32>(D_0035f144);
}

void* Jiminy::GetMenuInfo() {
    return reinterpret_cast<void*>(D_0035f1fc);
}

s32 Jiminy::GetCurPos(s32 index) {
    return static_cast<s32>(*(s16*)((u32)&D_0035f158 + ((u32)index << 1)));
}

s32 Jiminy::GetCurTopPos(s32 index) {
    u32 p = (u32)&D_0035f158 + ((u32)index << 1);
    return static_cast<s32>(*(s16*)(p + 82));
}

s32 Jiminy::GetSelectPos(s32 index) {
    return GetCurPos(index) + GetCurTopPos(index);
}

void* Jiminy::GetSeqTbl() {
    return reinterpret_cast<void*>(D_0035f21c);
}

void* Jiminy::GetScrBarSeqTbl() { return &D_00373d88; }

s32 Jiminy::GetFontColorSeqNum(s32 index) {
    return static_cast<s32>(*(s16*)((u32)&D_00373da0 + ((u32)index << 1)));
}

}  // namespace Tz

#include "mcard.hpp"

namespace Tz {

extern u32 D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec88 asm("D_0035ec88");
extern u32 D_0035ec8c asm("D_0035ec8c");
extern "C" void func_002ff3fc(...);
extern "C" void func_002feee8(...);
extern "C" u32 func_00234630(...);
extern "C" u32 func_00234650(...);
extern "C" u32 func_00181500(...);
extern "C" u32 wtarget_002fde18(u32, u32, u32) asm("_Z16wtarget_002fde18jjjj");

bool MCard::isFindSystem() {
    u32 p = D_0035ec94;
    s32 v = *(s8*)((u32)p + 5);
    return v != 0;
}

void* MCard::GetMCInfo() { return reinterpret_cast<void*>(D_0035ec94); }

extern u8 D_00360000 asm("D_00360000");
u32 MCard::ClearFileInfo() {
    return wtarget_002fde18(((u32)(*(u32*)((u32)((u32)&D_00360000) - 4972u))) + 8u, 0, 0x00000c60u);
}

void MCard::SetSystemMode(s32 mode) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-4952)) = (u32)mode;
}

u32 MCard::ChgWorldName(s32 world) {
    u32 r14 = (u32)world;
    u32 r2 = 0u;
    u32 r15 = 4u;
    u32 r4 = 4235u;
    if (r14 == r15) {
        r2 = func_00181500(r4);
        r2 = ((u32)0u < (u32)r2);
    }
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 MCard::ChgDir(s32 doSync) {
    u32 t5 = D_0035ec8c;
    *(u8*)(t5 + 0) = 47;
    u32 t6 = D_0035ec8c;
    *(u8*)(t6 + 1) = 0;
    if (doSync == 0) {
        func_002ff3fc(D_0035ec88);
        func_002feee8(D_0035ec8c, D_0035ec88);
    }
    u8* q = (u8*)D_0035ec94;
    return func_00234630((s32)*(s8*)(q + 0), D_0035ec8c, 0);
}

u32 MCard::MakeDir() {
    func_002ff3fc(D_0035ec88);
    u32 t5 = D_0035ec8c;
    *(u8*)(t5 + 0) = 47;
    u32 t6 = D_0035ec8c;
    *(u8*)(t6 + 1) = 0;
    func_002feee8(D_0035ec8c, D_0035ec88);
    u8* p = (u8*)D_0035ec94;
    return func_00234650((s32)*(s8*)(p + 0), D_0035ec8c, 0);
}

void MCard::SetSlot(s32 slot) {
    u32 p = D_0035ec94;
    *(u8*)((u32)p + 0) = (u8)slot;
}

s32 MCard::GetSlot() {
    u32 p = D_0035ec94;
    return (s32)(*(s8*)((u32)p + 0));
}

void MCard::SetPos(s32 pos) {
    u32 p = D_0035ec94;
    *(u8*)((u32)p + 1) = (u8)pos;
}

}  // namespace Tz

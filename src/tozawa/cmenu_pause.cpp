#include "cmenu_pause.hpp"

namespace Tz {

extern u32 D_0035f068 asm("D_0035f068");
extern "C" u32 func_00139d78(u32);
extern "C" void func_00138c10(u32, u32);

bool Pause::isPause() {
    s32 v = *(s8*)&D_0035f068;
    return v != 0;
}

extern u32 D_0035f088 asm("D_0035f088");
extern u32 D_0035f078 asm("D_0035f078");
extern u32 D_0035f08c asm("D_0035f08c");

u32 Pause::isExistFade() {
    u32 r14 = D_0035f088;
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = func_00139d78(r14);
    }
    return r2;
}

u32 Pause::isLoopFade() {
    u32 r16 = (u32)(0x0036u << 16);
    u32 r4 = *(u32*)((u32)r16 + (s32)(-3960));
    u32 r2 = func_00139d78(r4);
    u32 r15 = *(u32*)((u32)r16 + (s32)(-3960));
    r2 = *(u32*)((u32)r15 + (s32)(388));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

void Pause::SetNextMenu(s32 nextMenu) {
    *(u16*)((u32)&D_0035f068 + 6) = (u16)nextMenu;
}

void Pause::StartFade(void (*cb)()) {
    u32 s1 = (u32)cb;
    func_00139d78((u32)D_0035f088);
    CreateFadeObject((u32)D_0035f088, 30036, 0, 0, D_0035f078, 5, 1, 0);
    u32 t6 = (u32)D_0035f088 + 24;
    u32 t7 = *(u32*)(t6 + 184);
    t7 |= 8u;
    *(u32*)(t6 + 184) = t7;
    *(u8*)((u32)D_0035f088 + 405) = 1;
    D_0035f08c = s1;
}

void Pause::EndFade(void (*cb)()) {
    u32 s1 = (u32)cb;
    func_00139d78((u32)D_0035f088);
    func_00138c10((u32)D_0035f088, 4);
    *(s32*)((u32)D_0035f088 + 392) = -1;
    D_0035f08c = s1;
}

}  // namespace Tz

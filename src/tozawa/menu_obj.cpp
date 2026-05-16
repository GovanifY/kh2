#include "types.h"

namespace dk {
class Sprite;
}
namespace kn {
class Motion;
}

namespace Tz {

class LayMsg;

class MenuObj {
public:
    void SetAction(s32, s32, s32);
    void SetTransZ(s32, f32);
    void SetRotX(s32, f32);
    void SetRotY(s32, f32);
    void SetSyncLayMsg(s32, LayMsg*);
    void SetSyncSprite(s32, dk::Sprite*);
};

extern "C" u32 func_001a9458(...);

void MenuObj::SetAction(s32 a1, s32 a2, s32 a3) {
    u8* s1;
    u8 idx;

    a1 += (s32)(u32)this;
    idx = *(u8*)((u32)a1 + 0xb64);
    s1 = (u8*)this + ((u32)idx * 0x140) + 0x660;

    *(u32*)(s1 + 0x78) = func_001a9458(*(u32*)(s1 + 0x70), (u32)a2, *(u32*)(s1 + 0x124));
    if (a3 >= 0) {
        *(u32*)(s1 + 0x7c) = func_001a9458(*(u32*)(s1 + 0x70), (u32)a3, *(u32*)(s1 + 0x124));
    }
}

void MenuObj::SetTransZ(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1656) = a2;
}

void MenuObj::SetRotX(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1632) = a2;
}

void MenuObj::SetRotY(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1636) = a2;
}

void MenuObj::SetSyncLayMsg(s32 a1, LayMsg* a2) {
    u32 a0 = (u32)this;
    a1 = (s32)((u32)a1 << 2);
    a1 = (s32)((u32)a1 + a0);
    *(u32*)((u32)a1 + 5296) = (u32)a2;
    *(u32*)((u32)a1 + 5312) = 0u;
}

void MenuObj::SetSyncSprite(s32 a1, dk::Sprite* a2) {
    u32 a0 = (u32)this;
    a1 = (s32)((u32)a1 << 2);
    a1 = (s32)((u32)a1 + a0);
    *(u32*)((u32)a1 + 5312) = (u32)a2;
    *(u32*)((u32)a1 + 5296) = 0u;
}

}  // namespace Tz

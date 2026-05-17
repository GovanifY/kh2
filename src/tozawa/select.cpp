#include "select.hpp"

namespace Tz {
s16 Select::GetCurrent() { return reinterpret_cast<SelectLayout*>(this)->current; }
s32 Select::GetLast() {
    u32 r2 = (u32)(s32)(*(s16*)((u32)this + (s32)(4)));
    r2 = (u32)((s32)r2 + (-1));
    return (s32)r2;
}
void* Select::GetItemPtr(s32 index) { return reinterpret_cast<SelectLayout*>(this)->itemPtr[index]; }
void* Select::GetCurrentItemPtr() { return reinterpret_cast<SelectLayout*>(this)->itemPtr[reinterpret_cast<SelectLayout*>(this)->current]; }
s16 Select::GetItemMax() { return reinterpret_cast<SelectLayout*>(this)->itemMax; }
s16 Select::GetSelectMax() { return *(s16*)((u32)this + 22); }
u32 Select::isFadeOut() {
    u32 v0 = (u32)(s16)*(s16*)((u32)this + 14);
    return (u32)(0u < v0);
}
extern "C" u32 func_0028acb8(u32) __attribute__((alias("_ZN2Tz6Select9isFadeOutEv")));

extern "C" u32 func_0028b040(...);
u32 Select::isCursorMove() {
    u32 s0 = (u32)this;
    u32 ret;
    if (*(s16*)(s0 + 2) >= 0) {
        ret = ((u32(*)(void))func_0028b040)() != (u32)(s32)*(s16*)(s0 + 2);
    } else {
        ret = 0;
    }
    return ret;
}
s32 Select::GetEnableButton() { return reinterpret_cast<SelectLayout*>(this)->enableButton; }
s16 Select::GetSelectTop() { return reinterpret_cast<SelectLayout*>(this)->selectTop; }
s32 Select::SetEnableButton(u32 v) {
    reinterpret_cast<SelectLayout*>(this)->enableButton = (s32)v;
    return (s32)v;
}
s32 Select::SetDisableButton(u32 v) {
    u32 r = (u32)reinterpret_cast<SelectLayout*>(this)->enableButton;
    r &= ~(0u | v);
    reinterpret_cast<SelectLayout*>(this)->enableButton = (s32)r;
    return (s32)r;
}
void Select::SetSelectorLoop(bool v) { *(u8*)((u32)this + 36) = (u8)((u32)v & 0xffu); }
s32 Select::SetEnableShortCut(u32 v) {
    u32 r2 = *(u32*)((u32)this + (s32)(52));
    u32 r15 = (u32)((s32)0u + (-1793));
    v = (u32)(v & 0x0700u);
    r2 = (u32)(r2 & r15);
    r2 = (u32)(r2 | v);
    *(u32*)((u32)this + (s32)(52)) = r2;
    return (s32)r2;
}
void Select::SetSelectDisable(u32 v) { reinterpret_cast<SelectLayout*>(this)->selectDisable = v; }
}  // namespace Tz

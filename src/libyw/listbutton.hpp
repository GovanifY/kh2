#pragma once

#include "../common/types.h"

class COLOR;
class EVENT;
class FuncDef24;
class RECT;

namespace YW {

class LIST_BUTTON {
public:
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    void change(s32 a0);
    void ChangeCallback(EVENT a0, s32 a1, void* a2);
    LIST_BUTTON(LIST_BUTTON* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, char** a6, FuncDef24* a7, void* a8);
    ~LIST_BUTTON();
};

}  // namespace YW


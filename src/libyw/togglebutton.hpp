#pragma once

#include "../common/types.h"

class COLOR;
class EVENT;
class FuncDef42;
class FuncDef77;
class RECT;
class TOGGLE_BUTTON;

class TOGGLE_BUTTON {
public:
    TOGGLE_BUTTON(TOGGLE_BUTTON* a0, char* a1, char* a2, s32 a3, s32 a4, s32 a5, s32 a6, bool a7, FuncDef42* a8, void* a9);
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    TOGGLE_BUTTON(TOGGLE_BUTTON* a0, char* a1, s32 a2, s32 a3, s32 a4, s32 a5, bool a6, FuncDef77* a7, void* a8);
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    ~TOGGLE_BUTTON();
    ~TOGGLE_BUTTON();
};


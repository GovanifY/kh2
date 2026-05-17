#ifndef KH2_SRC_LIBYW_SCROLLBAR_HPP
#define KH2_SRC_LIBYW_SCROLLBAR_HPP

#include "types.h"

class COLOR;
class EVENT;
class IMAGE;
class RECT;
class Sprite;

class SCROLLBAR {
public:
    SCROLLBAR(SCROLLBAR* a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 a5, f32 a6, f32 a7, f32 a8);
    void set_value(f32 a0);
    void idle_func();
    void focus_func(EVENT a0, s32 a1, s32 a2);
    void draw_func(RECT* a0, COLOR* a1);
    ~SCROLLBAR();
};

class ScrollBar {
public:
    ScrollBar();
    void isExist();
    ~ScrollBar();
    void Create(s32 a0, void* a1, IMAGE* a2, short* a3, s32 a4, s32 a5, Sprite* a6, s32 a7);
    void FadeOut();
    void Loop();
    void Leave();
    void SetPos(s32 a0);
    void SetMax(s32 a0);
};

#endif

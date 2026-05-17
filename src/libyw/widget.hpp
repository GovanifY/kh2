#pragma once

#include "../common/types.h"

class COLOR;
class EVENT;
class OBJ;
class Position;
class RECT;
class STDOBJ;
class WIDGET;
class Widget;

class WIDGET {
public:
    WIDGET(WIDGET* a0, s32 a1, s32 a2, s32 a3, s32 a4);
    ~WIDGET();
    s32 desktop(void);
    void grab(void);
    void ungrab(void);
    void raise(void);
    void _draw(void);
    void draw(void);
    WIDGET();
    void draw_func(RECT* a0, COLOR* a1);
    WIDGET();
    void draw_func(RECT* a0, COLOR* a1);
    WIDGET(WIDGET* a0, OBJ* a1);
    void ExecAct(EVENT a0, s32 a1, void* a2);
    WIDGET(WIDGET* a0, STDOBJ* a1);
    void Play(void* a0);
    void Voice(void* a0);
    void idle_func(void);
    ~WIDGET();
    ~WIDGET();
};

class Widget {
public:
    Widget();
    void link(Widget* a0);
    void unlink(Widget* a0);
    s32 updateAll(void);
    void drawAll(Position a0, COLOR a1);
    u64 update(void);
    ~Widget();
};


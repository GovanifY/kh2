#ifndef KH2_SRC_LIBYW_RECT_HPP
#define KH2_SRC_LIBYW_RECT_HPP

#include "types.h"

class COLOR;

class RECT {
public:
    void add(RECT* a0);
    void clip(RECT* a0);
    u64 is_in(s32 a0, s32 a1);
    void draw_rise_window(COLOR* a0);
    void draw_sink_window(COLOR* a0);
    void draw(COLOR* a0);
    void draw_window(COLOR* a0, COLOR* a1, COLOR* a2);
    void send(void* a0);
    void send_window(void* a0);
    RECT();
    void draw();
    ~RECT();
};

class Rect {
public:
    Rect();
    void drawPacket();
    ~Rect();
};

#endif

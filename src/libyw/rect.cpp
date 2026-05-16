#include "types.h"


class COLOR;
class RECT;
class Rect;

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
 void draw(void);
 ~RECT();
};

class Rect {
public:
 Rect();
 void drawPacket(void);
 ~Rect();
};

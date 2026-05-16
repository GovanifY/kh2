#include "types.h"


class EVENT;
class FRAME;
class Frame;

class FRAME {
public:
 FRAME(FRAME* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
 void set_offset_y(s32 a0);
 void idle_func(void);
 void inside_func(EVENT* a0, s32 a1, s32 a2);
 ~FRAME();
};

class Frame {
public:
 Frame();
 void setFrame(u16 a0, u32 a1, u16 a2, u16 a3);
 s32 widthToTW(u32 a0);
};

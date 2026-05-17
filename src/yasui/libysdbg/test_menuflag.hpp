#pragma once

#include "../../common/types.h"

class COLOR;
class EVENT;
class RECT;
class TEST_MENUFLAG;

namespace YS {

    class TEST_MENUFLAG {
    public:
     TEST_MENUFLAG();
     ~TEST_MENUFLAG();
     void idle_func(void);
     void focus_func(EVENT a0, s32 a1, s32 a2);
     void draw_func(RECT* a0, COLOR* a1);
     void Open(s32 a0);
     void Init(void);
    };

}  // namespace YS


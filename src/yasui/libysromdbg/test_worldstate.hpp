#pragma once

#include "../../common/types.h"

namespace YS {

class COLOR;
class RECT;

class TEST_WORLDSTATE {
public:
    void idle_func(void);
    void draw_func(RECT* a0, COLOR* a1);
    void Open(s32 a0);
    void Init(void);
    ~TEST_WORLDSTATE();
};

}  // namespace YS


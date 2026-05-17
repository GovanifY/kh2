#pragma once

#include "../../common/types.h"

class COLOR;
class RECT;
class TEST_BATTLEREPORT;

namespace YS {

    class TEST_BATTLEREPORT {
    public:
     void printf(char* a0, ...);
     void draw_func(RECT* a0, COLOR* a1);
     void Open(s32 a0);
     void Init(void);
     ~TEST_BATTLEREPORT();
    };

}  // namespace YS


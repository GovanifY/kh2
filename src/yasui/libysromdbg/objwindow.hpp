#pragma once

#include "../../common/types.h"

class OBJ;
class OBJ_WINDOW;

namespace YS {

    class OBJ_WINDOW {
    public:
     OBJ_WINDOW(OBJ_WINDOW* a0, char* a1, OBJ* a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a7);
     void idle_func(void);
     ~OBJ_WINDOW();
    };

}  // namespace YS


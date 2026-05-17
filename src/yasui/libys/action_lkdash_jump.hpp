#pragma once

#include "../../common/types.h"

class ACTION_LKDASH_JUMP;
class FVector;
class OBJ;

namespace YS {

    class ACTION_LKDASH_JUMP {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void control(OBJ* a0);
     void land(OBJ* a0);
     void jump(OBJ* a0, FVector* a1);
     void jump_height(OBJ* a0, f32 a1);
     void calc_movement(OBJ* a0);
     ~ACTION_LKDASH_JUMP();
     ACTION_LKDASH_JUMP();
    };

}  // namespace YS


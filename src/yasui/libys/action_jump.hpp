#pragma once

#include "../../common/types.h"

class ACTION_JUMP;
class ID;
class OBJ;

namespace YS {

    class ACTION_JUMP {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void change_fall_motion(OBJ* a0);
     u64 is_change_fall_motion(OBJ* a0);
     bool CanHold(OBJ* a0);
     void control(OBJ* a0);
     double calc_movement_y(OBJ* a0);
     void _calc_movement(OBJ* a0, f32 a1, f32 a2);
     void calc_movement(OBJ* a0);
     void _land(OBJ* a0, ID a1);
     void land(OBJ* a0);
     void fall(OBJ* a0);
     void party_jump(OBJ* a0, bool a1);
     ~ACTION_JUMP();
     ACTION_JUMP();
    };

}  // namespace YS


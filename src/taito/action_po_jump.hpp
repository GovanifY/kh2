#pragma once

#include "../common/types.h"

class ACTION_PO_JUMP;
class OBJ;

namespace Ti {

    class ACTION_PO_JUMP {
    public:
     void decide_way(OBJ* a0, f32 a1, f32 a2);
     void step(OBJ* a0, f32 a1);
     u64 get_jump_motion(void);
     u64 get_fall_motion(void);
     u64 get_land_motion(void);
     void on_land(OBJ* a0);
     void on_fall(OBJ* a0);
     u64 is_release_ok(OBJ* a0, f32 a1);
     void exec_jump(OBJ* a0);
     ACTION_PO_JUMP(ACTION_PO_JUMP* a0, f32 a1, f32 a2);
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_PO_JUMP();
    };

}  // namespace Ti


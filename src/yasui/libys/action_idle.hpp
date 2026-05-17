#ifndef KH2_SRC_YASUI_LIBYS_ACTION_IDLE_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_IDLE_HPP

#include "../../common/types.h"

class ACTION_IDLE;
class OBJ;

namespace YS {

    class ACTION_IDLE {
    public:
     void change_motion(OBJ* a0, s32 a1);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     void Jump(OBJ* a0, int* a1, bool a2);
     void party_jump(OBJ* a0, bool a1);
     ~ACTION_IDLE();
     ACTION_IDLE();
    };

}  // namespace YS

#endif

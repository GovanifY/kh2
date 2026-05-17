#ifndef KH2_SRC_YASUI_LIBYS_ACTION_CARPET_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_CARPET_HPP

#include "../../common/types.h"

class ACTION_CARPET;
class FVector;
class OBJ;

namespace YS {

    class ACTION_CARPET {
    public:
     void start(OBJ* a0);
     void jump(OBJ* a0, FVector* a1);
     void jump_height(OBJ* a0, f32 a1);
     void party_jump(OBJ* a0, bool a1);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_CARPET();
     ACTION_CARPET();
    };

}  // namespace YS

#endif

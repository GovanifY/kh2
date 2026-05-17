#ifndef KH2_SRC_SUGI_ACTION_DICE_HPP
#define KH2_SRC_SUGI_ACTION_DICE_HPP

#include "../common/types.h"

class ACTION_DICE;
class FVector;
class OBJ;

namespace Ts {

    class ACTION_DICE {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void land(OBJ* a0);
     void jump(OBJ* a0, FVector* a1);
     void jump_height(OBJ* a0, f32 a1);
     void calc_movement(OBJ* a0);
     void party_jump(OBJ* a0, bool a1);
     void SetSpec(f32 a0, f32 a1, f32 a2, f32 a3);
     ~ACTION_DICE();
    };

}  // namespace Ts

#endif

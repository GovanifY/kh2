#ifndef KH2_SRC_YASUI_LIBYS_ACTION_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_HPP

#include "../../common/types.h"

class ACTION;
class FVector;
class ID;
class OBJ;

namespace YS {

    class ACTION {
    public:
     void jump(OBJ* a0, FVector* a1);
     void jump_height(OBJ* a0, f32 a1);
     void calc_movement(OBJ* a0);
     void blow(OBJ* a0);
     u32 Get(ID a0);
     ~ACTION();
    };

}  // namespace YS

#endif

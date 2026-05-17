#pragma once

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


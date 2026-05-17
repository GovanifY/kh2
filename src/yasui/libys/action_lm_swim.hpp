#pragma once

#include "../../common/types.h"

class ACTION_LM_SWIM;
class OBJ;

namespace YS {

    class ACTION_LM_SWIM {
    public:
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_LM_SWIM();
     ACTION_LM_SWIM();
    };

}  // namespace YS


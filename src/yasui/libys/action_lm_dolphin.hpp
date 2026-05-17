#pragma once

#include "../../common/types.h"

class ACTION_LM_DOLPHIN;
class LMPLAYER;
class OBJ;

namespace YS {

    class ACTION_LM_DOLPHIN {
    public:
     void GetNearVector(LMPLAYER* a0);
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_LM_DOLPHIN();
     ACTION_LM_DOLPHIN();
    };

}  // namespace YS


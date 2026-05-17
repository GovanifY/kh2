#pragma once

#include "../../common/types.h"

class ACTION_DUSKJUMP;
class OBJ;

namespace YS {

    class ACTION_DUSKJUMP {
    public:
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     void land(OBJ* a0);
     ~ACTION_DUSKJUMP();
     ACTION_DUSKJUMP();
    };

}  // namespace YS


#pragma once

#include "../../common/types.h"

class ACTION_HOP;
class OBJ;

namespace YS {

    class ACTION_HOP {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_HOP();
     ACTION_HOP();
    };

}  // namespace YS


#pragma once

#include "../../common/types.h"

class ACTION_AIRSLIDE;
class OBJ;

namespace YS {

    class ACTION_AIRSLIDE {
    public:
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_AIRSLIDE();
     ACTION_AIRSLIDE();
    };

}  // namespace YS


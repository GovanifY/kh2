#pragma once

#include "../../common/types.h"

class ACTION_GLIDEHOVER;
class OBJ;

namespace YS {

    class ACTION_GLIDEHOVER {
    public:
     void _control(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_GLIDEHOVER();
     ACTION_GLIDEHOVER();
    };

}  // namespace YS


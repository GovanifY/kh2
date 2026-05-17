#pragma once

#include "../../common/types.h"

class ACTION_FRIEND_FLY_DASH;
class OBJ;

namespace kn {

    class ACTION_FRIEND_FLY_DASH {
    public:
     void end(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_FRIEND_FLY_DASH();
     ACTION_FRIEND_FLY_DASH();
    };

}  // namespace kn


#pragma once

#include "../../common/types.h"

class ACTION_FRIEND_FLY;
class OBJ;

namespace kn {

    class ACTION_FRIEND_FLY {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     ~ACTION_FRIEND_FLY();
     ACTION_FRIEND_FLY();
    };

}  // namespace kn


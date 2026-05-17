#ifndef KH2_SRC_NAKA_LIBKN_ACTION_FRIEND_FLY_HPP
#define KH2_SRC_NAKA_LIBKN_ACTION_FRIEND_FLY_HPP

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

#endif

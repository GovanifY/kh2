#ifndef KH2_SRC_SUGI_ACTION_TT_BALL_BLOW_HPP
#define KH2_SRC_SUGI_ACTION_TT_BALL_BLOW_HPP

#include "../common/types.h"

class ACTION_TT_BALL_BLOW;
class OBJ;

namespace Ts {

    class ACTION_TT_BALL_BLOW {
    public:
     ACTION_TT_BALL_BLOW();
     void start(OBJ* a0);
     void calc_movement(OBJ* a0);
     void land(OBJ* a0);
     ~ACTION_TT_BALL_BLOW();
    };

}  // namespace Ts

#endif

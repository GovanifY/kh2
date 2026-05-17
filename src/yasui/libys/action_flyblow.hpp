#ifndef KH2_SRC_YASUI_LIBYS_ACTION_FLYBLOW_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_FLYBLOW_HPP

#include "../../common/types.h"

class ACTION_FLYBLOW;
class OBJ;

namespace YS {

    class ACTION_FLYBLOW {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void Break(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_FLYBLOW();
     ACTION_FLYBLOW();
    };

}  // namespace YS

#endif

#ifndef KH2_SRC_YASUI_LIBYS_ACTION_FLYJUMP_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_FLYJUMP_HPP

#include "../../common/types.h"

class ACTION_FLYJUMP;
class OBJ;

namespace YS {

    class ACTION_FLYJUMP {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     void land(OBJ* a0);
     ~ACTION_FLYJUMP();
     ACTION_FLYJUMP();
    };

}  // namespace YS

#endif

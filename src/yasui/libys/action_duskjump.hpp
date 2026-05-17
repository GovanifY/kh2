#ifndef KH2_SRC_YASUI_LIBYS_ACTION_DUSKJUMP_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_DUSKJUMP_HPP

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

#endif

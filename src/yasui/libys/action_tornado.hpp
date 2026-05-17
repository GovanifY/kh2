#ifndef KH2_SRC_YASUI_LIBYS_ACTION_TORNADO_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_TORNADO_HPP

#include "../../common/types.h"

class ACTION_TORNADO;
class BTLOBJ;
class OBJ;

namespace YS {

    class ACTION_TORNADO {
    public:
     void SetDir(BTLOBJ* a0);
     void control(OBJ* a0);
     void CalcMovement(BTLOBJ* a0);
     ~ACTION_TORNADO();
     ACTION_TORNADO();
     void calc_movement(OBJ* a0);
    };

}  // namespace YS

#endif

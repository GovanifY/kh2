#ifndef KH2_SRC_YASUI_LIBYS_ACTION_LIGHTCYCLE_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_LIGHTCYCLE_HPP

#include "../../common/types.h"

class ACTION_LIGHTCYCLE;
class OBJ;

namespace YS {

    class ACTION_LIGHTCYCLE {
    public:
     void CheckCrash(OBJ* a0);
     void start(OBJ* a0);
     bool IsRun(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_LIGHTCYCLE();
     ACTION_LIGHTCYCLE();
    };

}  // namespace YS

#endif

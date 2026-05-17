#ifndef KH2_SRC_YASUI_LIBYS_ACTION_BLOW_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_BLOW_HPP

#include "../../common/types.h"

class ACTION_BLOW;
class ID;
class OBJ;

namespace YS {

    class ACTION_BLOW {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void land(OBJ* a0);
     void calc_movement(OBJ* a0);
     s32 GetLandMotion(OBJ* a0);
     void _land(OBJ* a0, ID a1);
     ~ACTION_BLOW();
     ACTION_BLOW();
    };

}  // namespace YS

#endif

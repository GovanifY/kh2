#ifndef KH2_SRC_YASUI_LIBYS_ACTION_FLY_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_FLY_HPP

#include "../../common/types.h"

class ACTION_FLY;
class OBJ;

namespace YS {

    class ACTION_FLY {
    public:
     void calc_movement(OBJ* a0);
     ~ACTION_FLY();
     ACTION_FLY();
    };

}  // namespace YS

#endif

#ifndef KH2_SRC_YASUI_LIBYS_ACTION_HOVER_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_HOVER_HPP

#include "../../common/types.h"

class ACTION_HOVER;
class OBJ;

namespace YS {

    class ACTION_HOVER {
    public:
     void calc_movement(OBJ* a0);
     ~ACTION_HOVER();
     ACTION_HOVER();
    };

}  // namespace YS

#endif

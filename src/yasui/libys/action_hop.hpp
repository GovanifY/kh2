#ifndef KH2_SRC_YASUI_LIBYS_ACTION_HOP_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_HOP_HPP

#include "../../common/types.h"

class ACTION_HOP;
class OBJ;

namespace YS {

    class ACTION_HOP {
    public:
     void start(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_HOP();
     ACTION_HOP();
    };

}  // namespace YS

#endif

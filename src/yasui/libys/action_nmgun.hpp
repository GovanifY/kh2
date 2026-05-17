#ifndef KH2_SRC_YASUI_LIBYS_ACTION_NMGUN_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_NMGUN_HPP

#include "../../common/types.h"

class ACTION_NMGUN;
class OBJ;

namespace YS {

    class ACTION_NMGUN {
    public:
     void control(OBJ* a0);
     ~ACTION_NMGUN();
     ACTION_NMGUN();
     void calc_movement(OBJ* a0);
    };

}  // namespace YS

#endif

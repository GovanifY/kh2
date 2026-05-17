#ifndef KH2_SRC_YASUI_LIBYS_ACTION_AIRSLIDE_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_AIRSLIDE_HPP

#include "../../common/types.h"

class ACTION_AIRSLIDE;
class OBJ;

namespace YS {

    class ACTION_AIRSLIDE {
    public:
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_AIRSLIDE();
     ACTION_AIRSLIDE();
    };

}  // namespace YS

#endif

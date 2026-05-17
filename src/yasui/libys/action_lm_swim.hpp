#ifndef KH2_SRC_YASUI_LIBYS_ACTION_LM_SWIM_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_LM_SWIM_HPP

#include "../../common/types.h"

class ACTION_LM_SWIM;
class OBJ;

namespace YS {

    class ACTION_LM_SWIM {
    public:
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_LM_SWIM();
     ACTION_LM_SWIM();
    };

}  // namespace YS

#endif

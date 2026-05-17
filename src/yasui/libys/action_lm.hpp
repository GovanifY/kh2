#ifndef KH2_SRC_YASUI_LIBYS_ACTION_LM_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_LM_HPP

#include "../../common/types.h"

class ACTION_LM;
class OBJ;

namespace YS {

    class ACTION_LM {
    public:
     u64 control(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_LM();
     ACTION_LM();
    };

}  // namespace YS

#endif

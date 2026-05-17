#ifndef KH2_SRC_YASUI_LIBYS_ACTION_DEADSORA_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_DEADSORA_HPP

#include "../../common/types.h"

class ACTION_DEADSORA;
class OBJ;

namespace YS {

    class ACTION_DEADSORA {
    public:
     void start(OBJ* a0);
     void calc_movement(OBJ* a0);
     ~ACTION_DEADSORA();
     ACTION_DEADSORA();
    };

}  // namespace YS

#endif

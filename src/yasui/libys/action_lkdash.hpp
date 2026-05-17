#ifndef KH2_SRC_YASUI_LIBYS_ACTION_LKDASH_HPP
#define KH2_SRC_YASUI_LIBYS_ACTION_LKDASH_HPP

#include "../../common/types.h"

class ACTION_LKDASH;
class OBJ;

namespace YS {

    class ACTION_LKDASH {
    public:
     void start(OBJ* a0);
     void end(OBJ* a0);
     void fall(OBJ* a0);
     void control(OBJ* a0);
     void calc_movement(OBJ* a0);
     void party_jump(OBJ* a0, bool a1);
     ~ACTION_LKDASH();
     ACTION_LKDASH();
    };

}  // namespace YS

#endif

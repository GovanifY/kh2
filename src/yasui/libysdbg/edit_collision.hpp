#ifndef KH2_SRC_YASUI_LIBYSDBG_EDIT_COLLISION_HPP
#define KH2_SRC_YASUI_LIBYSDBG_EDIT_COLLISION_HPP

#include "../../common/types.h"

class EDIT_COLLISION;

namespace YS {

    class EDIT_COLLISION {
    public:
     void idle_func(void);
     void Init(void);
     void Open(s32 a0);
     ~EDIT_COLLISION();
    };

}  // namespace YS

#endif

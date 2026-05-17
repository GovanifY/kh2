#ifndef KH2_SRC_YASUI_LIBYS_COLLISIONFLAG_HPP
#define KH2_SRC_YASUI_LIBYS_COLLISIONFLAG_HPP

#include "../../common/types.h"

namespace YS {

    class COLLISION_FLAG {
    public:
     void clear(void);
     void enable(s32 a0);
     void disable(s32 a0);
     void reset(s32 a0);
     bool is_enable(s32 a0);
     bool is_disable(s32 a0);
    };

}  // namespace YS

#endif

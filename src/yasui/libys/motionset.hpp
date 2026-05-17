#ifndef KH2_SRC_YASUI_LIBYS_MOTIONSET_HPP
#define KH2_SRC_YASUI_LIBYS_MOTIONSET_HPP

#include "../../common/types.h"

namespace YS {

    class MOTIONSET {
    public:
     u64 is_player(void);
     u64 is_raw(void);
     u32 get_motion(s32 a0);
    };

}  // namespace YS

#endif

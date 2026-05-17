#pragma once

#include "../../common/types.h"

namespace YS {

    class MOTIONSET {
    public:
     u64 is_player(void);
     u64 is_raw(void);
     u32 get_motion(s32 a0);
    };

}  // namespace YS


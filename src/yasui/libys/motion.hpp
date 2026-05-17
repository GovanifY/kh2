#pragma once

#include "../../common/types.h"

namespace YS {

    class MOTION {
    public:
        u32 is_no_motion();
        void sync(MOTION*);
    };

}  // namespace YS


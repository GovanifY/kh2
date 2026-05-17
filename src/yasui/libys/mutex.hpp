#pragma once

#include "../../common/types.h"

namespace YS {

    class MUTEX {
    public:
        void lock(s32);
        u32 is_lock(s32);
    };

}  // namespace YS


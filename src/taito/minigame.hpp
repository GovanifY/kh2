#pragma once

#include "../common/types.h"

namespace Ti {

    class LFlag {
    public:
        LFlag(u32);
        bool check(u32);
        void reset(u32);
        void zero();
    };

}  // namespace Ti


#pragma once

#include "../../common/types.h"

namespace dk {

    class Linear {
    public:
     void start(f32 a0, f32 a1, f32 a2);
     u64 execFixed(void);
     u64 exec(void);
    };

}  // namespace dk


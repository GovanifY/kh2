#pragma once

#include "../../common/types.h"

namespace YS {

    class SAVEFLAG {
    public:
     void Set(u32 a0);
     void Reset(u32 a0);
     bool Check(u32 a0);
    };

}  // namespace YS


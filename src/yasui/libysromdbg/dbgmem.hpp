#pragma once

#include "../../common/types.h"

namespace YS {

    class DBGMEM {
    public:
     void Init(void);
     void Alloc(u32 a0);
     void Free(void* a0);
    };

}  // namespace YS


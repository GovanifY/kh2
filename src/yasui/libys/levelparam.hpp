#pragma once

#include "../../common/types.h"

namespace YS {

    class LEVELPARAM {
    public:
     void Init(void* a0);
     s32 Get(s32 a0);
     void SetCurrent(s32 a0);
     s32 GetCurrent(void);
    };

}  // namespace YS


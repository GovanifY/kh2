#pragma once

#include "../../common/types.h"

namespace YS {

    class DISAREA {
    public:
     void SysInit(void* a0);
     void Disable(s32 a0, s32 a1, s32 a2);
     void Enable(s32 a0);
     void Lost(s32 a0);
     s32 Reset(s32 a0);
     u64 GetStatus(s32 a0, s32 a1);
     u64 GetDisableReason(s32 a0, s32 a1, s32 a2);
    };

}  // namespace YS


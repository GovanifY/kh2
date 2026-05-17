#pragma once

#include "../../common/types.h"

namespace YS {

    class STATUS {
    public:
        static u32 GetMode();
        static u32 IsBattleMode();
        static void SetPrizeRatio(f32);
        static f32 GetLockOnRatio();
        static f32 GetLockOutRange();
    };

}  // namespace YS


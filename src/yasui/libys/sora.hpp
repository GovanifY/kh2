#pragma once

#include "../../common/types.h"

namespace YS {

    class SORA {
    public:
        static u32 Get();
        static u32 GetEntryId(s32);
        void set_skateboard_mode(s32 v);
    };

}  // namespace YS


#pragma once

#include "../../common/types.h"

namespace YS {

struct SORALayout {
    char _pad0[2928];
    s32 skateboard_mode;
};

    class SORA {
    public:
        static u32 Get();
        static u32 GetEntryId(s32);
        void set_skateboard_mode(s32 v);
    };

}  // namespace YS


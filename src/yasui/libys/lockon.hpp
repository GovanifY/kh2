#pragma once

#include "../../common/types.h"

namespace YS {

struct LOCKONLayout {
    s32 mode;
    char _pad_mode[24];
    f32 lock_value;
    char _pad0[8];
    s32 player;
};

    class LOCKON {
    public:
        void auto_lock();
        void reset_player();
    };

}  // namespace YS


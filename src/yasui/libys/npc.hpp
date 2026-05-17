#pragma once

#include "../../common/types.h"

namespace YS {

struct NPCLayout {
    char _pad0[2660];
    u8 rtn_change_dir;
};

    class NPC {
    public:
        u8 is_rtn_change_dir();
    };

}  // namespace YS


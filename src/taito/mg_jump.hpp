#pragma once

#include "../common/types.h"

namespace Ti {

struct MGJumpLayout {
    char _pad0[112];
    s32 configValue;
};

    class MGJump {
    public:
        s32 config();
    };

}  // namespace Ti

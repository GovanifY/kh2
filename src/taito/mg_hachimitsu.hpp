#pragma once

#include "../common/types.h"

namespace Ti {

struct MGHachimitsuLayout {
    char _pad0[476];
    s32 gopher;
};

    class MGHachimitsu {
    public:
        s32 get_gopher();
    };

}  // namespace Ti

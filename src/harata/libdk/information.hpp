#pragma once

#include "../../common/types.h"

namespace dk {

struct INFORMATION_WINDOW_Layout {
    char _pad0[456];
    s32 message;
};

    class INFORMATION_WINDOW {
    public:
        void close();
        s32 getMessage();
    };

}  // namespace dk

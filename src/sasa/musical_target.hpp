#pragma once

#include "../common/types.h"

namespace sa {

    class MUSICAL_TARGET {
    public:
        static void* getImage();
        static u32 init();
        static void free();
    };

}  // namespace sa


#pragma once

#include "../common/types.h"

namespace Ti {

struct MGOarashiLayout {
    char _pad0[100];
    s32 configValue;
};

    class MGOarashi {
    public:
        s32 config();
    };

}  // namespace Ti

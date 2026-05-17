#pragma once

#include "../common/types.h"

namespace Ti {

struct AfpLayout {
    char _pad0[12];
    s32 count;
};

    class Afp {
    public:
        s32 getCount(void* p);
    };

}  // namespace Ti

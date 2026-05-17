#pragma once

#include "../common/types.h"

namespace Tz {

struct LayoutLayout {
    char _pad0[140];
    s32 num;
    s32 nextNum;
};

class Layout {
public:
    s32 getNum();
    s32 getNextNum();
};

}  // namespace Tz


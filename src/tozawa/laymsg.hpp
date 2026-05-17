#pragma once

#include "../common/types.h"

namespace Tz {
struct LayMsgLayout {
    char _pad0[28];
    s32 sequence;
};


class LayMsg {
public:
    s32 getSequence();
};

}  // namespace Tz


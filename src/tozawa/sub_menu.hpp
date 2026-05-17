#pragma once

#include "../common/types.h"

namespace Tz {

class SubMenu {
public:
    static u32 Exit(s32);
    static u32 GetCallSignal();
    static void SetLeadData(const char*);
};

}  // namespace Tz


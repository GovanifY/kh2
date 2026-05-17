#pragma once

#include "../common/types.h"

namespace Tz {

class JmNewInfo {
public:
    static void Exit();
    static u32 GetSram();
    static void CheckAll();
};

}  // namespace Tz


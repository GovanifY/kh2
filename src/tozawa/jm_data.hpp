#pragma once

#include "../common/types.h"

namespace Tz {

class JMData {
public:
    static u32 Clear(s32);
    static u32 Destroy(s32);
    static void LoadObjRequest(s32, bool);
    static u32 CacheAlloc(s32, const char*);
};

}  // namespace Tz

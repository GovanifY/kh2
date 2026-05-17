#pragma once

#include "../common/types.h"
#include "../common/task.hpp"


namespace Tz {

class LoadData {
public:
    static void Request(const char*, s32, bool);
    static void FlushTask(TASK*);
    static void Clear(s32);
    static void* CacheAlloc(const char*);
};

}  // namespace Tz


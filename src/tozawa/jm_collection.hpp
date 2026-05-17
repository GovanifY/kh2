#pragma once

#include "../common/types.h"

namespace Tz {

class Select;

class JmCollection {
public:
    static void FileAlloc();
    static u32 DrawUpdate(Select*, s32, s32);
};

}  // namespace Tz


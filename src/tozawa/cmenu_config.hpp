#pragma once

#include "../common/types.h"

namespace Tz {

class Select;

class CmConfig {
public:
    static void DrawUpdate(Select*, s32, s32);
    static u32 GetSelSeq(s32, s32);
};

}  // namespace Tz


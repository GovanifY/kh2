#pragma once

#include "./types.h"

namespace SAVERAM {

struct Layout {
    char _pad0[9368];
    s32 gameLevel;
};

s32 GetGameLevel(void* self);

}  // namespace SAVERAM

#pragma once

#include "../../common/types.h"

namespace dk {

class Tim2 {
public:
    u32 getWidthHeight(void* a0, int* a1, int* a2, uint* a3, uint* a4, int* a5, int* a6);
    u64 loadImage(void* a0, s32 a1, s32 a2);
    u64 check4bit(void* a0);
};

}  // namespace dk


#pragma once

#include "../../common/types.h"

class BGMSET;

namespace YS {

    class BGMSET {
    public:
     void SetCurrent(BGMSET* a0);
     void Change(s32 a0, s32 a1);
    };

}  // namespace YS


#pragma once

#include "../../common/types.h"

class SHEET;

namespace YS {

    class BONUSLEVEL {
    public:
     void up(SHEET* a0);
     void Init(void* a0);
     bool IsUp(s32 a0);
     s32 Up(s32 a0);
    };

}  // namespace YS


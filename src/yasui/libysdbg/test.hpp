#pragma once

#include "../../common/types.h"

struct TASK;

namespace YS {

    class TEST {
    public:
     void Init(void);
     void Test(s32 a0);
     void Thread(TASK* a0);
    };

}  // namespace YS


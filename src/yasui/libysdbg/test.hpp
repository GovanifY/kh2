#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace YS {

    class TEST {
    public:
     void Init(void);
     void Test(s32 a0);
     void Thread(TASK* a0);
    };

}  // namespace YS


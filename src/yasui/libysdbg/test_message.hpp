#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace YS {

    class TEST_MESSAGE {
    public:
     void Open(s32 a0);
     void ExecThread(TASK* a0);
     void Init(void);
    };

}  // namespace YS


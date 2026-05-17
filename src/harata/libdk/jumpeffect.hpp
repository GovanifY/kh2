#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

    class JumpEffect {
    public:
     void outInit(void);
     void inInit(void);
     void outFinal(void);
     void inFinal(void);
     void outInit_task(TASK* a0);
     s32 in(void);
     u8 outIsExist(void);
     void init(void);
     void outClear(void);
    };

}  // namespace dk


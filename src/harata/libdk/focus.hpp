#pragma once

#include "../../common/types.h"

struct TASK;

namespace dk {

    class Focus {
    public:
     void end(void);
     void Task(TASK* a0);
     void start(s32 a0, bool a1);
     void update(void);
    };

}  // namespace dk


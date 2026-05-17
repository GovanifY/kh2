#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace YS {

    class BLUR {
    public:
     void stop(void);
     void exec(void);
     void Exec(TASK* a0);
     void init(void);
     void start(f32 a0);
     void fadeout(f32 a0);
     void Init(void);
    };

}  // namespace YS


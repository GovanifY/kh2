#pragma once

#include "../common/types.h"

struct TASK;

namespace Ts {

    class SKATEBOARDSCORE {
    public:
     void add_count(s32 a0, f32 a1);
     void stop(void);
     void ExecTask(TASK* a0);
     void ExecFinalize(TASK* a0);
    };

}  // namespace Ts


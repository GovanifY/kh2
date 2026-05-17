#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

    class Vsync {
    public:
     void setGameSpeed(f32 a0);
     void gameSpeedTask(TASK* a0);
     void vsyncWait(void);
     void vsync_task(TASK* a0);
     u64 vSyncCallback(s32 a0);
     void initGameSpeed(void);
     s32 setLimit(s32 a0);
     void setFrameType(bool a0);
     void clear(void);
     void init(void);
     void setGameSpeed(f32 a0, f32 a1, f32 a2);
     double getFuncFrameTime(void);
    };

}  // namespace dk


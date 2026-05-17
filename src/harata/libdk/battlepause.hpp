#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

    class BattlePause {
    public:
     void init(void);
     void pause_thread(TASK* a0);
    };

}  // namespace dk


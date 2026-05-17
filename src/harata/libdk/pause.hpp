#pragma once

#include "../../common/types.h"

struct TASK;

namespace dk {

class Pause {
public:
 void disable(s32 a0);
 void enable(s32 a0);
 u64 isDisable(void);
 void init(void);
 void pause_thread(TASK* a0);
};

} // namespace dk


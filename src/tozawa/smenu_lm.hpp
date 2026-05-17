#pragma once

#include "../common/types.h"
#include "../common/task.hpp"


namespace Tz {

class LMMU {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


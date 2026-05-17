#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class HEFT {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


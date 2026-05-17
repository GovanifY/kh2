#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class HECO {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


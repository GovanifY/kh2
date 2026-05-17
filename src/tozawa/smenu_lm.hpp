#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class LMMU {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


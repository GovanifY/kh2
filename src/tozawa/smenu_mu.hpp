#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class MUMI {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


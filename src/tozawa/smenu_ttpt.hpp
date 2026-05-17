#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class TTPT {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


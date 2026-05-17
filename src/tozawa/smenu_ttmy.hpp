#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class TTMY {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class TRTE {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class HBTE {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


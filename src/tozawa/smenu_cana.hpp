#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class CANA {
public:
    static void PauseThread(TASK*);
};

}  // namespace Tz


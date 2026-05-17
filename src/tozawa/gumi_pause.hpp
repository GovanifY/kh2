#pragma once

#include "../common/types.h"

struct TASK;

namespace Tz {

class GumiPause {
public:
    static void PauseThread(TASK*);
    static void SetupTop();
    static void UpdateAdvice();
    static void ChkLoadRequest();
};

}  // namespace Tz


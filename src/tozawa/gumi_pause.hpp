#ifndef KH2_SRC_TOZAWA_GUMI_PAUSE_HPP
#define KH2_SRC_TOZAWA_GUMI_PAUSE_HPP

#include "types.h"

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

#endif

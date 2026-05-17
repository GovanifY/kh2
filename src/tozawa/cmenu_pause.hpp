#ifndef KH2_SRC_TOZAWA_CMENU_PAUSE_HPP
#define KH2_SRC_TOZAWA_CMENU_PAUSE_HPP

#include "types.h"

namespace Tz {

class Pause {
public:
    static bool isPause();
    static u32 isExistFade();
    static u32 isLoopFade();
    static void SetNextMenu(s32);
    static void StartFade(void (*)());
    static void EndFade(void (*)());
    static void CreateFadeObject(...);
};

}  // namespace Tz

#endif

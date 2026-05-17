#pragma once

#include "../common/types.h"

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


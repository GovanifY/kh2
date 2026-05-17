#pragma once

#include "../common/types.h"

namespace Tz {

class MenuSound {
public:
    static u32 PlaySE(s32, bool);
    static void PlayBgSE(s32);
    static u32 isBeep(s32);
    static u32 ResetPause();
    static void StopBgSE(u32);
    static void PlaySEDirect(s32);
    static void AllStop();
    static u32 GetBgSeHandle();
    static u32 isBgSePlaying(...);
    static void StopBgSeHandle(...);
    static u32 GetSeId(s32);
    static u32 ResetVoiceState();
    static u32 ResetPauseImpl();
    static u32 isPauseActive();
};

}  // namespace Tz


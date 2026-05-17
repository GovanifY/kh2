#include "menu_sound.hpp"

extern void SOUND_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
extern void SOUND_seVoicePcmStop(void) asm("_ZN5SOUND14seVoicePcmStopEv");
extern u32 D_0035ecd4 asm("D_0035ecd4");

namespace Tz {
u32 MenuSound::PlaySE(s32 se, bool play) {
    u32 s0 = (u32)play & 0xFFu;
    u32 s1 = GetSeId(se);
    if (s0 != 0u) {
        SOUND_systemSePlay((s32)s1, 0);
    }
    return s1;
}
void MenuSound::PlayBgSE(s32) { D_0035ecd4 = GetBgSeHandle(); }
u32 MenuSound::isBeep(s32 which) {
    u32 r15 = (u32)(0x0036u << 16);
    u32 r16 = (u32)which;
    u32 r4 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(-4912)));
    u32 r2 = GetSeId(r4);
    r16 = (u32)(r16 ^ r2);
    r16 = ((u32)r16 < 0x00000001u);
    return r16;
}
u32 MenuSound::ResetPause() {
    u32 r2 = isPauseActive();
    if (r2 != 0u) {
        r2 = ResetPauseImpl();
    }
    return ResetVoiceState();
}
void MenuSound::StopBgSE(u32 which) {
    u32 s16 = which;
    u32 v0;
    if (s16 == 0) {
        s16 = D_0035ecd4;
        if (s16 == 0) {
            goto clear;
        }
    }
    v0 = isBgSePlaying(s16);
    if (v0 != 0) {
        StopBgSeHandle(s16, 0);
    }
clear:
    D_0035ecd4 = 0;
}
void MenuSound::PlaySEDirect(s32 se) { SOUND_systemSePlay(se, 0); }
void MenuSound::AllStop() { SOUND_seVoicePcmStop(); }
}  // namespace Tz

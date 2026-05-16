#include "types.h"

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
};
}  // namespace Tz

extern void SOUND_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
extern void SOUND_seVoicePcmStop(void) asm("_ZN5SOUND14seVoicePcmStopEv");
extern "C" u32 func_002bc1e8(void);
extern "C" u32 func_002bc420(...);
extern "C" void func_002bc358(...);
extern "C" u32 func_00242708(...);
extern "C" u32 func_002ba9c0(...);
extern "C" u32 func_002bd6d0(...);
extern "C" u32 func_002ef7b8(...);
extern u32 D_0035ecd4 asm("D_0035ecd4");

namespace Tz {
u32 MenuSound::PlaySE(s32 se, bool play) {
    u32 s0 = (u32)play & 0xFFu;
    u32 s1 = func_00242708(se);
    if (s0 != 0u) {
        SOUND_systemSePlay((s32)s1, 0);
    }
    return s1;
}
void MenuSound::PlayBgSE(s32) { D_0035ecd4 = func_002bc1e8(); }
u32 MenuSound::isBeep(s32 which) {
    u32 r15 = (u32)(0x0036u << 16);
    u32 r16 = (u32)which;
    u32 r4 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(-4912)));
    u32 r2 = func_00242708(r4);
    r16 = (u32)(r16 ^ r2);
    r16 = ((u32)r16 < 0x00000001u);
    return r16;
}
u32 MenuSound::ResetPause() {
    u32 r2 = ((u32(*)())func_002ef7b8)();
    if (r2 != 0u) {
        r2 = ((u32(*)())func_002bd6d0)();
    }
    return ((u32(*)())func_002ba9c0)();
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
    v0 = func_002bc420(s16);
    if (v0 != 0) {
        func_002bc358(s16, 0);
    }
clear:
    D_0035ecd4 = 0;
}
void MenuSound::PlaySEDirect(s32 se) { SOUND_systemSePlay(se, 0); }
void MenuSound::AllStop() { SOUND_seVoicePcmStop(); }
}  // namespace Tz

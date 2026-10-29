#include "../common/types.h"

// Agent R46p_39 (2026-10-29): FUN_001bbf40 (64 bytes, SLPM_666.75).
// If YS::MISSION::IsExec() is non-zero, reads the pointer at +8 of YS::MISSION::GetCurrent()
// and returns bit 1 of the halfword at +4 of that pointer's target. Otherwise returns 0.
extern "C" u32 _ZN2YS7MISSION6IsExecEv(void);
extern "C" u8* _ZN2YS7MISSION10GetCurrentEv(void);

s32 func_001bbf40(void) {
    s32 r = 0;
    if (_ZN2YS7MISSION6IsExecEv() != 0) {
        u8* v = _ZN2YS7MISSION10GetCurrentEv();
        u8* p = *(u8**)(v + 8);
        u32 h = *(u16*)(p + 4);
        r = (s32)((h >> 1) & 1);
    }
    return r;
}

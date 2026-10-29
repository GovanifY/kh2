#include "../common/types.h"

// FUN_001bbf00 (64 bytes).
// Code: same as FUN_001bbec0 but returns bit 12 of the u16 at (*(GetCurrent() + 8)) + 4.
extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern u32 YS_MISSION_GetCurrent(void) asm("_ZN2YS7MISSION10GetCurrentEv");

u32 func_001bbf00(void) {
    u32 r = 0;
    if (YS_MISSION_IsExec() != 0) {
        u32 p = YS_MISSION_GetCurrent();
        u32 q = *(u32 *)(p + 8);
        u32 v = *(u16 *)(q + 4);
        r = (v >> 12) & 1;
    }
    return r;
}

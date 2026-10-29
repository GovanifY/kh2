#include "../common/types.h"

// FUN_001bb9f0 (64 bytes).
// Code: returns 0 if YS::MISSION::IsExec (mangled, 0x1bb4a0) returns 0. Otherwise returns bit 9 of the
// u16 at (*(*D_01d49320 + 8) + 4).
extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern u32 D_01d49320;

u32 func_001bb9f0(void) {
    if (YS_MISSION_IsExec() == 0) {
        return 0;
    }
    u32 *p = (u32 *)D_01d49320;
    u32 *q = (u32 *)p[2];
    u32 v = *(u16 *)((u8 *)q + 4);
    return (v >> 9) & 1;
}

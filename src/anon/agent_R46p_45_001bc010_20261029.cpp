#include "../common/types.h"

// Agent R46p_45 (2026-10-29): FUN_001bc010 (64 bytes, SLPM_666.75).

extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern u8* YS_MISSION_GetCurrent(void) asm("_ZN2YS7MISSION10GetCurrentEv");

// FUN_001bc010: returns 0 if YS::MISSION::IsExec is zero. Otherwise takes GetCurrent()->+8 (a pointer),
// and returns bit 13 of the u16 at +4 of that pointer.
u32 func_001bc010(void) {
    u32 r = 0;
    if (YS_MISSION_IsExec() != 0) {
        u8* obj = YS_MISSION_GetCurrent();
        u8* q = *(u8**)(obj + 8);
        u32 v = *(u16*)(q + 4);
        r = (v >> 13) & 1;
    }
    return r;
}

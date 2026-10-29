#include "../common/types.h"

// Agent R46p_45 (2026-10-29): FUN_001bbfd0 (60 bytes, SLPM_666.75).

extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern u8* YS_MISSION_GetCurrent(void) asm("_ZN2YS7MISSION10GetCurrentEv");

// FUN_001bbfd0: returns a float. If YS::MISSION::IsExec is nonzero, return the float at
// GetCurrent()+1328; otherwise return the float at 0x0036dc44.
f32 func_001bbfd0(void) {
    if (YS_MISSION_IsExec() != 0) {
        u8* obj = YS_MISSION_GetCurrent();
        return *(f32*)(obj + 1328);
    }
    u32 p = 0x00370000;
    asm volatile("" : "+r"(p));
    asm("addiu %0,%0,-9148" : "+r"(p));
    return *(f32*)p;
}

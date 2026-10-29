#include "../common/types.h"

// Agent R46p_94 (2026-10-29): FUN_00244938 (80 bytes, SLPM_666.75).
// Calls YS::MENUFLAG::Check(int). Result is 1 by default, or the Check result when a0 != 0.
// When a0 == 0, calls Check(1) and, if that is non-zero, calls Check(118).
extern "C" s32 r_menuflag_check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");

s32 func_00244938(s32 a0) {
    s32 s0 = 1;
    if (a0 == 0) {
        if (r_menuflag_check(1) != 0) {
            s0 = r_menuflag_check(118);
        }
    } else {
        s0 = r_menuflag_check(1);
    }
    return s0;
}

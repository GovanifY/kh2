#include "../common/types.h"

// Agent R46p_52 (2026-10-29): FUN_001c9df8 (84 bytes), SLPM_666.75.
// Code: frame of 16 bytes (s0, ra). Loop: v = YS::FRIEND::Get(s0), s0 += 1 (the addiu sits after the
// jal return); if v != 0 and YS::OBJ::is_leave(v) != 0 the function returns 1. Otherwise it loops while
// s0 < 2 (signed slti) and returns 0 at the end.
// The two callees have mangled-name rows; they are declared extern "C" with asm labels.
extern "C" u32 r_FRIEND_Get(s32 i) asm("_ZN2YS6FRIEND3GetEi");
extern "C" s32 r_OBJ_is_leave(u32 self) asm("_ZN2YS3OBJ8is_leaveEv");

s32 r_FUN_001c9df8(void) asm("func_001c9df8");

s32 r_FUN_001c9df8(void) {
    s32 s0 = 0;
    for (;;) {
        u32 v = r_FRIEND_Get(s0);
        s0 = s0 + 1;
        if (v != 0) {
            if (r_OBJ_is_leave(v) != 0) {
                return 1;
            }
        }
        if (!(s0 < 2)) {
            return 0;
        }
    }
}

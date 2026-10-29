#include "../common/types.h"

// Agent R46p_80 (2026-10-29): FUN_002072a8 (96 bytes), SLPM_666.75.
// Byte s = a0 & 0xff. Calls the VU0 random-float helper func_00207260 (result discarded), takes
// x = (float)(2*s), halves s, multiplies x by a second helper result, subtracts (float)s, and
// returns the truncated x as a sign-extended byte.
extern "C" f32 func_00207260(void);

s32 func_002072a8(u32 a0) {
    u32 s = a0 & 0xff;
    func_00207260();
    f32 x = (f32)(s32)(s * 2);
    s = s >> 1;
    x = x * func_00207260();
    x = x - (f32)(s32)s;
    return (s8)(s32)x;
}

#include "../common/types.h"

extern "C" u32 func_002bc0f0(u32);

// FUN_002bc158 (48 bytes)
// Code: if a0 == 0 or a0 < 0 return 0; otherwise tail-call func_002bc0f0(a0).
// Guess: forward a positive count to a helper, zero otherwise.
u32 func_002bc158(s32 a0) {
    if (a0 == 0) {
        return 0;
    }
    if (a0 < 0) {
        return 0;
    }
    return func_002bc0f0((u32)a0);
}

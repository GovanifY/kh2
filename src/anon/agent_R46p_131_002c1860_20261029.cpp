#include "../common/types.h"

// FUN_002c1860 (108 bytes), SLPM_666.75. Calls func_002c7060(arg1 + 2928). If the float at +84 of that
// sub-object is greater than 0.0, returns. Otherwise tail-calls func_0016bd60(arg1, 47).
// Guess: a per-frame check on a sub-object's timer, which changes the object's action when it runs out.
extern "C" void func_002c7060(u32 p);
extern "C" void func_0016bd60(u32 a0, u32 a1);

void func_002c1860(u32 a0, u32 a1) {
    u32 sub = a1 + 2928u;
    func_002c7060(sub);
    float f = *(float *)(sub + 84);
    u32 flag = (0.0f < f) ? 1u : 0u;
    if ((flag & 0xffu) != 0) return;
    func_0016bd60(a1, 47);
}

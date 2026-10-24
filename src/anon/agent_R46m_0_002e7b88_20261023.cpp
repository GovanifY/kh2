#include "../common/types.h"

// FUN_002e7b88 (36 bytes)
// Loads the floats at +0, +4, +8 and +12 of arg0 and tail-calls FUN_002eac70 with them.
extern "C" void func_002eac70(float f12, float f13, float f14, float f15);

void func_002e7b88(float* a0) {
    func_002eac70(a0[0], a0[1], a0[2], a0[3]);
}

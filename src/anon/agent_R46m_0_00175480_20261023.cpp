#include "../common/types.h"

// FUN_00175480 (36 bytes)
// Loads the word at +0 and floats at +4 and +8 of arg0 and tail-calls FUN_00153e28 with them.
extern "C" void func_00153e28(u32 a0, float f12, float f13);

void func_00175480(u32* a0) {
    func_00153e28(a0[0], *(float*)&a0[1], *(float*)&a0[2]);
}

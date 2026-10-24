#include "../common/types.h"

// Agent R46j_2 (2026-10-23): FUN_00171150 (44 bytes), SLPM_666.75.
// Reads the word at 0(a0), the word at 4(a0) and the float at 8(a0), then tail-calls
// func_0017f488(word0 + 320, word1, float, 0.0f).
extern "C" void func_0017f488(int a0, int a1, float f12, float f13);
extern "C" void func_00171150(u32* p);

void func_00171150(u32* p) {
    f32* fp = (f32*)p;
    func_0017f488((int)(p[0] + 320), (int)p[1], fp[2], 0.0f);
}

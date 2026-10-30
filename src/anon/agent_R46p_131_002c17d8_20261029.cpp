#include "../common/types.h"

// FUN_002c17d8 (108 bytes), SLPM_666.75. Sets bit 1 of the word at +264, zeroes the 16-byte vector at +32
// (VU0 vsub + sqc2), calls func_0017f488(obj+320, 161, 0.0f, 0.0f), then tail-calls
// func_0017f5e0(obj+320, 0, 0, 0.0f, 0.0f) (YS::MOTION::push).
// Guess: the reset step of a motion-holder object, followed by a push of a default motion.
extern "C" void func_0017f488(u32 p, u32 v, float f12, float f13);
extern "C" void func_0017f5e0(u32 p, u32 a1, u32 a2, float f12, float f13);

void func_002c17d8(u32 a0, u32 a1) {
    *(u32 *)(a1 + 264) |= 2;
    __asm__ volatile(
        "vsub.wxyz $vf1,$vf0,$vf0\n\t"
        "sqc2 $vf1,0(%0)"
        : : "r"(a1 + 32) : "memory");
    func_0017f488(a1 + 320, 161, 0.0f, 0.0f);
    func_0017f5e0(a1 + 320, 0, 0, 0.0f, 0.0f);
}

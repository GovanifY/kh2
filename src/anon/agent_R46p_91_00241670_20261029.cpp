#include "../common/types.h"

// FUN_00241670 (84 bytes): s0 = a0; calls 0x242408 (result discarded), s0 = 0x242418(s0, 0x8a58),
// calls 0x242408 again (void), then 0x242418(word at 0x35EC90, 0x8a58); returns (s0 ^ v) == 0.
// The first 0x242408 call result is discarded; s0 comes from the 0x242418 result.
// Callees 0x242408 and 0x242418 have func_ rows.
extern "C" void func_00242408(void);
extern "C" u32 func_00242418(u32 a0, u32 a1);

u32 func_00241670(u32 a0) {
    u32 s0 = a0;
    func_00242408();
    s0 = func_00242418(s0, 0x8a58);
    func_00242408();
    u32 base = 0x00360000;
    asm volatile("" : "+r"(base));
    u32 a1 = 0x8a58;
    asm volatile("" : "+r"(a1));
    u32 v = func_00242418(*(u32 *)(base - 4976), a1);
    s0 ^= v;
    return s0 == 0;
}

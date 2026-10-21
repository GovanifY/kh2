#include "../common/types.h"

// Agent S34 (2026-10-21): FUN_0014e140, FUN_0014f068. FUN_0014dca8 is already registered by
// agent_s33_20261021.cpp, so it is not defined here (candidate kept in the scratchpad).
// Object flags (Makefile): -falign-functions=1 (the 84- and 68-byte bodies do not end on an
// 8-byte boundary, so the default alignment would pad them) and -fno-guess-branch-probability
// (keeps the shared bc1f join in FUN_0014f068).

// Callees. The registry aliases resolve these names to the linker symbols.
extern "C" void func_001666f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern "C" u32 func_0014e648(u32 a0);
extern "C" u32 func_0014dd60(u32 a0, u32 a1, u32 a2, u32 a3);

// Global data at D_00349F00 (= D_00350000 - 24832), passed to FUN_0014e648 in FUN_0014e140.
extern u8 D_00349f00[];

// FUN_0014e140 (84 bytes)
// Code: r = FUN_0014e648(&D_00349F00), then tail-calls FUN_0014dd60(r, a0&0xff, a1&0xff, a2&0xff).
// Matching: the u8 parameter types give the andi masks, and the callee result becomes the first
//       argument of the tail call. The object needs -falign-functions=1 (see the header).
u32 func_0014e140(u8 a0, u8 a1, u8 a2) {
    u32 r = func_0014e648((u32)D_00349f00);
    return func_0014dd60(r, a0, a1, a2);
}

// FUN_0014f068 (68 bytes)
// Code: x1 = p[1]. If 0.0 <= x1 then the test is x2 <= x0, else x0 <= x2, where x0 = p[0] and
//       x2 = p[2]. If the test holds, p[0] = x2 and the result is 0. Otherwise the result is 1.
// Matching: x0 is pinned to $f0 and x2 to $f1. The zero constant and x1 share $f0/$f1 as in the
//       original, and the arms load p[2] separately. The -fno-guess-branch-probability flag makes
//       the two arms share one bc1f before the store.
u32 func_0014f068(float* p) {
    register float x1 asm("$f1") = p[1];
    float z = 0.0f;
    register float x0 asm("$f0");
    register float x2 asm("$f1");
    if ((z <= x1) ? ((x2 = p[2]) <= (x0 = p[0])) : ((x0 = p[0]) <= (x2 = p[2]))) {
        p[0] = x2;
        return 0;
    }
    return 1;
}

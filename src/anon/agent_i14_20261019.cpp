#include "../common/types.h"

// Three return-zero stubs. Each one builds a frame pointer (s8), stores the
// argument registers (where it takes them), and returns 0 through t7. The
// original was compiled at -O0, so this file is built with -O0 via a
// target-specific CXXFLAGS line in the Makefile (same as agent_m_o0).

// FUN_002b6ab8 (36 bytes): no arguments. Frame of 16 bytes (s8 save only).
// Returns 0 through t7 (move t7,zero; move v0,t7).
u32 func_002b6ab8() {
    return 0;
}

// FUN_002b740c (52 bytes): four argument registers a0..a3 are spilled to the
// s8 frame (sw a0..a3), then returns 0. Frame of 32 bytes.
u32 func_002b740c(u32 a0, u32 a1, u32 a2, u32 a3) {
    return 0;
}

// FUN_002b81b8 (52 bytes): same shape as func_002b740c (four argument spills,
// frame of 32, return 0 through t7). Kept as its own function because it is a
// separate address in the layout.
u32 func_002b81b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return 0;
}

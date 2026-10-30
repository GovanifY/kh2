#include "../common/types.h"

extern "C" u32 func_002b6708(u32, u32, u32, u32, u32, u32, u32, u32);

// FUN_002b7010 (104 bytes)
// Code: return func_002b6708(7, 15, a0, a1, a2, a3, t0, t1);
// Built with -O0 via the per-object CXXFLAGS line in the Makefile.
u32 func_002b7010(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    return func_002b6708(7, 15, a0, a1, a2, a3, a4, a5);
}

#include "../common/types.h"

extern "C" u32 func_002b6708(u32, u32, u32);

// FUN_002b6c04 (64 bytes)
// Code: return func_002b6708(2, 10, a0);
// Same shape as FUN_002b7efc (a thin -O0 wrapper). Built with -O0 via the
// per-object CXXFLAGS line in the Makefile.
u32 func_002b6c04(u32 a0) {
    return func_002b6708(2, 10, a0);
}

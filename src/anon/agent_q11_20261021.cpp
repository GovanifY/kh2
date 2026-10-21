#include "../common/types.h"

// Callees. Calls with no argument setup match the original, which sets no
// argument registers before them.
extern "C" void func_00168388(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 func_00170cd0(void);
extern "C" void func_00102448(u32 a0, u32 a1);

// FUN_001367e0 (96 bytes)
// Code: calls func_00168388(a1, a2, 0, 0). Then loops: while func_00170cd0()
// returns non-zero, calls func_00102448(a0, 0). a0 is kept in s0 across the calls.
// The original keeps a0 in s0 and reloads it into a0 before each test (move a0,s0
// in the delay path), which the plain loop reproduces.
void func_001367e0(u32 a0, u32 a1, u32 a2) {
    func_00168388(a1, a2, 0, 0);
    while (func_00170cd0() != 0) {
        func_00102448(a0, 0);
    }
}

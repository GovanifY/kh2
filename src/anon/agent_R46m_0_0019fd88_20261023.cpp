#include "../common/types.h"

// FUN_0019fd88 (36 bytes)
// Virtual call: vtable slot +36 of arg0, called with arg1 passed through and a2 = 0.
void func_0019fd88(u32* a0, u32 a1) {
    u32* vt = (u32*)a0[0];
    ((void (*)(u32*, u32, u32))vt[9])(a0, a1, 0);
}

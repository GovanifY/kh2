#include "../common/types.h"

// FUN_00322968 (36 bytes)
// Virtual call: loads the vtable pointer at arg0, calls slot +20 with arg0 as the only argument.
void func_00322968(u32* a0) {
    u32* vt = (u32*)a0[0];
    ((void (*)(u32*))vt[5])(a0);
}

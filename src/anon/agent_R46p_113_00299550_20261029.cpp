#include "../common/types.h"

// FUN_00299550 (80 bytes)
// Same shape as func_00295810: clears the byte globals at 0x0035f5a8 and 0x0035f5a9, then if the
// pointer at 0x0035f5a4 is non-null, calls its vtable slot 1 with the pointer, and clears the pointer.
extern u8 D_0035f5a8;
extern u8 D_0035f5a9;
extern u32 D_0035f5a4;

void func_00299550(void) {
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    u32 p = D_0035f5a4;
    if (p != 0) {
        ((void (*)(u32))((u32 *)*(u32 *)p)[1])(p);
        D_0035f5a4 = 0;
    }
}

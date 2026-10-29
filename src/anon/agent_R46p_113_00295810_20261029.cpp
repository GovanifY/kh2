#include "../common/types.h"

// FUN_00295810 (80 bytes)
// Clears two byte globals at 0x0035f590 and 0x0035f591, then if the pointer at 0x0035f58c is
// non-null, calls its vtable slot 1 with the pointer as the argument, and clears the pointer.
extern u8 D_0035f590;
extern u8 D_0035f591;
extern u32 D_0035f58c;

void func_00295810(void) {
    D_0035f590 = 0;
    D_0035f591 = 0;
    u32 p = D_0035f58c;
    if (p != 0) {
        ((void (*)(u32))((u32 *)*(u32 *)p)[1])(p);
        D_0035f58c = 0;
    }
}

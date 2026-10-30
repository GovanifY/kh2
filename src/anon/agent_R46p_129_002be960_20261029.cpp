#include "../common/types.h"

// FUN_002be960 (80 bytes): s = FUN_002be908(s) in a loop; while s is non-zero, call the
// object's vtable slot 32 with s as this. Returns 0. The while form gives the original
// bnez to an out-of-line call block.
extern "C" u32 func_002be908(u32);

typedef void (*vfn_t)(u32);

u32 func_002be960(void) {
    u32 s = 0;
    while ((s = func_002be908(s)) != 0) {
        ((vfn_t)((u32*)*(u32*)s)[32])(s);
    }
    return s;
}

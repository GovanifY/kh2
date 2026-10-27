#include "../common/types.h"

extern u8 D_00377b68[];

// FUN_002ffbe0 (36 bytes): table byte at D_00377b68[a0]; if bit 1 is set, returns a0-32, else a0.
u32 func_002ffbe0(u32 a0) {
    u32 r = a0;
    if (D_00377b68[a0] & 2) {
        r = a0 - 32;
    }
    return r;
}

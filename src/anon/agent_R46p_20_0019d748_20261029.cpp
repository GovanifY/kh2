#include "../common/types.h"

// FUN_0019d748 (72 bytes): if FUN_00181858(a0) returns nonzero, returns bit 0 of the word at +32
// of a0 as 0 or 1 (sltu of zero against the masked bit); otherwise returns 0.
extern "C" u32 func_00181858(u32);

u32 func_0019d748(u32 a0) {
    u32 r = 0;
    if (func_00181858(a0)) {
        u32 t = *(u32*)(a0 + 32) & 1;
        asm volatile("" : "+r"(t));
        r = 0u < t;
    }
    return r;
}

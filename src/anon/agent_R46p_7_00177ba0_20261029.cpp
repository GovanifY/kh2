#include "../common/types.h"

extern "C" u8* func_00177860(u8* a0);

// FUN_00177ba0 (84 bytes): s0 = byte at +2820 (read before the first call); calls FUN_00177860(obj)
// and compares s0 with the signed byte at +44 of the result. Less: returns the byte at +2820;
// otherwise calls FUN_00177860 again and returns the signed byte at +44 of that result.
s32 func_00177ba0(u8* a0) {
    u32 s0 = a0[2820];
    s32 t = (s8)func_00177860(a0)[44];
    if ((s32)s0 < t) {
        return a0[2820];
    }
    return (s8)func_00177860(a0)[44];
}

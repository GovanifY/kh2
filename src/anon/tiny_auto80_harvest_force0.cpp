#include "types.h"

u32 func_00244938(u32, u32, u32, u32);


u32 func_00244ee8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r2 = r4;
    if (r4 == 0u) {
    u32 (*fp_call0_00244938)() = (u32(*)())func_00244938;
        r2 = fp_call0_00244938();
        r2 = ((u32)r2 < 0x00000001u);
    }
    return r2;
}

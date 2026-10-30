#include "../common/types.h"

// Agent R46p_140 (2026-10-29): FUN_002dc808 (68 bytes, SLPM_666.75).

extern "C" u32 func_002dc7c8(u32);

// FUN_002dc808: reads the word at arg0+0x8070. Calls func_002dc7c8(arg0), then returns the float at
// +180 of the result if the word was non-zero, otherwise the float at +0 of it.
float func_002dc808(u8* a0) {
    u32 t = *(u32*)(a0 + 0x8070u);
    if (t != 0) {
        u32 p = func_002dc7c8((u32)a0);
        return *(float*)(p + 180);
    }
    u32 q = func_002dc7c8((u32)a0);
    return *(float*)q;
}

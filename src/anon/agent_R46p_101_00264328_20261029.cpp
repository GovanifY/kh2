#include "../common/types.h"

// Agent R46p_101 (2026-10-29): FUN_00264328 (96 bytes, SLPM_666.75).

extern "C" u8* func_00263ea8(void);

// FUN_00264328: p = func_00263ea8(); the word at p+12 is an offset to a table of u16 entries at p+off.
// Scan up to 128 entries for one equal to a0; return its index, or -1 if none matches.
s32 func_00264328(s32 a0) {
    s32 i;
    s32 r;
    u8* p = func_00263ea8();
    u16* q = (u16*)(p + *(s32*)(p + 12));
    r = -1;
    i = 0;
    do {
        if ((s32)q[0] == a0) {
            r = i;
            break;
        }
        i++;
        q++;
    } while (i < 128);
    return r;
}

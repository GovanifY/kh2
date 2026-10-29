#include "../common/types.h"

// Agent R46p_17 (2026-10-29): func_00198b88 (68 bytes), SLPM_666.75.
// Code: walks a table of 88-byte records from D_01c60000 + 6984 to + 1408 past that, calling
// func_00198dc0(record) for each. The loop is a do-while with a signed (s32) compare.
// Size is 68, not a multiple of 8, so the object gets -falign-functions=1 in the Makefile.

extern u8 D_01c60000[];
void func_00198dc0(u8*);

void func_00198b88(void) {
    u8* p = D_01c60000 + 0x1b48;
    u8* end = p + 1408;
    do {
        func_00198dc0(p);
        p += 88;
    } while ((s32)p < (s32)end);
}

#include "../common/types.h"

// Agent R46p_17 (2026-10-29): func_00192320 (104 bytes), SLPM_666.75.
// Code: zeroes the words at D_01c60000 + 6512 + i * 8 for i = 2 down to 0 (three entries, the same
// table func_001922c8 reads). Then calls wtarget_002fee78(buf, &D_00370000[-12896], word at
// D_00340000[-13580]) and func_001b1490(buf), and calls func_00191f78(1, result).
// buf is a 48-byte local at sp.

extern u8 D_01c60000[];
extern u8 D_00340000[];
extern u8 D_00370000[];
void wtarget_002fee78(u32, u32, u32) asm("_Z16wtarget_002fee78jjjj");
u32 func_001b1490(u32);
u32 func_00191f78(u32, u32);

void func_00192320(void) {
    u8 buf[48];
    u32* p = (u32*)(D_01c60000 + 0x1970);
    s32 n = 2;
    do {
        *p = 0;
        p += 2;
        n--;
    } while (n >= 0);
    wtarget_002fee78((u32)&buf[0], (u32)&D_00370000[-12896], *(u32*)&D_00340000[-13580]);
    u32 v = func_001b1490((u32)&buf[0]);
    func_00191f78(1, v);
}

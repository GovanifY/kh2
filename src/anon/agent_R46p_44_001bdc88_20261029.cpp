#include "../common/types.h"

// Agent R46p_44 (2026-10-29): FUN_001bdc88 (68 bytes, SLPM_666.75).
// Code: if the word at +32 has bit 0x40 set, call func_0013b320(obj), then clear bit 0x40 in the word at +32.
extern "C" void func_0013b320(u8* a0);

void func_001bdc88(u8* p) {
    if ((*(s32*)(p + 32) & 0x40) != 0) {
        func_0013b320(p);
        *(s32*)(p + 32) = *(s32*)(p + 32) & -65;
    }
}

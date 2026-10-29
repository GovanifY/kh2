#include "../common/types.h"

// Agent R46p_17 (2026-10-29): func_001922c8 (88 bytes), SLPM_666.75.
// Code: reads the word at D_01c60000 + 6512 + idx * 8. If it is non-zero, calls
// CACHE_BUFF::Free(p) (func_00170950) and tail-jumps to func_00192028 with idx.
// Otherwise it returns without the tail call.

void cache_buff_free(void*) asm("_ZN2YS10CACHE_BUFF4FreeEPv");
void func_00192028(s32);
extern u8 D_01c60000[];

void func_001922c8(s32 idx) {
    u32* tbl = (u32*)(D_01c60000 + 0x1970);
    void* p = (void*)tbl[idx * 2];
    if (p != 0) {
        cache_buff_free(p);
        func_00192028(idx);
    }
}

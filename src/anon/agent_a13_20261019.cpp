#include "../common/types.h"

extern u8 D_0035dcf0[];
extern u8 D_0035dcfc[];
extern u8 D_01dad9c0[];

// FUN_00227a28 (56 bytes): scans 128 records of 84 bytes starting at the pointer stored at
// 0x35DCF0 and returns the first one whose word at +4 is zero, else NULL.
u8* func_00227a28(void) {
    u8* p = *(u8**)D_0035dcf0;
    s32 i;
    for (i = 0; i < 128; i++) {
        if (*(s32*)(p + 4) == 0) return p;
        p += 84;
    }
    return 0;
}

// FUN_00227cd8 (56 bytes): scans 96 records of 40 bytes starting at the pointer stored at
// 0x35DCFC and returns the first one whose first word equals a0, else NULL.
u8* func_00227cd8(s32 a0) {
    u8* p = *(u8**)D_0035dcfc;
    s32 i;
    for (i = 0; i < 96; i++) {
        if (*(s32*)p == a0) return p;
        p += 40;
    }
    return 0;
}

// FUN_0022d7e8 (52 bytes; object built with -falign-functions=1): clears 32 records of
// 8 bytes at 0x1DAD9C0 to {0, -1, -1}. The -1 constant is pinned to t5 so that gcc loads it
// before the count, matching the original prologue order.
void func_0022d7e8(void) {
    register s32 m asm("$13") = -1;
    u8* p = D_01dad9c0;
    s32 i = 31;
    do {
        *(u32*)p = 0;
        i--;
        *(s16*)(p + 4) = m;
        *(s16*)(p + 6) = m;
        p += 8;
    } while (i >= 0);
}

#include "../common/types.h"

// FUN_001bff88 (80 bytes)
// Code: zeroes 8 words starting at D_01d50000 - 27864, then stores 256 at D_01d50000 - 27828
//       and zero at D_01d50000 - 27832, D_01d50000 - 27824 and D_01d50000 - 27820.
// Guess: clears a 32-byte block and resets three global words in the same 0x1d5xxxx region.
// Note: the loop base uses the extern symbol so gcc emits lui 0x1d5 / addiu -27864. The tail
//       uses literal bases, one per store group, with empty asm barriers so each group gets its
//       own lui like the original.
extern u32 D_01d50000[];
void func_001bff88() {
    register u32* b asm("$15");
    register u32* b2 asm("$14");
    register u32* b3 asm("$12");
    register u32* t3 asm("$11");
    register u32 v256 asm("$13");
    u32* p = &D_01d50000[-6966];
    s32 t6 = 7;
    do {
        *p = 0;
        t6 = t6 - 1;
        p = p + 1;
    } while (t6 >= 0);
    v256 = 256;
    b = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b));
    b2 = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b2));
    b[-6957] = v256;
    b2[-6958] = 0;
    b3 = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b3));
    t3 = b3 - 6956;
    __asm__ volatile("" : "+r"(t3));
    b3[-6956] = 0;
    t3[1] = 0;
}

#include "../common/types.h"

void func_00239558(u8* a0, u16* a1, u16* a2) {
    *(u32*)(a0 + 16) = *(u32*)(a0 + 16) | 0x40u;
    u8* p = a0;
    for (s32 i = 0; i < 4; i++) {
        *(u16*)(p + 160) = a1[i];
        *(u16*)(p + 168) = a2[i];
        p += 2;
    }
}

void func_00198aa8(u8* a0, s32 a1, s32 a2, s32 a3) {
    s32 t6 = 1000;
    if (a3 == 0) {
        u8* t7 = *(u8**)(a0 + 2484);
        a3 = -1;
        if (t7 != 0) {
            a3 = *(s16*)(t7 + 2);
            t6 = 1000;
        }
    }
    u8* base = a0 + a1 * 12;
    *(s32*)(base + 2532) = a3 * t6 + a2;
}

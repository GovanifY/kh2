#include "../common/types.h"

// Agent R46p_10 (2026-10-29): FUN_00188670 (96 bytes). Clears 64 words at 0x1c608c0 with a 12-byte stride
// (do-while, signed compare), clears the word at 0x1c60bc0, then tail-calls
// func_00102788(*(0x351214), 0, 0, 0x188550). The 0x188550 is taken from a symbol base so gcc emits lui 0x19 + addiu.
u32 func_00102788(u32, u32, u32, u32);
extern u8 D_01c60000[];
extern u8 D_00190000[];
extern u8 D_00350000[];

void func_00188670(void) {
    u32* p = (u32*)(D_01c60000 + 0x8c0);
    u32* end = (u32*)(D_01c60000 + 0x8c0 + 768);
    do {
        *p = 0;
        p += 3;
    } while ((s32)p < (s32)end);
    *(u32*)(D_01c60000 + 0xbc0) = 0;
    func_00102788(*(u32*)(D_00350000 + 0x1214), 0, 0, (u32)&D_00190000[-31408]);
}

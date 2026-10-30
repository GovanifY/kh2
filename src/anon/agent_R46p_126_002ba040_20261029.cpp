#include "../common/types.h"

extern u8 D_01e2a410;

void func_002bcfe8(u32);
void func_002bd030(u32);
u32 func_002b6adc(u32, u32);

// FUN_002ba040 (108 bytes)
// Code: func_002bcfe8(obj) and func_002bd030(obj) with obj = &D_01e2a410, then
//       twice: func_002b6adc(2, s1+20) and func_002b6adc(0, s1+20), s1 = 0..1.
void func_002ba040(void) {
    u32 obj = (u32)&D_01e2a410;
    u32 i = 0;
    func_002bcfe8(obj);
    func_002bd030(obj);
    do {
        u32 p = i + 20;
        func_002b6adc(2, p);
        i++;
        func_002b6adc(0, p);
    } while ((s32)i < 2);
}

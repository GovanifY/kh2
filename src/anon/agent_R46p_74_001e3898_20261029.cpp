#include "../common/types.h"

extern "C" u32 func_001e3650(u32) asm("func_001e3650");

void func_001e3898(u32 a0, u32 a1) {
    u32 *v = (u32*)func_001e3650(a0);
    s32 t5 = 4;
    do {
        s32 n = (s32)*v;
        v++;
        if (n > 0) {
            s32 t6 = n;
            do {
                *v = *v + a1;
                t6--;
                v++;
            } while (t6 != 0);
        }
        t5--;
    } while (t5 >= 0);
}

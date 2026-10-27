#include "../common/types.h"

extern "C" u32 _ZN2YS3OBJ7is_hideEv(u32);

extern "C" u32 func_00176258(u8 *a0);
u32 func_00176258(u8 *a0) {
    u32 *s0 = (u32 *)(a0 + 2808);
    s32 s1 = 0;
    for (;;) {
        u32 t = *s0;
        s0++;
        if (t != 0) {
            if (_ZN2YS3OBJ7is_hideEv(t) == 0) return 1;
        }
        s1++;
        if (!(s1 < 2)) return 0;
    }
}

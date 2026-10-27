#include "../common/types.h"

extern "C" void func_001b7f88(void);
extern u8 D_00350000[];

extern "C" u32 func_001b81e8(void);
u32 func_001b81e8(void) {
    func_001b7f88();
    u32 v = *(u32 *)&D_00350000[0x11b8];
    *(u8 *)&D_00350000[0x11c1] = 1;
    return v;
}

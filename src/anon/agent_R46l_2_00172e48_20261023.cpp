#include "../common/types.h"

// Agent R46l_2: FUN_00172e48 (60 bytes), SLPM_666.75.
// func_0019ba60(p[0]->[1]); then p[0] = (p[0]->[1])->[690] (offset 2760).
extern "C" u32 func_0019ba60(u32 a0);

void func_00172e48(u32* p) {
    func_0019ba60(((u32*)p[0])[1]);
    u32* t6 = (u32*)((u32*)p[0])[1];
    p[0] = t6[690];
}

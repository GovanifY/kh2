#include "../common/types.h"

extern u8 D_01e2a568;
extern u8 D_00374f70;

u32 func_002fee78(u32, u32, u32);
u32 func_002ff3fc(u32);

// FUN_002ba0b0 (68 bytes)
// Code: obj = &D_01e2a568; func_002fee78(obj, &D_00374f70, arg0); func_002ff3fc(obj);
//       returns obj.
u32 func_002ba0b0(u32 a0) {
    u32 obj = (u32)&D_01e2a568;
    func_002fee78(obj, (u32)&D_00374f70, a0);
    func_002ff3fc(obj);
    return obj;
}

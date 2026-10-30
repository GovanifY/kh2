#include "../common/types.h"

extern u8 D_01e2a5a8;
extern u8 D_00374f80;

u32 func_002fee78(u32, u32, u32);
u32 func_002ff3fc(u32);

// FUN_002ba0f8 (68 bytes)
// Code: obj = &D_01e2a5a8; func_002fee78(obj, &D_00374f80, arg0); func_002ff3fc(obj);
//       returns obj.
u32 func_002ba0f8(u32 a0) {
    u32 obj = (u32)&D_01e2a5a8;
    func_002fee78(obj, (u32)&D_00374f80, a0);
    func_002ff3fc(obj);
    return obj;
}

#include "../common/types.h"

extern u8 D_01e2a410;

void func_002bc9a8(u32, u32, u32);
void func_002bce10(u32, u32);

// FUN_002b9b78 (88 bytes)
// Code: obj = 0x01E2A410; func_002bc9a8(obj, 2, 0); func_002bce10(obj, 2);
//       func_002bc9a8(obj, 3, 999); func_002bce10(obj, 3) (tail call).
void func_002b9b78(void) {
    u32 obj = (u32)&D_01e2a410;
    func_002bc9a8(obj, 2, 0);
    func_002bce10(obj, 2);
    func_002bc9a8(obj, 3, 999);
    func_002bce10(obj, 3);
}

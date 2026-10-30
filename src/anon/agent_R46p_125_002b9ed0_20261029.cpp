#include "../common/types.h"

extern u8 D_01e2a410;

void func_002baa78(void);
void func_002bcfe8(u32);
void func_002bd030(u32);
void func_002bd078(u32);
void func_002bd0b8(u32);
void func_002bd100(u32);
void func_002bd140(u32);

// FUN_002b9ed0 (84 bytes)
// Code: func_002baa78(); then func_002bcfe8, func_002bd030, func_002bd078,
//       func_002bd0b8, func_002bd100 on obj, and func_002bd140(obj) as a tail call.
void func_002b9ed0(void) {
    u32 obj = (u32)&D_01e2a410;
    func_002baa78();
    func_002bcfe8(obj);
    func_002bd030(obj);
    func_002bd078(obj);
    func_002bd0b8(obj);
    func_002bd100(obj);
    func_002bd140(obj);
}

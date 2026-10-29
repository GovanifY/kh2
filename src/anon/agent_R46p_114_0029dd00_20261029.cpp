#include "../common/types.h"

// Agent R46p_114 (2026-10-29): FUN_0029dd00 (96 bytes). Uses a 128-byte local buffer (passed as sp).
// b = signed byte at +4 of the pointer stored at D_00360000-2644. r = func_00293de8(b).
// func_00293cb8(buf, 4, r). v = func_002ff918(buf, word at D_00360000-2616). If v != 0,
// func_002ff2e8(v, word at D_00360000-2612). Then func_002931a8(buf).
extern "C" u32 func_00293de8(s32);
extern "C" void func_00293cb8(u8*, u32, u32);
extern "C" u32 func_002ff918(u8*, u32);
extern "C" void func_002ff2e8(u32, u32);
extern "C" void func_002931a8(u8*);
extern u8 D_00360000[];

void func_0029dd00(void) {
    u8 buf[128];
    u32 p = *(u32*)&D_00360000[-2644];
    s32 b = *(s8*)(p + 4);
    u32 r = func_00293de8(b);
    func_00293cb8(buf, 4, r);
    u32 v = func_002ff918(buf, *(u32*)&D_00360000[-2616]);
    if (v != 0) {
        func_002ff2e8(v, *(u32*)&D_00360000[-2612]);
    }
    func_002931a8(buf);
}

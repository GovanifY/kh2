#include "../common/types.h"

// Agent R46p_116 (2026-10-29): FUN_0029dda8 (108 bytes). n = GetSelectPos(15). Reads a halfword from
// base(D_00360000-2644) + 2n + 8, passes it to func_0029da68, reads a signed byte at +1 of the result, then
// calls func_00292a90(byte); if that is non-zero, returns. Otherwise calls func_00292af0(byte); if that is
// non-zero, returns; else tail-calls RequestGraLoad (0x0029dd60).
extern "C" u32 r_GetSelectPos(s32) asm("_ZN2Tz6Jiminy12GetSelectPosEi");
extern "C" u32 func_0029da68(s32);
extern "C" u32 func_00292a90(s32);
extern "C" u32 func_00292af0(s32);
extern "C" void r_RequestGraLoad(void) asm("_ZN2Tz5JmDic14RequestGraLoadEv");
extern u8 D_00360000[];

void func_0029dda8(void) {
    u32 n = r_GetSelectPos(15);
    u32 q = (n << 1) + *(u32*)&D_00360000[-2644];
    s32 h = *(s16*)(q + 8);
    u32 p = func_0029da68(h);
    s32 s = *(s8*)(p + 1);
    if (func_00292a90(s) != 0) {
        return;
    }
    if (func_00292af0(s) != 0) {
        return;
    }
    r_RequestGraLoad();
}

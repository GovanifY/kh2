#include "../common/types.h"

// Agent R46l_2: FUN_00172928 (92 bytes), SLPM_666.75.
// s1 = p[0]->[1]; v = func_0016a020(s1); func_0019b0e8(buf, v, p[1], float p[2], float p[3]); func_0016ace0(s1, buf).
// Volatile loads pin the argument order. The buffer address is a move from $29 that depends on the
// float p[3] load, so it lands after the f13 load as in the original. The float p[2] load fills the jal delay slot.
extern "C" u32 func_0016a020(u32 a0);
extern "C" void func_0019b0e8(u32 a0, u32 a1, u32 a2, f32 f12, f32 f13);
extern "C" void func_0016ace0(u32 a0, u32 a1);

void func_00172928(u32* p) {
    u32 s1 = ((u32*)p[0])[1];
    u32 buf[4];
    u32 v = func_0016a020(s1);
    u32 a2 = *(volatile u32*)&p[1];
    f32 f3 = *(volatile f32*)&p[3];
    register u32 a0r asm("$4");
    asm("move %0,$29" : "=r"(a0r) : "f"(f3));
    f32 f2 = *(volatile f32*)&p[2];
    func_0019b0e8(a0r, v, a2, f2, f3);
    func_0016ace0(s1, (u32)buf);
}

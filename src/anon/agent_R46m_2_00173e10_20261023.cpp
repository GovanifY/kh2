#include "../common/types.h"

// Agent R46m_2 (2026-10-23): FUN_00173e10 (40 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Loads p[0] (pointer q), p[1] (a1), q[1] (a0), and the float p[2] (f12),
// then tail-calls func_001846a0(a0, a1, f12).
// Matching: plain C with the loads pinned to the original order (q in $15, the rest as asm-free locals).
extern "C" void func_001846a0(void *a0, u32 a1, f32 f);
extern "C" void func_00173e10(u32 *p);

void func_00173e10(u32 *p) {
    register u32 *q asm("$15");
    u32 a1;
    u32 v;
    q = (u32 *)p[0];
    a1 = p[1];
    v = q[1];
    func_001846a0((void *)v, a1, *(f32 *)&p[2]);
}

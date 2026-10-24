#include "../common/types.h"

// Agent R46m_2 (2026-10-23): FUN_00174168 (40 bytes), SLPM_666.75.
// Same shape as FUN_00173e10: tail-calls func_00183768(q[1], p[1], float p[2]) with q = p[0].
// Matching: plain C with the loads pinned to the original order (q in $15).
extern "C" void func_00183768(void *a0, u32 a1, f32 f);
extern "C" void func_00174168(u32 *p);

void func_00174168(u32 *p) {
    register u32 *q asm("$15");
    u32 a1;
    u32 v;
    q = (u32 *)p[0];
    a1 = p[1];
    v = q[1];
    func_00183768((void *)v, a1, *(f32 *)&p[2]);
}

#include "../common/types.h"

// Agent R46m_2 (2026-10-23): FUN_00175328 (36 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. q = p[0]; a2 = p[2]; a1 = p[1]; tail-calls func_001a5880(q, a1, a2).
// Matching: empty asm barriers keep the loads in the original order. Needs -falign-functions=1 (36 bytes).
extern "C" void func_001a5880(void *a0, u32 a1, u32 a2);
extern "C" void func_00175328(u32 *p);

void func_00175328(u32 *p) {
    register u32 *q asm("$15");
    u32 a1;
    u32 a2;
    q = (u32 *)p[0];
    asm volatile("" : "+r"(q));
    a2 = p[2];
    asm volatile("" ::: "memory");
    a1 = p[1];
    func_001a5880(q, a1, a2);
}

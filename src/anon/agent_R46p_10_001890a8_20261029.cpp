#include "../common/types.h"

// Agent R46p_10 (2026-10-29): FUN_001890a8 (96 bytes). If func_00181a70(a0) is nonzero, calls
// func_00189068(a0, a1) to get a pointer p. If p is non-null and *p < 9999, stores *p + 1 back to *p.
extern "C" u32 func_00181a70(u32);
extern "C" u32 func_00189068(u32, u32);

void func_001890a8(u32 a0, u32 a1) {
    if (func_00181a70(a0) != 0) {
        u32* p = (u32*)func_00189068(a0, a1);
        if (p != 0) {
            u32 v = *p;
            if (v < 9999u) {
                *p = v + 1;
            }
        }
    }
}

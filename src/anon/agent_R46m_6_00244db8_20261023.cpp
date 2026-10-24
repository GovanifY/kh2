#include "../common/types.h"

// Agent R46m_6 (2026-10-23): FUN_00244db8 (108 bytes), SLPM_666.75.
// Two passes over a 408-byte record table whose base word is at D_00360000 - 4860. For each record,
// if the predicate at 0x139d78 returns non-zero, call virtual slot 5 on the record (first word is its vtable).
extern u8 D_00360000[] asm("D_00360000");
extern "C" u32 r46m6_pred_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

void r_FUN_00244db8(void) asm("func_00244db8");

void r_FUN_00244db8(void) {
    u32 off = 0;
    s32 i = 1;
    do {
        u32 rec = *(u32*)(&D_00360000[-4860]) + off;
        if (r46m6_pred_00139d78(rec) != 0u) {
            void** obj = (void**)(off + *(u32*)(&D_00360000[-4860]));
            void** vt = (void**)*obj;
            ((void (*)(void*))vt[5])((void*)obj);
        }
        i = i - 1;
        off = off + 408u;
    } while (i >= 0);
}

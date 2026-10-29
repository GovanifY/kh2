#include "../common/types.h"

// Agent R46p_95: FUN_00250928 (108 bytes), SLPM_666.75.
// Five passes over a 408-byte record table whose base word is at D_00360000 - 4536. For each record,
// if the predicate at 0x139d78 returns non-zero, call virtual slot 5 on the record.
// Same shape as FUN_0024c828 with a different base offset and pass count.
extern u8 D_00360000[] asm("D_00360000");
extern "C" u32 r46p95_pred_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

void func_00250928(void) {
    u32 off = 0;
    s32 i = 4;
    do {
        if (r46p95_pred_00139d78(*(u32*)(&D_00360000[-4536]) + off) != 0u) {
            void** obj = (void**)(off + *(u32*)(&D_00360000[-4536]));
            void** vt = (void**)*obj;
            ((void (*)(void*))vt[5])((void*)obj);
        }
        i = i - 1;
        off = off + 408u;
    } while (i >= 0);
}

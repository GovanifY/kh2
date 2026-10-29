#include "../common/types.h"

// Agent R46p_95: FUN_002519d0 (52 bytes), SLPM_666.75.
// Calls the predicate at 0x139d78 on the word at D_00360000 - 4480; if it returns 0,
// calls 0x28acc8 on the word at D_00360000 - 4516.
extern u8 D_00360000[] asm("D_00360000");
extern "C" u32 r46p95_pred_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");
extern "C" u32 r46p95_isCreated_0028acc8(u32) asm("func_0028acc8");

void func_002519d0(void) {
    if (r46p95_pred_00139d78(*(u32*)(&D_00360000[-4480])) == 0u) {
        r46p95_isCreated_0028acc8(*(u32*)(&D_00360000[-4516]));
        asm volatile("" ::: "memory");
    }
}

#include "../common/types.h"

// Agent R46m_7 (2026-10-23): FUN_001d29a0 (40 bytes), SLPM_666.75.
// Loads the float at 0x36e3c8 into f12, moves a1 into a0, sets a1 to 0, and
// tail-calls FUN_001a5990(float, a1, 0).
extern u8 D_00370000[];
void func_001a5990(f32, u32, u32);

void func_001d29a0(u32, u32 a1) {
    f32* p = (f32*)&D_00370000[-7224];
    asm("" : "+r"(p));
    func_001a5990(*p, a1, 0);
}

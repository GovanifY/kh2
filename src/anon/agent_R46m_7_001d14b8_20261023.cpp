#include "../common/types.h"

// Agent R46m_7 (2026-10-23): FUN_001d14b8 (40 bytes), SLPM_666.75.
// Reads the word at +2896 of a0. If it is not 6, tail-calls FUN_00176cd0(a0).
void func_00176cd0(u32);

void func_001d14b8(u32 a0) {
    if (*(s32*)(a0 + 2896) != 6) func_00176cd0(a0);
}

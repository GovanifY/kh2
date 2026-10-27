#include "../common/types.h"

// FUN_002fd220 (40 bytes): calls FUN_002ffbb0(a0, 0, 10) and returns its result truncated to s32 (sign-extended).
extern "C" s64 func_002ffbb0(u32 a0, u32 a1, u32 a2);

s32 func_002fd220(u32 a0) {
    return (s32)func_002ffbb0(a0, 0, 10);
}

#include "../common/types.h"

extern "C" u32 func_001b58f0(u32, u32, u32, u32);

// FUN_0018fe48 (56 bytes): calls FUN_001b58f0(word[0], word[1], word[2], 0) on the object at a0 and
// stores the result back into word[0].
void func_0018fe48(u32* a0) {
    u32 v = func_001b58f0(a0[0], a0[1], a0[2], 0);
    a0[0] = v;
}

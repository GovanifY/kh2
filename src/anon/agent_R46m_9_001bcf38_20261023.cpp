#include "../common/types.h"

// FUN_001bcf38 (72 bytes)
// Code: loads the signed word at arg0. Returns 1 for 5, 10, and 13..18, else 0.
// Guess: a predicate over a small type or state ID set.
u32 func_001bcf38(s32* a0) {
    s32 a = a0[0];
    switch (a) {
    case 5:
    case 10:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 1;
    default:
        return 0;
    }
}

#include "../common/types.h"

// FUN_002ff918 (84 bytes)
// Code: substring search (strstr-like). Returns a pointer to the first
// occurrence of needle in hay, or NULL. Empty needle returns hay. The
// inner loop reads needle[i] and hay[i]; on a mismatch the outer loop
// advances hay by one byte and restarts i at zero.
// Guess: the compiler emits the restart as a branch-likely with the i = 0
// reset in the delay slot, which matches the original shape.
s8* func_002ff918(s8* hay, s8* needle) {
    s8* p = hay;
    if (*hay == 0) {
        if (*needle) p = 0;
        return p;
    }
    s32 i;
    for (;;) {
        i = 0;
        for (;;) {
            s8 n = needle[i];
            if (n == 0) return p;
            if (n != p[i]) break;
            i++;
        }
        p++;
        if (*p == 0) return 0;
    }
}

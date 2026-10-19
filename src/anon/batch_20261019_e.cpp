#include "../common/types.h"

// FUN_00145c68 (68 bytes)
// Code: n = word at +20 of arg0. If n > 0, walks n records of 28 bytes from the
// pointer at +8 of arg0 (read at the top of each pass). A record whose byte at
// +1 equals (byte)arg1 gets its byte at +0 set to 1.
// Guess: marks matching entries in a table of 28-byte records keyed by a byte,
// for example a selection or visibility flag.
void func_00145c68(u8* a0, u32 a1) {
    register s32 n asm("$15") = *(s32*)(a0 + 20);
    u8 c = (u8)a1;
    if (n > 0) {
        register s32 cnt asm("$13") = n;
        u8 one = 1;
        u32 off = 0;
        do {
            u8* p = (u8*)(off + *(u32*)(a0 + 8));
            off += 28;
            if (p[1] == c) {
                p[0] = one;
            }
        } while (--cnt != 0);
    }
}

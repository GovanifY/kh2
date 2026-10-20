#include "../common/types.h"
typedef int u128 __attribute__((mode(TI)));

// FUN_00140850 (80 bytes)
// Code: copies three 16-byte vectors inside a block: +128->+144, +96->+112, +160->+176 (skipping self-copies).
// Guess: copies sub-matrix/vector rows within a struct.
void func_00140850(u8* a0) {
    u8* d; u8* s;
    d = a0 + 144; s = a0 + 128; __asm__("" : "+r"(d), "+r"(s));
    if (d != s) { register u128 t asm("$8") = *(u128*)s; *(u128*)d = t; __asm__("" :: "r"(s)); }
    d = a0 + 112; s = a0 + 96; __asm__("" : "+r"(d), "+r"(s));
    if (d != s) { register u128 t asm("$8") = *(u128*)s; *(u128*)d = t; __asm__("" :: "r"(s)); }
    s = a0 + 160; a0 += 176; __asm__("" : "+r"(a0), "+r"(s));
    if (a0 != s) { register u128 t asm("$8") = *(u128*)s; *(u128*)a0 = t; }
}

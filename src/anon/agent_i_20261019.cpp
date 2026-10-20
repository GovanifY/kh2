#include "../common/types.h"

extern u16 D_00374aa8[];
extern u32 D_01c6ced0[];

struct Func148638Obj {
    u8 pad[0x10d];
    u8 mode;
    u8 pad2[6];
    float* limits;
};

// FUN_0029ec98 (88 bytes)
// Code: searches a zero-terminated u16 list at 0x374AA8 for arg0; returns 1 if found, else 0.
// Guess: membership test in a 0-terminated id list.
s32 func_0029ec98(s32 a0) {
    s32 r = 0;
    s32 i = 0;
    if (D_00374aa8[0] != 0) {
        do {
            if (D_00374aa8[i] == a0) {
                r = 1;
                break;
            }
            i++;
        } while (D_00374aa8[i] != 0);
    }
    return r;
}

// FUN_00148638 (84 bytes)
// Code: sets obj->mode (+269) from comparing float a2 against four thresholds at
//       obj->limits (+56,+60,+64,+68): >68 -> 2, >64 -> keep, >60 -> 1, >56 -> keep, else 0.
// Guess: picks a state byte from a value against a threshold table.
void func_00148638(void* a0, Func148638Obj* o, float a2) {
    float* s = o->limits;
    u8 cur = o->mode;
    float f38 = s[14];
    float f3c = s[15];
    float f40 = s[16];
    u8 m;
    if (s[17] < a2) m = 2;
    else if (f40 < a2) m = cur;
    else if (f3c < a2) m = 1;
    else if (f38 < a2) m = cur;
    else m = 0;
    o->mode = m;
}

// FUN_001ac778 (20 bytes)
// Code: zeroes the two adjacent words at 0x01c6ced0 and 0x01c6ced4.
// Guess: clears a pair of globals. The empty asm statement is a compiler barrier
//        so the base address is computed before the first store.
void func_001ac778() {
    u32* p = D_01c6ced0;
    __asm__ volatile("" ::: "memory");
    D_01c6ced0[0] = 0;
    p[1] = 0;
}

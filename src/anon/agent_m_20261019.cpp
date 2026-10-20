#include "../common/types.h"

extern u8 D_00350000;
extern u8 D_0034ee08;
extern u8 D_002ef1b8;

void func_0018a008(u32, u32);
void func_0019f9a8(u32);
void func_001c0248(u32);
void func_00319fb0(u32);
void func_00105110(u32);

// FUN_00147c78 (36 bytes)
// Code: copy bytes 232..235 of a1 to offsets 12..15.
// Guess: refresh a 4-byte field from its backup copy.
void func_00147c78(u8* a0, u8* a1) {
    a1[12] = a1[232];
    a1[13] = a1[233];
    a1[14] = a1[234];
    a1[15] = a1[235];
}

// FUN_002ef180 (56 bytes)
// Code: if (a0->+12 != 0) tail-call func_0018a008(that, &label).
// Guess: release/notify the object held at +12.
// asm use: empty asm keeps a0 alive in $a2 (original copies a0 to a2).
void func_002ef180(u32 a0) {
    register u32 keep asm("$6") = a0;
    u32 p = *(u32*)(a0 + 12);
    __asm__ volatile("" :: "r"(keep));
    if (p != 0) func_0018a008(p, (u32)&D_002ef1b8);
}

// FUN_00161a80 (40 bytes)
// Code: clamp a0 to 0..128 and store to a global.
// Guess: set a volume/level value.
void func_00161a80(s32 a0) {
    s32 v = a0 < 0 ? 0 : (a0 > 128 ? 128 : a0);
    *(s32*)(&D_00350000 - 14484) = v;
}

// FUN_0031f340 (72 bytes)
// Code: set vtable, destroy two members, call base dtor, tail-call AREA::Free.
// Guess: deleting-style destructor.
void func_0031f340(u32 a0) {
    *(u32*)a0 = (u32)&D_0034ee08;
    func_0019f9a8(a0 + 2568);
    func_001c0248(a0 + 2640);
    func_00319fb0(a0);
    func_00105110(a0);
}

#include "../common/types.h"

// Globals in the 0x330000 page, addressed as base-relative offsets so gcc emits
// lui 0x33 plus a negative lw/sw/sb offset, as the original does.
extern u8 D_00330000;

u32 func_00102788(u32, u32, u32, u32);
u32 func_00102818(u32, u32, u32, u32, u32);
void func_00103ea0(u32);
void func_001037f8(void);

// FUN_001037b8 (64 bytes): calls func_00102788(*(0x32B91C), 0, 0x50910, func_001037f8),
// then sets the byte at 0x32BA28 to 1.
void func_001037b8() {
    func_00102788(*(u32*)((u32)&D_00330000 - 18148u), 0, 0x00050910u, (u32)func_001037f8);
    *(u8*)((u32)&D_00330000 - 17880u) = 1;
}

// FUN_001039f8 (68 bytes): t6 = 3. If the function pointer at 0x32BA34 is non-null, call it
// and tail-call func_00103ea0(0). Otherwise store t6 to the word at 0x32BA04.
void func_001039f8() {
    u32 t6 = 3;
    u32 t7 = *(u32*)((u32)&D_00330000 - 17868u);
    if (t7 != 0) {
        ((void (*)())t7)();
        func_00103ea0(0);
        return;
    }
    *(u32*)((u32)&D_00330000 - 17916u) = t6;
}

// FUN_00103b78 (56 bytes): tail-calls func_00102818(*(0x32B9EC), a0, a1, a2, a3).
// Five arguments: the fifth (a4 = t0) is the original a3.
u32 func_00103b78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102818(*(u32*)((u32)&D_00330000 - 17940u), a0, a1, a2, a3);
}

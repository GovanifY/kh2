#include "../common/types.h"

// FUN_001a2668 (80 bytes). Sibling of FUN_001a2578/001a25c8/001a2618, but the
// byte is at record +8 and the two u16 fields are at +398 and +406.
// If the pointer at +580 is non-null, the byte at (pointer)+8 gets a1 added,
// clamped so the byte stays at most 100 (a1 is replaced by 100 - byte in that case).
// The u16 fields at +398 and +406 then each get the (possibly clamped) a1 added.
// Register pins keep the original layout: record in $14, byte in $12,
// masked byte in $13, temp in $15. The andi is an asm op because gcc folds it.

void func_001a2668(u8* a0, s32 a1) {
    register u8* x asm("$14");
    register s32 c asm("$12");
    register s32 d asm("$13");
    register s32 t asm("$15");
    x = *(u8**)(a0 + 580);
    if (x) {
        c = x[8];
        asm("andi %0,%1,0xff" : "=r"(d) : "r"(c));
        t = d + a1;
        if (t >= 101) { a1 = 100 - d; }
        t = c + a1;
        x[8] = (u8)t;
    }
    *(u16*)(a0 + 398) = (u16)(*(u16*)(a0 + 398) + a1);
    *(u16*)(a0 + 406) = (u16)(*(u16*)(a0 + 406) + a1);
}

#include "../common/types.h"

// Three leaf functions with the same shape, differing only in offsets.
// Each: if the pointer at +580 is non-null, it points at a record whose u8
// (+9, +10, +11) is updated: v = byte + delta, where delta becomes 100 - byte
// when byte + delta would reach 101. Then the u16 fields (+392/+400,
// +394/+402, +396/+404) each get the (possibly updated) delta added.
// Guess: a per-object percentage-like nudge with a clamp at 100.
// Register pins ($12 byte, $13 masked byte, $14 record, $15 temp) keep the
// original register layout; the andi is an asm op because gcc folds it away.

void func_001a2578(u8* a0, s32 a1) {
    register u8* x asm("$14");
    register s32 c asm("$12");
    register s32 d asm("$13");
    register s32 t asm("$15");
    x = *(u8**)(a0 + 580);
    if (x) {
        c = x[9];
        asm("andi %0,%1,0xff" : "=r"(d) : "r"(c));
        t = d + a1;
        if (t >= 101) { a1 = 100 - d; }
        t = c + a1;
        x[9] = (u8)t;
    }
    *(u16*)(a0 + 392) = (u16)(*(u16*)(a0 + 392) + a1);
    *(u16*)(a0 + 400) = (u16)(*(u16*)(a0 + 400) + a1);
}

void func_001a25c8(u8* a0, s32 a1) {
    register u8* x asm("$14");
    register s32 c asm("$12");
    register s32 d asm("$13");
    register s32 t asm("$15");
    x = *(u8**)(a0 + 580);
    if (x) {
        c = x[10];
        asm("andi %0,%1,0xff" : "=r"(d) : "r"(c));
        t = d + a1;
        if (t >= 101) { a1 = 100 - d; }
        t = c + a1;
        x[10] = (u8)t;
    }
    *(u16*)(a0 + 394) = (u16)(*(u16*)(a0 + 394) + a1);
    *(u16*)(a0 + 402) = (u16)(*(u16*)(a0 + 402) + a1);
}

void func_001a2618(u8* a0, s32 a1) {
    register u8* x asm("$14");
    register s32 c asm("$12");
    register s32 d asm("$13");
    register s32 t asm("$15");
    x = *(u8**)(a0 + 580);
    if (x) {
        c = x[11];
        asm("andi %0,%1,0xff" : "=r"(d) : "r"(c));
        t = d + a1;
        if (t >= 101) { a1 = 100 - d; }
        t = c + a1;
        x[11] = (u8)t;
    }
    *(u16*)(a0 + 396) = (u16)(*(u16*)(a0 + 396) + a1);
    *(u16*)(a0 + 404) = (u16)(*(u16*)(a0 + 404) + a1);
}

#include "../common/types.h"

// Agent H11 leaf functions (kh2 decomp, 2026-10-20). Each is checked against SLPM_666.75.
// Object flags (Makefile): -falign-functions=1, so the 28- and 52-byte bodies get no
// trailing 8-byte alignment nop.

// FUN_00222770 (28 bytes)
// Code: VU0 lower-lane subtract. Loads vf1 from a1, vf2 from a2 and vf3 from a0, computes
//       vf3.xy = vf1.xy - vf2.xy (z and w keep the old values in vf3), then stores vf3 back to a0.
// Guess: subtracts two 2D vectors in place into a0 (lower two lanes only).
// Layout: the vsub is one asm block in the original order. The sqc2 is its own asm statement,
//         then a "nop" asm, so GCC places sqc2 before "jr ra" and the nop in the delay slot.
void func_00222770(u8* a0, u8* a1, u8* a2) {
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "lqc2 $vf3,0(%0)\n\t"
        "vsub.xy $vf3,$vf1,$vf2\n\t"
        :
        : "r"(a0), "r"(a1), "r"(a2)
        : "memory");
    __asm__ volatile("sqc2 $vf3,0(%0)" : : "r"(a0) : "memory");
    __asm__ volatile("nop" ::: "memory");
}

// FUN_002282d8 (24 bytes)
// Code: loads the word at D_00360000-9448 (a flag). Returns 15000 if it is non-zero, else 25000.
//       Written as v0 = 25000; t7 = 15000; movn v0,t7,t6 (the original's order and registers).
// Guess: picks one of two constant timing values from a global flag.
// Layout: the 0x36 base is built as an extern-array symbol, so GCC emits lui plus lw with the
//         -9448 offset folded in. The asm barrier on the constant keeps li v0 before the load.
u32 func_002282d8() {
    extern u32 D_00360000[];
    register u32 r asm("$2") = 25000;
    register u32 k asm("$15") = 15000;
    u32 flag = *(u32*)((u32)&D_00360000[0] - 9448u);
    __asm__ volatile("" : "+r"(r), "+r"(k));
    if (flag) {
        r = k;
    }
    return r;
}

// FUN_00287d68 (52 bytes)
// Code: copies three words in the 0x36 table one slot up, and two more slots:
//       t5 = [0x36-3336], t4 = [0x36-3324], t3 = [0x36-3316] (all loaded first), then
//       [0x36-3332] = t5, [0x36-3320] = t4, [0x36-3312] = t3.
// Guess: shifts a three-word block of globals within the same table.
// Layout: each access rebuilds the 0x360000 base with lui, as the original does. Base pointers
//         are pinned to $15 and $14 (t7 and t6), and each pair of lui instructions is emitted
//         right before its two memory operations.
void func_00287d68() {
    register u32 a asm("$13");
    register u32 b asm("$12");
    register u32 c asm("$11");
    register u32* pa asm("$15");
    register u32* pb asm("$14");
    pa = (u32*)0x360000; __asm__ volatile("" : "+r"(pa));
    pb = (u32*)0x360000; __asm__ volatile("" : "+r"(pb));
    a = pa[-834];
    b = pb[-831];
    pa = (u32*)0x360000; __asm__ volatile("" : "+r"(pa));
    pb = (u32*)0x360000; __asm__ volatile("" : "+r"(pb));
    c = pa[-829];
    pb[-833] = a;
    pa = (u32*)0x360000; __asm__ volatile("" : "+r"(pa));
    pb = (u32*)0x360000; __asm__ volatile("" : "+r"(pb));
    pa[-830] = b;
    pb[-828] = c;
}

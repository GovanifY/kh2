#include "../common/types.h"

extern u8 D_00350000[];

// FUN_001dc738 (84 bytes at 0x001dc738, layout size 84)
// Code: t5 = a0[+8]. Returns 1 if t5 has bit 0x00400000 set. Otherwise, if the flag word at
//       0x34f240 (D_00350000-3520) has bit 0x20 set and a0[+4] != 3, returns 1. Otherwise
//       returns bit 26 of t5 (0 or 1).
// Guess: a predicate on an object's state word, with a global mode flag gating a field check.
// Matching: t5/mask/base pinned to $13/$15/$14 with the "+r" barrier removed; the constant 3
//       is written before the load so the compiler fills the beqz delay slot with it.
u32 func_001dc738(u32 a0) {
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register u8* base asm("$14");
    u32 v0 = 0;
    t5 = *(u32*)(a0 + 8);
    t7 = 0x00400000u;
    t7 = t5 & t7;
    if (t7 != 0) goto set1;
    base = D_00350000;
    t7 = *(u32*)(base - 3520);
    t7 = t7 & 0x20;
    if (t7 != 0) {
        t7 = 3;
        t6 = *(u32*)(a0 + 4);
        if (t6 != t7) { v0 = 1; goto end; }
    }
    t7 = (u32)((s32)t5 >> 26);
    t7 = t7 & 0x1;
    t7 = t7 & 0xff;
    if (t7 == 0) goto end;
set1:
    v0 = 1;
end:
    asm volatile("" : "+r"(v0));
    return v0;
}

// FUN_001ddc48 (64 bytes at 0x001ddc48, layout size 64)
// Code: p = D_00352ae0 (the word at D_00350000+10976). If p is non-null, walks the list
//       through the pointer at +40. On each node, clears bit 0x04000000 of the word at +8.
// Guess: clears one "active" bit on every node of a linked list rooted at a global.
// Matching: a goto-free do/while whose tail is a bnezl with the next +8 load in its delay slot.
//       The mask is pinned to $13 and the loads are kept in order with empty "+r" barriers.
void func_001ddc48(void) {
    register u8* p asm("$14");
    register u32 mask asm("$13");
    register u32 t7 asm("$15");
    p = *(u8**)(D_00350000 + 10976);
    if (p == 0) return;
    mask = 0xFBFFFFFFu;
    asm volatile("" : "+r"(mask));
    t7 = *(u32*)(p + 8);
    do {
        t7 &= mask;
        *(u32*)(p + 8) = t7;
        p = *(u8**)(p + 40);
        asm volatile("" : "+r"(p));
        if (p == 0) break;
        t7 = *(u32*)(p + 8);
    } while (1);
}

// FUN_001e01e8 (72 bytes at 0x001e01e8, layout size 72)
// Code: walks a list starting at a0[+12]. For each node p, if p->68 has no bit 0x200 in its
//       word at +16, then sets p->72 = a2 when p->72 == a1. The next node is p->96; the loop
//       ends at 0.
// Guess: a list update that replaces one field value in matching entries.
// Matching: the loop tail uses bnezl with the p->96 load in the delay slot and the head reload
//       (a0+12) on the fall-through; the "+r" barrier on p keeps gcc from splitting the test.
void func_001e01e8(u32 a0, u32 a1, u32 a2) {
    register u8* p asm("$13");
    register u8* q asm("$14");
    register u32 t7 asm("$15");
    u8* base = (u8*)a0;
    p = *(u8**)(base + 12);
    if (p == 0) return;
loop:
    q = *(u8**)(p + 68);
    if ((*(u32*)(q + 16) & 0x200) == 0) {
        if (*(u32*)(p + 72) == a1) *(u32*)(p + 72) = a2;
    }
    asm volatile("" : "+r"(p));
    if (p != 0) goto has_p;
    t7 = *(u32*)(base + 12);
    goto test;
has_p:
    t7 = *(u32*)(p + 96);
test:
    p = (u8*)t7;
    if (t7 != 0) goto loop;
}

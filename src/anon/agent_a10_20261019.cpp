#include "../common/types.h"

// Table base for FUN_0020e858 (16-byte slots, 256 slots, starting at 0x01DAC550).
extern u8 D_01dac550[];

// FUN_0020e858 (84 bytes)
// Code: clears the 16-byte node at a0 (sq $0), stores ((a1 - 1) | 0x20000000) at +0, clamps
// a2 to 0..255 (signed), and picks the slot at D_01dac550 + a2 * 16. It links the node into
// the list whose head is the word at slot+8: the old head's +4 word is saved, the head's +4
// is set to the node, the node's +4 takes the saved word, and the slot's head becomes the node.
// The final store and jr/nop are one noreorder asm block so the store sits before the jr.
// Guess: inserts a 16-byte record into one of 256 per-slot linked lists in an EE RAM table,
// tagged with a value derived from a1. The sibling FUN_0020e7a8 is the same shape with a 0..15
// clamp and table base D_01dac450.
// The lui/addiu pair for the table base is written as asm so the %hi/%lo halves match.
void func_0020e858(u32* a0, s32 a1, s32 a2) __attribute__((noreturn));
void func_0020e858(u32* a0, s32 a1, s32 a2) {
    register u32* e asm("$14");
    register u32* h asm("$15");
    register u32 n asm("$13");
    register u32 w asm("$15");
    register s32 c asm("$15");
    __asm__ volatile("sq $0,0(%0)" : : "r"(a0) : "memory");
    w = 0x20000000u;
    a1 = a1 - 1;
    a1 = a1 | w;
    *(volatile u32*)a0 = (u32)a1;
    __asm__ volatile("" : "+r"(a2));
    c = 0 < a2;
    __asm__ volatile("" : "+r"(c));
    __asm__ volatile("lui %0,%%hi(D_01dac550)" : "=r"(e));
    if (!c) a2 = 0;
    __asm__ volatile("addiu %0,%0,%%lo(D_01dac550)" : "+r"(e));
    a2 = (a2 < 256) ? a2 : 255;
    a2 = a2 << 4;
    __asm__ volatile("addu %0,%1,%0" : "+r"(e) : "r"(a2));
    h = (u32*)e[2];
    n = h[1];
    h[1] = (u32)a0;
    a0[1] = n;
    __asm__ volatile(".set noreorder\n\tsw %0,8(%1)\n\tjr $31\n\tnop\n\t.set reorder" : : "r"(a0), "r"(e) : "memory");
}

// FUN_0020ea48 (36 bytes)
// Code: stores the low bytes of a0, a1 and a2 at 0x00359150 (byte 0), +1 and +2. The base is
// the integer 0x00360000 with displacement -28336, so the lui is the only high-half
// instruction. The store order (a0, a2, then a1 in the jr delay slot) comes from the asm.
// Guess: writes three bytes of a small state block, for example a 3-channel setting.
void func_0020ea48(u8 a0, u32 a1, u32 a2) __attribute__((noreturn));
void func_0020ea48(u8 a0, u32 a1, u32 a2) {
    register u8* p asm("$14");
    register u8* q asm("$15");
    p = (u8*)0x00360000;
    p[-28336] = a0;
    __asm__ volatile("addiu %0,%1,-28336" : "=r"(q) : "r"(p));
    __asm__ volatile("" : "+r"(a1), "+r"(a2) : "r"(q));
    u32 m1 = a1 & 0xffu;
    __asm__ volatile("" : "+r"(m1));
    u32 m2 = a2 & 0xffu;
    __asm__ volatile(".set noreorder\n\tsb %0,2(%1)\n\tjr $31\n\tsb %2,1(%1)\n\t.set reorder" : : "r"(m2), "r"(q), "r"(m1) : "memory");
}

// FUN_0020eac0 (48 bytes)
// Code: writes 0x70004000 to 0x00359810 and 0x70000000 to 0x00359788, then zero to 0x00359808
// and 0x00359780. The base registers are rebuilt with lui before the second pair of stores,
// as the original does. The last zero store sits in the jr delay slot.
// Guess: resets four state words in an init step. The values 0x70000000 and 0x70004000 look
// like flags or addresses, but this is not confirmed.
void func_0020eac0(void) __attribute__((noreturn));
void func_0020eac0(void) {
    register u32 v5 asm("$13");
    register u32 v4 asm("$12");
    register u32* a asm("$14");
    register u32* b asm("$15");
    __asm__ volatile("lui %0,0x7000" : "=r"(v5) : : "memory");
    __asm__ volatile("lui %0,0x36" : "=r"(b) : : "memory");
    __asm__ volatile("lui %0,0x36" : "=r"(a) : : "memory");
    __asm__ volatile("ori %0,%0,0x4000" : "+r"(v5) : : "memory");
    __asm__ volatile("lui %0,0x7000" : "=r"(v4) : : "memory");
    a[-6652] = v5;
    b[-6686] = v4;
    __asm__ volatile("lui %0,0x36" : "=r"(a) : : "memory");
    __asm__ volatile("lui %0,0x36" : "=r"(b) : : "memory");
    __asm__ volatile(".set noreorder\n\tsw $0,-26616(%0)\n\tjr $31\n\tsw $0,-26752(%1)\n\t.set reorder" : : "r"(a), "r"(b) : "memory");
}

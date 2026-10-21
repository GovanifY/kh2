#include "../common/types.h"

// Table bases used by the two list-insert functions below. The lui/addiu pair is
// written as inline asm so the %hi/%lo halves land in the same order as the original.
extern u8 D_01dac450[];
extern u8 D_01dad550[];

// FUN_0020b410 (68 bytes)
// Code: VU0 pseudo-random number. Sets t0 = -1 and moves it into vf2 (qmtc2). Runs five
// vrxor/vrnext.x pairs to advance the VU R register and produce a value in vf1.
// Converts vf2 to float (vitof0.x), adds it into vf1 (vadd.x), moves the result bits to
// t7 (qmfc2) and returns them as a float in $f0 (mtc1 in the jr delay slot).
// Guess: returns a random float in the -1 seed pattern, used by a random-number helper.
// Build: the instruction words are identical to func_00207260, so this body is copied
// from that matched sibling and only the name differs.
f32 func_0020b410(u32 a0) {
    register u32 r asm("$15");
    __asm__ volatile(
        "addi $8,$0,-1\n\t"
        ".word 0x48a81000\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4b02113c\n\t"
        ".word 0x4b020868\n\t"
        ".word 0x482f0800\n\t"
        : "=r"(r)
        :
        : "$8");
    union {
        u32 u;
        f32 f;
    } x;
    x.u = r;
    return x.f;
}

// FUN_0020e7a8 (84 bytes)
// Code: clears the 16-byte node at a0 (sq $0), stores the word ((a1 - 1) | 0x20000000)
// at +0, clamps a2 to 0..15, and picks the table entry at D_01dac450 + (a2 * 16). It
// then links the node into the list whose head is the word at entry+8: the old head's
// +4 word is saved, the head's +4 is set to the node, the node's +4 takes the saved
// word, and the entry's head becomes the node.
// Guess: inserts a 16-byte record into one of 16 per-slot linked lists in an EE RAM
// table (the clamped a2 is the slot), tagging it with a value derived from a1.
// Build: the sq/lw/sw order and the lui/addiu pair come from inline asm barriers; the
// final store plus jr and nop are one noreorder asm block so the nop fills the delay
// slot. gcc then appends an epilogue after the registered 84 bytes, which the layout
// ignores (same as agent_r1). The noreturn prototype stops gcc from treating the asm as a normal return.
void func_0020e7a8(u32* a0, s32 a1, s32 a2) __attribute__((noreturn));
void func_0020e7a8(u32* a0, s32 a1, s32 a2) {
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
    __asm__ volatile("lui %0,%%hi(D_01dac450)" : "=r"(e));
    if (!c) a2 = 0;
    __asm__ volatile("addiu %0,%0,%%lo(D_01dac450)" : "+r"(e));
    a2 = (a2 < 16) ? a2 : 15;
    a2 = a2 << 4;
    __asm__ volatile("addu %0,%1,%0" : "+r"(e) : "r"(a2));
    h = (u32*)e[2];
    n = h[1];
    h[1] = (u32)a0;
    a0[1] = n;
    __asm__ volatile(".set noreorder\n\tsw %0,8(%1)\n\tjr $31\n\tnop\n\t.set reorder" : : "r"(a0), "r"(e) : "memory");
}

// FUN_0020e800 (84 bytes)
// Code: identical to FUN_0020e7a8 except the table base is D_01dad550 (the second
// table, 0x10 bytes per slot, starting at 0x01DAD550).
// Guess: the same slot-list insert for a second table of records.
void func_0020e800(u32* a0, s32 a1, s32 a2) __attribute__((noreturn));
void func_0020e800(u32* a0, s32 a1, s32 a2) {
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
    __asm__ volatile("lui %0,%%hi(D_01dad550)" : "=r"(e));
    if (!c) a2 = 0;
    __asm__ volatile("addiu %0,%0,%%lo(D_01dad550)" : "+r"(e));
    a2 = (a2 < 16) ? a2 : 15;
    a2 = a2 << 4;
    __asm__ volatile("addu %0,%1,%0" : "+r"(e) : "r"(a2));
    h = (u32*)e[2];
    n = h[1];
    h[1] = (u32)a0;
    a0[1] = n;
    __asm__ volatile(".set noreorder\n\tsw %0,8(%1)\n\tjr $31\n\tnop\n\t.set reorder" : : "r"(a0), "r"(e) : "memory");
}

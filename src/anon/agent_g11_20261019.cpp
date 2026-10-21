#include "../common/types.h"

extern u8 D_004f0000[];

// FUN_0016c750 (28 bytes)
// Code: stores arg0 at D_004f0000+25224, then zeroes the words at +25232 and +25236.
// Guess: resets a two-word slot in a global block and records a value next to it.
// Layout: two lui's (one per base, as in the original) and an addiu that makes the
// +25232 base. Each lui/addiu is an asm block with a paired %hi/%lo reloc (no
// empty asm barriers needed). The addiu is fenced with a "+r" barrier so it is emitted
// before the first store, as in the original.
void func_0016c750(u32 a0) {
    register u8* t5 asm("$13");
    register u8* t7 asm("$15");
    register u8* t6 asm("$14");
    __asm__ volatile("lui %0,%%hi(D_004f0000+25232)" : "=r"(t5));
    __asm__ volatile("lui %0,%%hi(D_004f0000+25224)" : "=r"(t7));
    __asm__ volatile("addiu %0,%1,%%lo(D_004f0000+25232)" : "=r"(t6) : "r"(t5));
    *(volatile u32*)(t7 + 25224) = a0;
    *(volatile u32*)(t6 + 4) = 0;
    *(volatile u32*)(t5 + 25232) = 0;
}

// FUN_00177a38 (32 bytes)
// Code: n = byte at +2820 of arg0. Stores n+1 back there, but only when (n & 0xff) < 100.
// Guess: a bounded counter byte (increments up to 100 and saturates).
// Layout: the "+r" barrier on the loaded byte keeps the andi, and the store sits in the
// bnezl delay slot. Not-taken path skips the store.
void func_00177a38(u8* a0) {
    u32 v = a0[2820];
    u32 n = v + 1;
    __asm__("" : "+r"(v));
    u32 m = v & 0xff;
    if (m < 100)
        a0[2820] = n;
}

// FUN_0017fdf8 (20 bytes)
// Code: a0 += 160; vf1 = vf0 - vf0 (zero vector); store vf1 as a quadword at a0.
// Guess: zeroes the 16-byte vector at +160 of an object.
// Layout: same VU0 zeroing as agent_h5 (vsub.wxyz then sqc2); the pointer add is
// folded into the asm operand, so GCC emits addiu a0,a0,160 itself.
void func_0017fdf8(u8* a0) {
    u8* p = a0 + 160;
    __asm__ volatile(".set noreorder\n\tvsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)\n\t.set reorder" : : "r"(p) : "memory");
}

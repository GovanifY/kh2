#include "../common/types.h"

// FUN_001a8bf8 (20 bytes)
// Code: returns the byte at a0+a1, masked to its low five bits.
// Guess: a bit-field read from a byte table entry.
// Build: plain C. The u8 local masks with andi 0x1f, and the u8 return adds the
//        andi 0xff in the jr delay slot, which is the shape in the original.
u32 func_001a8bf8(u32 a0, u32 a1) {
    u8 v = *(u8*)(a0 + a1) & 0x1f;
    return v;
}

// FUN_001a9110 (32 bytes)
// Code: copies the 4-byte word at a0 (unaligned) to D_01c6cc48 (unaligned store).
// Guess: copies a small unaligned header into a global buffer.
// Build: one asm block with the original's order. The lui/addiu pair uses %hi/%lo
//        relocations (addiu from t7 into t6), then lwl/lwr load and swl/swr store,
//        using t3 as the temp. C always emits lwr before lwl, so it stays in asm.
//        The .set noreorder keeps the assembler from moving swr into the jr delay slot.
void func_001a9110(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "lui $15,%%hi(D_01c6cc48)\n\t"
        "addiu $14,$15,%%lo(D_01c6cc48)\n\t"
        "lwl $11,3(%0)\n\t"
        "lwr $11,0(%0)\n\t"
        "swl $11,3($14)\n\t"
        "swr $11,0($14)\n\t"
        ".set reorder"
        : : "r"(a0) : "$11", "$14", "$15", "memory");
}

// FUN_001a91f8 (28 bytes)
// Code: sets word 0 to -1 and words 1, 3, 4, 5 to zero. The store order is 5, 0, 1, 3, 4
//       with the -1 constant loaded first.
// Guess: initializes a sentinel record (first word -1, rest zero).
// Build: the -1 is pinned to t7 and computed before the stores by an empty "+r" asm.
//        A memory barrier after each store keeps the original order.
void func_001a91f8(u32* a0) {
    register u32 m asm("$15");
    m = 0xFFFFFFFFu;
    __asm__ volatile("" : "+r"(m));
    a0[5] = 0; __asm__ volatile("" ::: "memory");
    a0[0] = m; __asm__ volatile("" ::: "memory");
    a0[1] = 0; __asm__ volatile("" ::: "memory");
    a0[3] = 0; __asm__ volatile("" ::: "memory");
    a0[4] = 0;
}

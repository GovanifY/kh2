#include "../common/types.h"

// Agent S28 (2026-10-21): two of the three functions from SLPM_666.75, decompiled byte-exact.
// FUN_00146ed8 is not included (see the report).

extern "C" u32 func_001652c8(u32, u32, u32, u32, u32, u32, u32, u32);
extern "C" u32 func_00143b88(u32, u32, u32*, u32*, u32);
extern u8 D_00350000[];
typedef int u128 __attribute__((mode(TI)));

// FUN_00143470 (92 bytes; this object is built with -falign-functions=1, because the size is not a
// multiple of 8 and the default alignment adds a trailing nop).
// Code: a wrapper that shifts the arguments by one and prepends a global. It loads the word at
// D_00350000 - 30716 and calls FUN_001652c8 with (word, a0, a1, a2, a3, a4, a5, a6), then returns
// the callee's result unchanged. The original saves s0 and ra, because s0 is a temporary.
// Guess: a "prepend the current context and forward" helper for an 8-argument function.
// Tricks: the whole body is one noreorder asm block, so the argument moves and saves come out in
// the original order (C could not reproduce that interleaving). The frame is made by gcc: an unused
// 16-byte local plus a trailing empty asm that writes it, which gives addiu sp,-16 and the epilogue.
// The result is returned through a $2-pinned output operand so no move is added.
u32 func_00143470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    register u32 r asm("$2");
    u128 tmp;
    asm volatile(
        ".set noreorder\n\t"
        "move $14,$4\n\t"
        "sd $16,0($29)\n\t"
        "lui $15,%%hi(D_00350000-30716)\n\t"
        "move $13,$5\n\t"
        "sd $31,8($29)\n\t"
        "move $12,$6\n\t"
        "lw $4,%%lo(D_00350000-30716)($15)\n\t"
        "move $3,$7\n\t"
        "move $2,$8\n\t"
        "move $16,$9\n\t"
        "move $11,$10\n\t"
        "move $10,$16\n\t"
        "move $5,$14\n\t"
        "move $6,$13\n\t"
        "move $7,$12\n\t"
        "move $8,$3\n\t"
        "jal func_001652c8\n\t"
        "move $9,$2\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        ".set reorder"
        : "=m"(tmp), "=r"(r) : : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    return r;
}

// FUN_00143b60 (40 bytes)
// Code: allocates a 32-byte frame, sets a 4-byte local at sp+4 to zero, and calls FUN_00143b88 with
// (a0, a1, &local at sp+0, &local at sp+4, a2). It returns the callee's result.
// Guess: a "call with two out-parameters" wrapper; the first out-parameter is left unset.
// Tricks: the first local's address is fixed early with a "+r" barrier, the store is fenced with an
// empty memory barrier, and the second address is formed last so it lands in the jal delay slot.
u32 func_00143b60(u32 a0, u32 a1, u32 a2) {
    u32 buf[4];
    u32* p0 = &buf[0];
    u32* p1;
    asm volatile("" : "+r"(p0));
    buf[1] = 0;
    asm volatile("" ::: "memory");
    p1 = &buf[1];
    return func_00143b88(a0, a1, p0, p1, a2);
}

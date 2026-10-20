#include "../common/types.h"

// FUN_0016ffc8 (80 bytes)
// Code: t = word at +40 of a0. If t >= 0 return t. If the byte at +0 is nonzero return t.
//       Otherwise x = word at +56: return x if x-2300 (unsigned) < 100, or x-2410 < 10, or
//       x-2420 < 10 (checked in that order); else return t.
// Guess: picks a value from a record field (+40 or +56) according to a range check on an id.
// Note: the tail (from the load of +56 onwards) is a noreorder asm block. The `beqzl` (branch
//       likely) with the `move v0,t5` in its delay slot can't be produced from C here: every
//       plain-C shape tried (goto chains, barriers on the flag or result, pinned temps) gets a
//       movz or a plain bnez instead.
s32 func_0016ffc8(u8* a0) {
    register s32 t5 asm("$13") = *(s32*)(a0 + 40);
    if (t5 >= 0) return t5;
    if (a0[0] != 0) return t5;
    register u8* A0 asm("$4") = a0;
    register s32 R asm("$2");
    __asm__ volatile(
        ".set noreorder\n"
        "lw $4,56($4)\n"
        "addiu $15,$4,-2300\n"
        "addiu $14,$4,-2410\n"
        "sltiu $15,$15,100\n"
        "move $2,$4\n"
        "bnez $15,9f\n"
        "sltiu $14,$14,10\n"
        "bnez $14,9f\n"
        "addiu $15,$4,-2420\n"
        "sltiu $15,$15,10\n"
        "beqzl $15,9f\n"
        "move $2,$13\n"
        "9:\n"
        ".set reorder\n"
        : "=r"(R), "+r"(A0)
        : "r"(t5)
        : "$14", "$15", "memory");
    return R;
}

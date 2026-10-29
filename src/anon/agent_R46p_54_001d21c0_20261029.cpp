#include "../common/types.h"

// FUN_001d21c0 (80 bytes), whole-body asm.
// Float compare on this+60 against the constant at 0x349e10 (lui 0x35 / lwc1 -25072).
// Returns 1 unless 0 < v; stores v - C back to this+60; returns 1 if the result is > 0,
// else calls FUN_001d2180 (numeric jal) and returns 0.
// Matching: plain C puts mtc1 zero after sd ra (or hoists it above addiu); the original
// order is addiu, mtc1, sd ra, lwc1, so the body is one noreorder asm block with the
// out-of-line return-1 block (b + li in delay slot) placed after the shared epilogue.
void func_001d21c0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "mtc1 $0,$f2\n\t"
        "sd $31,0($29)\n\t"
        "lwc1 $f1,60($4)\n\t"
        "c.lt.s $f2,$f1\n\t"
        "bc1f 1f\n\t"
        " lui $15,0x35\n\t"
        "lwc1 $f0,-25072($15)\n\t"
        "sub.s $f0,$f1,$f0\n\t"
        "c.le.s $f0,$f2\n\t"
        "bc1f 1f\n\t"
        " swc1 $f0,60($4)\n\t"
        "jal 0x1d2180\n\t"
        " nop\n\t"
        "daddu $2,$0,$0\n\t"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "b 2b\n\t"
        " addiu $2,$0,1\n\t"
        ".set reorder"
        ::: "memory");
}

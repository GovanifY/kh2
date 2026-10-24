#include "../common/types.h"

// Agent R46e_a (2026-10-23): FUN_001535b0 (64 bytes), SLPM_666.75.
// Code: a1 = a1 * 24 (record index), a0 += 32. Loads the record fields at +20..+23 of the table at
// D_0034a778 + a1 * 24 (the table base is read from a word at 0x350000 - 22664), then tail-jumps to
// FUN_00153540(a0 + 32, field +20, field +21, field +22, field +23 in t0).
// Matching: the whole function is one noreorder asm block with no C locals and no calls the compiler
// knows about, so gcc emits no prologue. The asm writes the original 16 words in the original order,
// including the spill and reload of ra in the 16-byte frame. R5900 forms that gas may not accept
// (3-operand mult, daddu moves) are written as .word, with the original encodings.
// The 8 bytes of gcc's trailing jr ra; nop fall past the 64-byte boundary.
// The symbol is bound with an asm label so the source lookup finds this file.

void r_FUN_001535b0(void) asm("func_001535b0");

void r_FUN_001535b0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $15,$0,24\n\t"
        "lui $14,0x35\n\t"
        ".word 0x00af2818\n\t"          /* mult $5,$5,$15 */
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "addiu $4,$4,32\n\t"
        "ld $31,0($29)\n\t"
        "lw $15,-22664($14)\n\t"
        "addu $5,$5,$15\n\t"
        "lbu $8,23($5)\n\t"
        "lbu $15,20($5)\n\t"
        "lbu $6,21($5)\n\t"
        "lbu $7,22($5)\n\t"
        ".word 0x01e0282d\n\t"          /* daddu $5,$15,$0 */
        ".word 0x08054d50\n\t"          /* j 0x153540 */
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

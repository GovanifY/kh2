#include "../common/types.h"

// Agent R46p_75 (2026-10-29): FUN_002007e0 (76 bytes), SLPM_666.75.
// Same body as FUN_002006b0 (the bytes are identical; the two copies differ only in address).
// Matching: whole-body asm with numeric jal targets, because the callee at 0x2f3f88 has no row.
void func_002007e0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,8($29)\n\t"
        "sd $16,0($29)\n\t"
        "lw $15,12($5)\n\t"
        "lw $14,4($15)\n\t"
        "lui $5,0x35\n\t"
        "addiu $5,$5,19392\n\t"
        "addu $16,$4,$14\n\t"
        "jal 0x2f3f88\n\t"
        "addiu $4,$16,160\n\t"
        "addiu $16,$16,176\n\t"
        "lui $5,0x35\n\t"
        "daddu $4,$16,$0\n\t"
        "jal 0x2f3f88\n\t"
        "addiu $5,$5,19424\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

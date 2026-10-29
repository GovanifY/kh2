#include "../common/types.h"

// Agent R46p_28 (2026-10-29): FUN_001ac1d0 (52 bytes, SLPM_666.75).
// Returns 0 unless the byte at a0 is non-zero; then calls the method at 0x239d10 with a0+4 and
// returns (v0 != 0) from the call's result.
// Matching: whole-body asm (form a). Numeric jal target. Needs -falign-functions=1 (52 bytes).

void func_001ac1d0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $14,$4,4\n\t"
        "sd $31,0($29)\n\t"
        "daddu $2,$0,$0\n\t"
        "lbu $15,0($4)\n\t"
        "beqz $15,1f\n\t"
        " daddu $4,$14,$0\n\t"
        "jal 0x239d10\n\t"
        "nop\n\t"
        "sltu $2,$0,$2\n"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

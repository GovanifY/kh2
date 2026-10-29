#include "../common/types.h"

// Agent R46p_104 (2026-10-29): FUN_0027f2b0 (72 bytes, SLPM_666.75).
// Whole-body asm (form a). Three-step chain: calls 0x139d78 with a0 = word at 0x36xxxx-3504, then 0x139d78 with
// a0 = word at 0x36xxxx-3496 (both return early if v0 != 0), then 0x28acc8 with a0 = word at 0x36xxxx-3500.
// The early-return paths share one jr ra. Bnez delay slots hold the ld ra, as in the original.
void func_0027f2b0(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "lui $15,0x36\n"
        "sd $31,0($29)\n"
        "jal 0x139d78\n"
        "lw $4,-3504($15)\n"
        "bnez $2,1f\n"
        "ld $31,0($29)\n"
        "lui $15,0x36\n"
        "jal 0x139d78\n"
        "lw $4,-3496($15)\n"
        "bnez $2,1f\n"
        "ld $31,0($29)\n"
        "lui $15,0x36\n"
        "jal 0x28acc8\n"
        "lw $4,-3500($15)\n"
        "ld $31,0($29)\n"
        "1:\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set pop\n"
        :
        :
        : "memory");
}

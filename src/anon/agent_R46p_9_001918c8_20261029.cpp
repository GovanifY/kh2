#include "../common/types.h"

// Agent R46p_9 (2026-10-29): func_001918c8 (108 bytes), SLPM_666.75.
// Calls func_0019ba60(word at 0x34e948). If it is zero, clears the word at 0x1c6960 and returns 0.
// Otherwise calls func_001b58a8(); a nonzero result returns 0. If not, returns 1 when the word at
// 0x34f240 has bit 0x10000 set; else returns (func_001a6850() != 0).
// Plain C gave a different frame and return shape (the original shares one return tail and
// fills delay slots), so this is form (b): whole-body asm with the original sequence.
// The jal targets are numeric.
void r_FUN_001918c8(void) asm("func_001918c8");
#if 0
void r_FUN_001918c8(void) {
}
#endif

__asm__(
    ".section .text.func_001918c8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001918c8\n"
    ".type func_001918c8, @function\n"
    "func_001918c8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "jal 0x19ba60\n"
    "lw $4,-5816($15)\n"
    "bnez $2,4f\n"
    "daddu $13,$0,$0\n"
    "lui $15,0x1c6\n"
    "sw $0,6496($15)\n"
    "5: ld $31,0($29)\n"
    "6: daddu $2,$13,$0\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "4: jal 0x1b58a8\n"
    "nop\n"
    "bnez $2,5b\n"
    "addiu $13,$0,1\n"
    "lui $15,0x35\n"
    "lw $14,-3520($15)\n"
    "lui $15,1\n"
    "and $14,$14,$15\n"
    "bnez $14,6b\n"
    "ld $31,0($29)\n"
    "jal 0x1a6850\n"
    "nop\n"
    "b 5b\n"
    "sltu $13,$0,$2\n"
    ".set pop\n"
    ".size func_001918c8, .-func_001918c8\n"
    ".text\n");

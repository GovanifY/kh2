#include "../common/types.h"

// FUN_001d8898 (108 bytes, SLPM_666.75). Whole-body noreorder asm (form b): the code
// uses beqz/jal delay-slot shapes and a raw R5900 3-operand mult (encoded as .word).
// Calls FUN_001bb4a0(a0), then if the result is nonzero calls FUN_001bbcb0 and reads
// the byte at offset 244 of the table indexed by s0 * 56, returning a flag test result.
u32 r_FUN_001d8898(void) asm("func_001d8898");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_001d8898(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_001d8898,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d8898\n"
    ".type func_001d8898, @function\n"
    "func_001d8898:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "jal 0x1bb4a0\n"
    "daddu $16,$4,$0\n"
    "beq $2,$0,1f\n"
    "daddu $2,$0,$0\n"
    "jal 0x1bbcb0\n"
    "nop\n"
    "addiu $15,$0,56\n"
    ".word 0x020f8018\n"
    "addu $2,$2,$16\n"
    "lw $15,244($2)\n"
    "andi $15,$15,1\n"
    "andi $15,$15,0xff\n"
    "beq $15,$0,1f\n"
    "daddu $2,$0,$0\n"
    "jal 0x1bbcb0\n"
    "nop\n"
    "addu $2,$2,$16\n"
    "lw $15,244($2)\n"
    "andi $15,$15,8\n"
    "sltu $2,$0,$15\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d8898, .-func_001d8898\n"
    ".text\n");

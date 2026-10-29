#include "../common/types.h"

// Agent R46p_71 (2026-10-29): FUN_001dbad0 (104 bytes), SLPM_666.75.
// Code: frame of 32 bytes. Saves s0, s1, ra; s0 = 0x350000; s1 = a0.
// Calls numeric 0x19ba60(word at 0x350000 - 5816) (mangled ctarget row, no name link).
// If it returns zero, skips to the 0x1dbcd0 call. Otherwise calls 0x16c028(same word) and,
// if the result is not the address at 0x350000 + 10848, copies 16 bytes from v0 to that address.
// Then calls numeric 0x1dbcd0, passes a0 = s1 and tail-jumps to 0x1c2578 (numeric j, no row).
// Matching: whole-body asm (form b). Numeric jal/j targets and local labels for the branches.
void r_FUN_001dbad0(void) asm("func_001dbad0");
#if 0
void r_FUN_001dbad0(void) {
}
#endif

__asm__(
    ".section .text.func_001dbad0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dbad0\n"
    ".type func_001dbad0, @function\n"
    "func_001dbad0:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "lui $16,0x35\n"
    "daddu $17,$4,$0\n"
    "jal 0x19ba60\n"
    "lw $4,-5816($16)\n"
    "beqz $2,1f\n"
    "nop\n"
    "jal 0x16c028\n"
    "lw $4,-5816($16)\n"
    "lui $15,0x35\n"
    "addiu $15,$15,10848\n"
    "beq $2,$15,1f\n"
    "nop\n"
    "lq $8,0($2)\n"
    "sq $8,0($15)\n"
    "1:\n"
    "jal 0x1dbcd0\n"
    "nop\n"
    "daddu $4,$17,$0\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "j 0x1c2578\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001dbad0, .-func_001dbad0\n"
    ".text\n");

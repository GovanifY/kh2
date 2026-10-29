#include "../common/types.h"

// Agent R46p_44 (2026-10-29): FUN_001c1060 (88 bytes, SLPM_666.75).
// Whole-body asm (form b). Plain C gave the branch the opposite sense (beqz to the return), a move v0,zero
// that the original does not have, and a different block order.
// Code: s = 0; loop { s = ctarget(s) (mangled, 001b9bc8, numeric jal); if s != 0 goto body; return 0;
// body: if is_attach(s) (001c0cd8, numeric jal) == 0 goto loop; detach(s) (001c0e60, numeric jal); goto loop }.
void func_001c1060(void) asm("func_001c1060");
#if 0
void func_001c1060(void) {
}
#endif

__asm__(
    ".section .text.func_001c1060,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001c1060\n"
    ".type func_001c1060, @function\n"
    "func_001c1060:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$0,$0\n"
    "1:\n"
    "jal 0x1b9bc8\n"
    "daddu $4,$16,$0\n"
    "daddu $16,$2,$0\n"
    "bnez $2,2f\n"
    "daddu $4,$2,$0\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    "nop\n"
    "2:\n"
    "jal 0x1c0cd8\n"
    "nop\n"
    "beqz $2,1b\n"
    "daddu $4,$16,$0\n"
    "jal 0x1c0e60\n"
    "nop\n"
    "b 1b\n"
    "nop\n"
    ".set pop\n"
    ".size func_001c1060, .-func_001c1060\n"
);

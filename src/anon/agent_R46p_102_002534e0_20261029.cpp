#include "../common/types.h"

// Agent R46p_102: func_002534e0 (88 bytes), SLPM_666.75.
// Calls 0x27dc08, then 0x103550 (result kept in s0 through the delay slot of the 0x103b38 call),
// then 0x103b38. If that result is zero it jumps to a tail call of 0x253180 with a0 = 14 and
// a1 = -1; otherwise it returns when s0 == 50, or tail-calls 0x253180 the same way.
// Whole-body asm (form b): the epilogue restores interleave with the tail jump.
void r_FUN_002534e0(void) asm("func_002534e0");
#if 0
void r_FUN_002534e0(void) {
}
#endif

__asm__(
    ".section .text.func_002534e0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002534e0\n"
    ".type func_002534e0, @function\n"
    "func_002534e0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "jal 0x27dc08\n"
    "nop\n"
    "jal 0x103550\n"
    "nop\n"
    "jal 0x103b38\n"
    "daddu $16,$2,$0\n"
    "addiu $4,$0,14\n"
    "beq $2,$0,3f\n"
    "addiu $5,$0,-1\n"
    "addiu $15,$0,50\n"
    "beq $16,$15,4f\n"
    "ld $16,0($29)\n"
    "3: ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "j 0x253180\n"
    "addiu $29,$29,16\n"
    "4: ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002534e0, .-func_002534e0\n"
    ".text\n");

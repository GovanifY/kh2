#include "../common/types.h"

// Agent R46j_1 (2026-10-23): FUN_0016f9e8 (108 bytes), SLPM_666.75.
// Loops forever. Each pass calls FUN_003058a0(0), then while the byte at 0x34dcac is 1 it calls
// FUN_001707d8 and clears the byte, then calls FUN_0014d430 and repeats.
// Top-level asm so gcc emits no prologue or epilogue. The body is the original sequence.
u32 r_FUN_0016f9e8(void) asm("func_0016f9e8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_0016f9e8(void) {
}
#endif

__asm__(
    ".section .text.func_0016f9e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0016f9e8\n"
    ".type func_0016f9e8, @function\n"
    "func_0016f9e8:\n"
    "addiu $29,$29,-48\n"
    "sd $18,16($29)\n"
    "sd $19,24($29)\n"
    "sd $16,0($29)\n"
    "li $18,1\n"
    "sd $17,8($29)\n"
    "lui $19,0x35\n"
    "sd $31,32($29)\n"
    "1: jal func_003058a0\n"
    " move $4,$0\n"
    "lbu $15,-9044($19)\n"
    "andi $15,$15,0xff\n"
    "bne $15,$18,3f\n"
    " nop\n"
    "lui $16,0x35\n"
    "li $17,1\n"
    "2: jal func_001707d8\n"
    " nop\n"
    "sb $0,-9044($16)\n"
    "lbu $15,-9044($16)\n"
    "andi $15,$15,0xff\n"
    "beq $15,$17,2b\n"
    " nop\n"
    "3: jal func_0014d430\n"
    " nop\n"
    "b 1b\n"
    " nop\n"
    ".set pop\n"
    ".size func_0016f9e8, .-func_0016f9e8\n"
    ".text\n");

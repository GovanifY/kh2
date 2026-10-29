#include "../common/types.h"

// Agent R46p_92 (2026-10-29): FUN_002349e8 (68 bytes, SLPM_666.75).
// Clears the word at 0x35e370, copies the word at 0x1dae424 to 0x1dae428 (the table at 0x1dae420),
// then calls the function pointer at 0x1dae41c (if set) with the word at 0x35e36c.
// Matching: the original uses an explicit lui/addiu pair for the 0x1db table base and a jalr tail, so
// the whole body is one file-scope asm block with the original instruction order.
void r_FUN_002349e8(void) asm("func_002349e8");
#if 0
void r_FUN_002349e8(void) {
}
#endif

__asm__(
    ".section .text.func_002349e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002349e8\n"
    ".type func_002349e8, @function\n"
    "func_002349e8:\n"
    "addiu $29,$29,-16\n"
    "lui $14,0x36\n"
    "sd $31,0($29)\n"
    "lui $15,0x1db\n"
    "addiu $15,$15,-7136\n"
    "sw $0,-7312($14)\n"
    "lw $13,4($15)\n"
    "lui $14,0x1db\n"
    "sw $13,8($15)\n"
    "lw $14,-7140($14)\n"
    "beq $14,$0,agent_R46p_92_002349e8_L38\n"
    "lui $15,0x36\n"
    "jalr $14\n"
    "lw $4,-7316($15)\n"
    "agent_R46p_92_002349e8_L38:\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002349e8, .-func_002349e8\n"
    ".text\n");

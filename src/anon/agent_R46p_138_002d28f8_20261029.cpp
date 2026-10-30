#include "../common/types.h"

// FUN_002d28f8 (80 bytes): copies the 3 words at 0x375a40 into a 12-byte frame local, then calls
// YS::MISSION::AddCount-named function 0x1d86a0 with (local[idx] * arg1, 0, &local[idx]) and
// returns its result. Matching: the whole function is one file-scope __asm__ block.
void r_FUN_002d28f8(void) asm("func_002d28f8");
#if 0
void r_FUN_002d28f8(void) {
}
#endif

__asm__(
    ".section .text.func_002d28f8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002d28f8\n"
    ".type func_002d28f8, @function\n"
    "func_002d28f8:\n"
    "addiu $29,$29,-32\n"
    "lui $15,0x37\n"
    "sd $31,16($29)\n"
    "addiu $14,$15,23104\n"
    "sll $6,$6,2\n"
    "lw $13,23104($15)\n"
    "addu $6,$6,$29\n"
    "lw $12,8($14)\n"
    "lw $15,4($14)\n"
    "sw $13,0($29)\n"
    "sw $15,4($29)\n"
    "daddu $14,$5,$0\n"
    "sw $12,8($29)\n"
    "daddu $5,$0,$0\n"
    "lw $4,0($6)\n"
    "jal _ZN2YS7MISSION8AddCountEii\n"
    "mult $4,$4,$14\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002d28f8, .-func_002d28f8\n"
    ".text\n");

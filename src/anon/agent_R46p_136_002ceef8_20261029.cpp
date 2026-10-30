#include "../common/types.h"

// Agent R46p_136: FUN_002ceef8 (92 bytes). Whole-body asm: copies six words from arg1+1856 to a stack box
// and returns FUN_002cec08(global, box) != 0.
s32 r_FUN_002ceef8(void* a0, u8* a1) asm("func_002ceef8");
#if 0
s32 r_FUN_002ceef8(void* a0, u8* a1) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002ceef8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002ceef8\n"
    ".type func_002ceef8, @function\n"
    "func_002ceef8:\n"
    "addiu $29,$29,-48\n"
    "addiu $14,$5,1856\n"
    "sd $31,32($29)\n"
    "lui $15,0x36\n"
    "lw $4,8032($15)\n"
    "lw $9,1856($5)\n"
    "lw $8,20($14)\n"
    "lw $13,4($14)\n"
    "daddu $5,$29,$0\n"
    "lw $12,8($14)\n"
    "lw $11,12($14)\n"
    "lw $10,16($14)\n"
    "sw $9,0($29)\n"
    "sw $13,4($29)\n"
    "sw $12,8($29)\n"
    "sw $11,12($29)\n"
    "sw $10,16($29)\n"
    "jal 0x2cec08\n"
    "sw $8,20($29)\n"
    "ld $31,32($29)\n"
    "sltu $2,$0,$2\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_002ceef8, .-func_002ceef8\n"
);

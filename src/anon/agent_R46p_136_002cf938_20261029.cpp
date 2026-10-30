#include "../common/types.h"

// Agent R46p_136: FUN_002cf938 (96 bytes). Whole-body asm: if (a0 & 0xff) and the table at +8100 is set,
// zeroes the first word of each 40-byte record (count at +8096). Tail-jumps to func_00182f38.
u32 r_FUN_002cf938(u32 a0) asm("func_002cf938");
#if 0
u32 r_FUN_002cf938(u32 a0) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002cf938,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002cf938\n"
    ".type func_002cf938, @function\n"
    "func_002cf938:\n"
    "addiu $29,$29,-16\n"
    "andi $4,$4,0xff\n"
    "sd $31,0($29)\n"
    "beqz $4,1f\n"
    "lui $14,0x36\n"
    "lw $15,8100($14)\n"
    "beqz $15,1f\n"
    "lui $11,0x36\n"
    "lw $15,8096($11)\n"
    "blez $15,1f\n"
    "daddu $13,$0,$0\n"
    "daddu $12,$14,$0\n"
    "daddu $14,$0,$0\n"
    "2:\n"
    "lw $15,8100($12)\n"
    "addiu $13,$13,1\n"
    "addu $15,$14,$15\n"
    "sw $0,0($15)\n"
    "lw $15,8096($11)\n"
    "slt $15,$13,$15\n"
    "bnez $15,2b\n"
    "addiu $14,$14,40\n"
    "1:\n"
    "ld $31,0($29)\n"
    "j 0x182f38\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002cf938, .-func_002cf938\n"
);

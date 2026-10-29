#include "../common/types.h"

// FUN_002421e8 (80 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Calls numeric 0x2efa40 with a0->field4 (lw in the jal delay slot); returns 1 if that
// result is nonzero (bnezl), else returns 1 when the word at 0x35ecb8 has bit 0 set,
// else 0. Branch-likely and the lw/jal delay slot cannot come out of plain C.
u32 r_FUN_002421e8(void) asm("func_002421e8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_002421e8(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002421e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002421e8\n"
    ".type func_002421e8, @function\n"
    "func_002421e8:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$0,$0\n"
    "jal 0x2efa40\n"
    "lw $4,4($4)\n"
    "bnezl $2,1f\n"
    "addiu $16,$0,1\n"
    "lui $14,0x36\n"
    "lw $15,-4936($14)\n"
    "andi $15,$15,0x1\n"
    "andi $15,$15,0xff\n"
    "beqz $15,2f\n"
    "daddu $2,$16,$0\n"
    "addiu $16,$0,1\n"
    "1:\n"
    "daddu $2,$16,$0\n"
    "2:\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_002421e8, .-func_002421e8\n"
    ".text\n");

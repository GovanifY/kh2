#include "../common/types.h"

// FUN_00256a58 (68 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Calls numeric 0x28b040 with the word at 0x36 base -4068, then numeric 0x257fa8 with the
// result; scales the result by 36 (raw R5900 3-operand mult as .word 0x004e1018), adds
// the table base 0x370000+10792 and tail-jumps to 0x263a58 with a0 = lhu +20, a1 = 1.
u32 r_FUN_00256a58(void) asm("func_00256a58");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00256a58(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00256a58,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00256a58\n"
    ".type func_00256a58, @function\n"
    "func_00256a58:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x36\n"
    "sd $31,0($29)\n"
    "jal 0x28b040\n"
    "lw $4,-4068($15)\n"
    "jal 0x257fa8\n"
    "daddu $4,$2,$0\n"
    "addiu $14,$0,36\n"
    "ld $31,0($29)\n"
    ".word 0x004e1018\n"
    "lui $15,0x37\n"
    "addiu $15,$15,10792\n"
    "addiu $5,$0,1\n"
    "addu $2,$2,$15\n"
    "lhu $4,20($2)\n"
    "j 0x263a58\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00256a58, .-func_00256a58\n"
    ".text\n");

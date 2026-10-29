#include "../common/types.h"

// Agent R46p_115 (2026-10-29): FUN_002a7588 (56 bytes), SLPM_666.75.
// Frame of 144 bytes with ra at +128. name = func_002b64c8(); func_00253b30(buf = sp, name);
// func_00170518(sp, 5102, 0). Plain C put the a1 move before the a0 setup, so this is a
// whole-body noreorder asm with numeric jal targets, as in the original.

u32 r_FUN_002a7588(void) asm("func_002a7588");
#if 0
u32 r_FUN_002a7588(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_002a7588,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002a7588\n"
    ".type func_002a7588, @function\n"
    "func_002a7588:\n"
    "addiu $29,$29,-144\n"
    "sd $31,128($29)\n"
    "jal 0x2b64c8\n"
    "nop\n"
    "daddu $4,$29,$0\n"
    "jal 0x253b30\n"
    "daddu $5,$2,$0\n"
    "daddu $4,$29,$0\n"
    "addiu $5,$0,5102\n"
    "jal 0x170518\n"
    "daddu $6,$0,$0\n"
    "ld $31,128($29)\n"
    "jr $31\n"
    "addiu $29,$29,144\n"
    ".set pop\n"
    ".size func_002a7588, .-func_002a7588\n"
    ".text\n");

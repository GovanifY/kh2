#include "../common/types.h"

// Agent R46p_99 (2026-10-29): func_0026ff30 (68 bytes), SLPM_666.75.
// Calls func_00287bc0() and stores its byte result at the byte 0x35f130, then clears the byte
// at 0x35f128. Calls func_00257388(0x846a), then func_002571e0(1). Tail-jumps to func_00287cc0(0)
// with the frame restored in the j delay slot.
// Callees have no function rows, so plain C would emit jalr. This is form (b): whole-body asm.
// The jal/j targets are numeric.
void r_FUN_0026ff30(void) asm("func_0026ff30");
#if 0
void r_FUN_0026ff30(void) {
}
#endif

__asm__(
    ".section .text.func_0026ff30,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0026ff30\n"
    ".type func_0026ff30, @function\n"
    "func_0026ff30:\n"
    "addiu $29,$29,-16\n"
    "sd $31,0($29)\n"
    "jal 0x287bc0\n"
    "nop\n"
    "lui $15,0x36\n"
    "lui $14,0x36\n"
    "sb $2,-3792($15)\n"
    "daddu $5,$0,$0\n"
    "sb $0,-3800($14)\n"
    "jal 0x257388\n"
    "ori $4,$0,0x846a\n"
    "jal 0x2571e0\n"
    "addiu $4,$0,1\n"
    "ld $31,0($29)\n"
    "daddu $4,$0,$0\n"
    "j 0x287cc0\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0026ff30, .-func_0026ff30\n"
    ".text\n");

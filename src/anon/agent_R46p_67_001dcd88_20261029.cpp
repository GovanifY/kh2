#include "../common/types.h"

// Asm label alias: registers func_001dcd88 with this file (no C definition is emitted).
void r_FUN_001dcd88(void) asm("func_001dcd88");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
void r_FUN_001dcd88(void) {
}
#endif

// FUN_001dcd88 (48 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Tail-calls 0x168388 with a0 = word at 0x352aec, a1 = 0x1d5bb40, a2 = 0x1dcd68, a3 = 0.
// The ld ra sits between the two lui/addiu argument setups, as in the original.
__asm__(
    ".section .text.func_001dcd88,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001dcd88\n"
    ".type func_001dcd88, @function\n"
    "func_001dcd88:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "lui $5,0x1d6\n"
    "lw $4,10988($15)\n"
    "lui $6,0x1e\n"
    "ld $31,0($29)\n"
    "addiu $5,$5,-17600\n"
    "addiu $6,$6,-12952\n"
    "daddu $7,$0,$0\n"
    "j 0x168388\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001dcd88, .-func_001dcd88\n"
    ".text\n");

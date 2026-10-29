#include "../common/types.h"

// Agent R46p_112 (2026-10-29): FUN_001cebb0 (88 bytes), form (b): top-level asm body. Calls AREA::Alloc(60),
// func_001ce8b8(result), stores the result at 0x3521d0, calls func_00102c18(1, 14001, 0x1cec08), stores 0x1cec18
// at +48 of the returned pointer, and returns it. Literal immediates and numeric jal targets keep the encoding
// identical to the original. Top-level asm avoids the trailing jr ra gcc appends to asm-only bodies.
u32 r_FUN_001cebb0(void) asm("func_001cebb0");
#if 0
u32 r_FUN_001cebb0(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_001cebb0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001cebb0\n"
    ".type func_001cebb0, @function\n"
    "func_001cebb0:\n"
    "addiu $29,$29,-16\n"
    "sd $31,8($29)\n"
    "sd $16,0($29)\n"
    "jal 0x1050d8\n"
    "li $4,60\n"
    "daddu $16,$2,$0\n"
    "jal 0x1ce8b8\n"
    "daddu $4,$2,$0\n"
    "lui $15,0x35\n"
    "lui $6,0x1d\n"
    "sw $16,8656($15)\n"
    "li $4,1\n"
    "addiu $6,$6,-5112\n"
    "jal 0x102c18\n"
    "li $5,14001\n"
    "lui $15,0x1d\n"
    "ld $16,0($29)\n"
    "addiu $15,$15,-5080\n"
    "ld $31,8($29)\n"
    "sw $15,48($2)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001cebb0, .-func_001cebb0\n"
    ".text\n");

#include "../common/types.h"

// Asm label alias: registers func_00102bd8 with this file (no C definition is emitted).
u32 r_FUN_00102bd8(void) asm("func_00102bd8");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00102bd8(void) {
    return 0;
}
#endif

// FUN_00102bd8 (60 bytes). Whole-body noreorder asm, top-level, so gcc emits no frame.
// Stores two words into the table at 0x0032B968 (+36, +32) and clears the word at 0x0032B994,
// then tail-calls FUN_00102b58 from the jump's delay slot. The dead ra spill is kept.
__asm__(
    ".section .text.func_00102bd8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00102bd8\n"
    ".type func_00102bd8, @function\n"
    "func_00102bd8:\n"
    "lui $13,0x33\n"
    "lui $15,0x10\n"
    "addiu $13,$13,-18072\n"
    "addiu $15,$15,11152\n"
    "lui $14,0x10\n"
    "sw $15,36($13)\n"
    "addiu $29,$29,-16\n"
    "addiu $14,$14,10864\n"
    "sd $31,0($29)\n"
    "lui $15,0x33\n"
    "sw $14,32($13)\n"
    "ld $31,0($29)\n"
    "sw $0,-18028($15)\n"
    "j func_00102b58\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00102bd8, .-func_00102bd8\n"
    ".text\n");

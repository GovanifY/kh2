#include "../common/types.h"

// Agent R46p_128 (2026-10-29): FUN_002bd7d8 (92 bytes), SLPM_666.75.
// Calls func_002b8a70(word at 0x003617ec), stores 0 to 0x003617ec, 0x003617f0 and 0x003617f4 and the byte at
// 0x003617f8, and calls func_00102670(word at 0x0032b91c, word at 0x003617f4) between the stores.
// Matching: whole-body asm (form b). Lui register choices and store order follow the original.
void r_FUN_002bd7d8(void) asm("func_002bd7d8");
#if 0
void r_FUN_002bd7d8(void) {
}
#endif

__asm__(
    ".section .text.func_002bd7d8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_002bd7d8\n"
    ".type func_002bd7d8, @function\n"
    "func_002bd7d8:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $31,16($29)\n"
    "lui $16,0x36\n"
    "sd $17,8($29)\n"
    "lw $4,6124($16)\n"
    "jal func_002b8a70\n"
    "lui $17,0x36\n"
    "lui $15,0x36\n"
    "lw $5,6132($17)\n"
    "lui $14,0x33\n"
    "sw $0,6124($16)\n"
    "sw $0,6128($15)\n"
    "jal func_00102670\n"
    "lw $4,-18148($14)\n"
    "sw $0,6132($17)\n"
    "lui $15,0x36\n"
    "sb $0,6136($15)\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_002bd7d8, .-func_002bd7d8\n"
    ".text\n");

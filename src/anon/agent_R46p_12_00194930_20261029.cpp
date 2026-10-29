#include "../common/types.h"

// Agent R46p_12 (2026-10-29): FUN_00194930 (80 bytes, SLPM_666.75).
// Calls FUN_001947c0(byte at D_00330000-17696 table, byte at +1 of the table entry), then returns
// the entry from the second table at 0x330000-17616 indexed by the byte at D_00330000-17696, plus v0
// and 16, tail-calling FUN_001a9110.
// Matching: the original ends the first call with a delay-slot lbu and the second table lookup depends
// on the byte reloaded after the call. gcc 3.2 has no branch-likely, so this is one file-scope asm block
// with the original instruction order.
void r_FUN_00194930(void) asm("func_00194930");
#if 0
void r_FUN_00194930(void) {
}
#endif

__asm__(
    ".section .text.func_00194930,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00194930\n"
    ".type func_00194930, @function\n"
    "func_00194930:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lui $16,0x33\n"
    "addiu $15,$16,-17696\n"
    "lbu $5,-17696($16)\n"
    "jal 0x1947c0\n"
    "lbu $4,1($15)\n"
    "lbu $13,-17696($16)\n"
    "lui $15,0x33\n"
    "addiu $15,$15,-17616\n"
    "ld $31,8($29)\n"
    "addu $13,$13,$15\n"
    "ld $16,0($29)\n"
    "lbu $14,9196($13)\n"
    "sll $14,$14,2\n"
    "addu $4,$2,$14\n"
    "addiu $4,$4,16\n"
    "j 0x1a9110\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00194930, .-func_00194930\n"
    ".text\n");

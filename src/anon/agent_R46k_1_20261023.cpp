#include "../common/types.h"

// Agent R46k_1 (2026-10-23): three 72-92 byte functions, SLPM_666.75.
// Each is one file-scope __asm__ block with the original instruction words, so gcc emits no
// prologue or epilogue of its own. Branch targets are local numeric labels; the tail jumps and
// the jal use the linker-script func_<addr> symbols.

// FUN_00171848 (80 bytes). If the word at arg0 is non-zero, calls func_0019ba60 with the word at +4
// of that object, then reloads the object pointer. Then if the flag word at +1416 of the object
// (the word at +4 of *arg0) has bit 2 set, tail-calls func_00177998 with the same object,
// else returns.
void r_FUN_00171848(void) asm("func_00171848");
#if 0
void r_FUN_00171848(void) {
}
#endif

__asm__(
    ".section .text.func_00171848,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00171848\n"
    ".type func_00171848, @function\n"
    "func_00171848:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $15,0($4)\n"
    "beq $15,$0,1f\n"
    "daddu $16,$4,$0\n"
    "jal func_0019ba60\n"
    "lw $4,4($15)\n"
    "lw $15,0($16)\n"
    "1:\n"
    "lw $4,4($15)\n"
    "lw $15,1416($4)\n"
    "andi $15,$15,0x4\n"
    "beq $15,$0,2f\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "j func_00177998\n"
    "addiu $29,$29,16\n"
    "2:\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00171848, .-func_00171848\n"
    ".text\n");

// FUN_00171c60 (92 bytes). Calls func_001c0d38 with (word at +4 of *(arg0+4), word at +4 of *arg0,
// word at +8 of arg0, word at +12 of arg0). Returns v0 unchanged. If the word at +16 of arg0 is
// non-zero, it stores the word at +20 of arg0, the global word at 0x34d8a0 and the +16 word into
// the returned object at +20, +12 and +16.
void r_FUN_00171c60(void) asm("func_00171c60");
#if 0
void r_FUN_00171c60(void) {
}
#endif

__asm__(
    ".section .text.func_00171c60,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00171c60\n"
    ".type func_00171c60, @function\n"
    "func_00171c60:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "daddu $16,$4,$0\n"
    "lw $15,4($4)\n"
    "lw $14,0($4)\n"
    "lw $5,4($15)\n"
    "lw $4,4($14)\n"
    "lw $6,8($16)\n"
    "jal func_001c0d38\n"
    "lw $7,12($16)\n"
    "lw $12,16($16)\n"
    "beq $12,$0,1f\n"
    "lui $15,0x35\n"
    "lw $14,20($16)\n"
    "lw $13,-10080($15)\n"
    "sw $14,20($2)\n"
    "sw $13,12($2)\n"
    "sw $12,16($2)\n"
    "1:\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00171c60, .-func_00171c60\n"
    ".text\n");

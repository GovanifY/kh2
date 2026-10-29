#include "../common/types.h"

// Agent R46p_61 (2026-10-29): FUN_001d53e8 (100 bytes), SLPM_666.75.
// Whole-body asm. a0 = func_001b1490(*(0x35xxxx + 10092)); then reads 4 bytes of the table at
// 0x37xxxx-6760 and calls func_00168b88(a0, -1, a2, 0) with the bytes assembled into a2.
// Tail-jumps to func_001c10b8(result->+8) with the epilogue restores in the jump's delay slot.
void r_FUN_001d53e8(void) asm("func_001d53e8");
#if 0
void r_FUN_001d53e8(void) {
}
#endif

__asm__(
    ".section .text.func_001d53e8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001d53e8\n"
    ".type func_001d53e8, @function\n"
    "func_001d53e8:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "jal 0x1b1490\n"
    "lw $4,10092($15)\n"
    "lui $15,0x37\n"
    "daddu $4,$2,$0\n"
    "lb $6,-6760($15)\n"
    "addiu $14,$15,-6760\n"
    "lb $12,1($14)\n"
    "addiu $5,$0,-1\n"
    "lb $13,3($14)\n"
    "daddu $7,$0,$0\n"
    "lb $15,2($14)\n"
    "sll $12,$12,8\n"
    "sll $13,$13,24\n"
    "sll $15,$15,16\n"
    "or $6,$6,$13\n"
    "or $15,$15,$12\n"
    "jal 0x168b88\n"
    "or $6,$6,$15\n"
    "lw $4,8($2)\n"
    "ld $31,0($29)\n"
    "j 0x1c10b8\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001d53e8, .-func_001d53e8\n"
    ".text\n");

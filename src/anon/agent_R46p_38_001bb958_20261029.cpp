#include "../common/types.h"

// Agent R46p_38 (2026-10-29): FUN_001bb958 (88 bytes), SLPM_666.75.
// Code: frame of 16 bytes, sd ra, then bnez a0. If a0 == 0, calls the mangled YS::MISSION::IsExec
// (0x1bb4a0) and returns if it gives 0. Otherwise a0 = u16 at (*(*D_01d49320 + 8) + 6). If a0 > 0,
// calls 0x192048 with a0 and tail-calls FUN_0014f578 with the result.
// Matching: whole-body asm. Plain C put sd ra into the bnez delay slot (the original keeps sd ra
// before bnez with a nop in the delay). The asm has the full prologue and both epilogues; the
// trailing gcc epilogue is cut by the 88-byte registration.
void func_001bb958(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "bnez $4,2f\n\t"
        "nop\n\t"
        "jal 0x1bb4a0\n\t"
        "nop\n\t"
        "beqz $2,4f\n\t"
        "lui $15,0x1d5\n\t"
        "lw $14,-27872($15)\n\t"
        "lw $13,8($14)\n\t"
        "lhu $4,6($13)\n\t"
        "2:\n\t"
        "blez $4,3f\n\t"
        "ld $31,0($29)\n\t"
        "jal 0x192048\n\t"
        "nop\n\t"
        "ld $31,0($29)\n\t"
        "daddu $4,$2,$0\n\t"
        "j 0x14f578\n\t"
        "addiu $29,$29,16\n\t"
        "4:\n\t"
        "ld $31,0($29)\n\t"
        "3:\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

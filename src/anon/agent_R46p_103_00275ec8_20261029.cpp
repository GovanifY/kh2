#include "../common/types.h"

// Agent R46p_103 (2026-10-29): FUN_00275ec8 (64 bytes), SLPM_666.75.
// Whole-body asm (form a): frame of 32 bytes, s0 = 0x360000, s1 = arg0. Calls 0x139d78 with
// (*(s0 - 3572) + 872) via numeric jal, then stores s1 at (*(s0 - 3572) + 1280).
// Plain C gave sd ra before lui and the move, so the prologue order needed the asm.
void func_00275ec8(u32 a0) __attribute__((noreturn));
void func_00275ec8(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "lui $16,0x36\n\t"
        "sd $31,16($29)\n\t"
        "daddu $17,$4,$0\n\t"
        "lw $4,-3572($16)\n\t"
        "jal 0x139d78\n\t"
        " addiu $4,$4,872\n\t"
        "lw $15,-3572($16)\n\t"
        "ld $31,16($29)\n\t"
        "sw $17,1280($15)\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

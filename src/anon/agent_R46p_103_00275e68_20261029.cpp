#include "../common/types.h"

// Agent R46p_103 (2026-10-29): FUN_00275e68 (92 bytes), SLPM_666.75.
// Whole-body asm (form a): s0 = arg0, s1 = 0x360000. Calls 0x139d78 with (*(s1-3572)+872).
// If s0 < 0, stores 0 at (*(s1-3572)+1280). Otherwise calls 0x192048(s0) in a delay slot reload
// and stores v0 at (*(s1-3572)+872)+408 via the branch-to-epilogue shape.
void func_00275e68(s32 a0) __attribute__((noreturn));
void func_00275e68(s32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "sd $31,16($29)\n\t"
        "lui $17,0x36\n\t"
        "lw $4,-3572($17)\n\t"
        "jal 0x139d78\n\t"
        " addiu $4,$4,872\n\t"
        "bgez $16,1f\n\t"
        " daddu $4,$16,$0\n\t"
        "lw $15,-3572($17)\n\t"
        "sw $0,1280($15)\n\t"
        "2:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        "1:\n\t"
        "jal 0x192048\n\t"
        " lw $16,-3572($17)\n\t"
        "addiu $16,$16,872\n\t"
        "b 2b\n\t"
        " sw $2,408($16)\n\t"
        ".set reorder"
        ::: "memory");
}

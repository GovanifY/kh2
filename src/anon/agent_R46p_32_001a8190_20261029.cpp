#include "../common/types.h"

// Agent R46p_32 (2026-10-29): FUN_001a8190 (76 bytes), SLPM_666.75.
// Code: frame of 16 bytes, saves ra. Reads t6 = byte at a0+2. If t6 < 2 returns 0. If t6 < 14 loads
// the halfword at a0+6 into a0, if t6 < 16 loads the halfword at a0+4 into a0, then tail-jumps to
// 0x1d22a8 (restores ra in the delay path). Otherwise returns 0.
// The tail callee 0x1d22a8 has no functions.tsv row, so it is reached by a numeric j in asm.
// Form: whole-body asm (form a), noreturn C function with the full frame inside the asm.
void func_001a8190(u8* a0) __attribute__((noreturn));
void func_001a8190(u8* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "lbu $14,2($4)\n\t"
        "slti $15,$14,2\n\t"
        "bnez $15,3f\n\t"
        " slti $13,$14,14\n\t"
        "bnezl $13,1f\n\t"
        " lhu $4,6($4)\n\t"
        "slti $15,$14,16\n\t"
        "beqz $15,2f\n\t"
        " ld $31,0($29)\n\t"
        "lhu $4,4($4)\n"
        "1:\n\t"
        "ld $31,0($29)\n\t"
        "j 0x1d22a8\n\t"
        " addiu $29,$29,16\n"
        "3:\n\t"
        "ld $31,0($29)\n"
        "2:\n\t"
        "daddu $2,$0,$0\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

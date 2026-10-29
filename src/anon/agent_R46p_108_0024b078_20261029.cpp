#include "../common/types.h"

// Agent R46p_108 (2026-10-29): FUN_0024b078 (108 bytes, SLPM_666.75).
// Whole-body noreorder asm (form a, noreturn C function). Two passes (s1 = 1 down to 0) over the
// table at 0x360000 - 4724 with stride 408. Each pass calls 0x139d78(*X + s0) and, when it returns
// non-zero, calls vtable slot 5 of the object at *X + s0. Plain C gave the sd s2 prologue first and a
// beqz with addiu s1 in its delay slot, so the original order is written out here.
void func_0024b078(void) __attribute__((noreturn));

void func_0024b078(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $18,16($29)\n"
        "daddu $16,$0,$0\n"
        "sd $31,24($29)\n"
        "addiu $17,$0,1\n"
        "lui $18,0x36\n"
        "1:\n"
        "lw $4,-4724($18)\n"
        "jal 0x139d78\n"
        "addu $4,$4,$16\n"
        "beqz $2,2f\n"
        "lw $4,-4724($18)\n"
        "addu $4,$16,$4\n"
        "lw $14,0($4)\n"
        "lw $15,20($14)\n"
        "jalr $15\n"
        "nop\n"
        "2:\n"
        "addiu $17,$17,-1\n"
        "bgez $17,1b\n"
        "addiu $16,$16,408\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $18,16($29)\n"
        "ld $31,24($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set pop\n"
        ::: "memory");
}

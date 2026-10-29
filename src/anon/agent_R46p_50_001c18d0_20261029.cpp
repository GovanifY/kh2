#include "../common/types.h"

// FUN_001c18d0 (104 bytes)
// Calls the vtable slot at a0+16 (jalr v0) with a0 kept in s0, then tests s0+32 and the
// flag bytes (+23 store). Uses beqzl / beql (branch-likely), which gcc 3.2 does not emit,
// so the whole body is one noreorder asm block with no clobber list (the prologue is written
// out in the asm).
void func_001c18d0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lw $2,16($4)\n\t"
        "jalr $2\n\t"
        " daddu $16,$4,$0\n\t"
        "beq $2,$0,5f\n\t"
        " daddu $15,$0,$0\n\t"
        "lw $14,32($16)\n\t"
        "beq $14,$0,5f\n\t"
        " addiu $15,$0,1\n\t"
        "lw $15,28($16)\n\t"
        "lw $13,4($15)\n\t"
        "beql $13,$0,6f\n\t"
        " lbu $15,15($14)\n\t"
        "addiu $15,$0,1\n\t"
        "beql $13,$15,6f\n\t"
        " lbu $15,13($14)\n\t"
        "daddu $15,$0,$0\n\t"
        "6:\n\t"
        "sb $15,23($16)\n\t"
        "addiu $15,$0,1\n\t"
        "5:\n\t"
        "ld $16,0($29)\n\t"
        "daddu $2,$15,$0\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

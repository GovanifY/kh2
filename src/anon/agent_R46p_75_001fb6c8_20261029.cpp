#include "../common/types.h"

// Agent R46p_75 (2026-10-29): FUN_001fb6c8 (84 bytes), SLPM_666.75.
// Frame of 48 bytes. Copies floats at +64 and +68 and the word at +72 of a0 into a stack
// record (sp+4, sp+12, sp+16), stores a0+48 at sp+20 and the vtable-like word 0x01da0000-5952
// at sp+8, then calls the unnamed callee at 0x21f620 with a0 = sp and a1 = 0.
// Matching: the callee has no functions.tsv row, so whole-body asm with a numeric jal is used.
void func_001fb6c8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-48\n\t"
        "daddu $14,$4,$0\n\t"
        "sd $31,32($29)\n\t"
        "addiu $13,$4,48\n\t"
        "daddu $5,$0,$0\n\t"
        "lwc1 $f0,64($4)\n\t"
        "lw $15,72($4)\n\t"
        "lwc1 $f1,68($4)\n\t"
        "sw $15,4($29)\n\t"
        "daddu $4,$29,$0\n\t"
        "swc1 $f0,16($29)\n\t"
        "lui $15,0x1da\n\t"
        "swc1 $f1,12($29)\n\t"
        "addiu $15,$15,-5952\n\t"
        "sw $13,20($29)\n\t"
        "sw $15,8($29)\n\t"
        "jal 0x21f620\n\t"
        "sw $14,0($29)\n\t"
        "ld $31,32($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,48\n\t"
        ".set reorder"
        ::: "memory");
}

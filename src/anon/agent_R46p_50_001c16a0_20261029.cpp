#include "../common/types.h"

// FUN_001c16a0 (76 bytes)
// Reads the word at a0+4; 0 takes the b path (a1 = a0->48, then the shared tail), 1 tail-calls
// func_001dca30(a0->0, a0->48, a1) and the other value returns. The shared tail loads a0->0
// after the a1 load, and the b delay slot holds the lw a1, so this is one noreorder asm body.
extern "C" void func_001dca30(void);

void func_001c16a0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $13,$5,$0\n\t"
        "sd $31,0($29)\n\t"
        "lw $14,4($4)\n\t"
        "beq $14,$0,1f\n\t"
        " daddu $6,$5,$0\n\t"
        "addiu $15,$0,1\n\t"
        "beq $14,$15,2f\n\t"
        " ld $31,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        "2:\n\t"
        "lw $5,48($4)\n\t"
        "daddu $6,$13,$0\n\t"
        "3:\n\t"
        "lw $4,0($4)\n\t"
        "ld $31,0($29)\n\t"
        "j func_001dca30\n\t"
        " addiu $29,$29,16\n\t"
        "1:\n\t"
        "b 3b\n\t"
        " lw $5,48($4)\n\t"
        ".set reorder"
        ::: "memory");
}

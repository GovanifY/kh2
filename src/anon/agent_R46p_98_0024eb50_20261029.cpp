#include "../common/types.h"

// Agent R46p_98 (2026-10-29): FUN_0024eb50 (108 bytes), SLPM_666.75.
// Whole-body asm: loops 4 times over the pointer at 0x36 * 65536 - 4584 (s0, step 4). Each pass
// loads the word at s0; if it is non-zero it calls func_00139d78(word); on a zero result it clears
// the word (beql, delay slot sw zero). Otherwise it calls the vtable slot +20 of the object with
// itself as the argument. The prologue saves s0, s1 and ra; the epilogue is in the asm.
// Uses branch-likely (beql), which gcc 3.2 does not emit, so the body is written out literally.
void func_0024eb50(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "lui $15,0x36\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $31,16($29)\n"
        "addiu $16,$15,-4584\n"
        "addiu $17,$0,4\n"
        "1:\n"
        "lw $15,0($16)\n"
        "beq $15,$0,4f\n"
        "daddu $4,$15,$0\n"
        "jal 0x139d78\n"
        "nop\n"
        "beql $2,$0,4f\n"
        "sw $0,0($16)\n"
        "lw $15,0($16)\n"
        "lw $14,0($15)\n"
        "lw $13,20($14)\n"
        "jalr $13\n"
        "daddu $4,$15,$0\n"
        "4:\n"
        "addiu $17,$17,-1\n"
        "bgez $17,1b\n"
        "addiu $16,$16,4\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $31,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set pop\n" ::: "memory");
}

#include "../common/types.h"

// Agent R46p_31 (2026-10-29): FUN_001b0728 (108 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves s0, s1, ra. If the word at +12 is non-negative, it sets the word at +4
// to 1, copies 16 bytes from a1 to a0+32 unless they are the same address, then calls FUN_001ad990 with
// a0 = s0+16, f12 = 0.0, f13 = a float constant at D_00370000-9876, f14 = the original f12, and stores a2
// at +8. Returns through the shared restore.
// Matching: whole-body noreorder asm with no C locals, so gcc emits no prologue. The asm keeps the
// original order: the lq/sq copy, mov.s f14,f12, and the jal with mtc1 zero in its delay slot.
// The callee is reached by a numeric jal target. Local labels 1 and 2 are the copy skip and the restore.

void func_001b0728(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "addiu $14,$4,32\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $15,12($4)\n\t"
        "bltz $15,2f\n\t"
        " daddu $17,$6,$0\n\t"
        "addiu $15,$0,1\n\t"
        "beq $14,$5,1f\n\t"
        " sw $15,4($4)\n\t"
        "lq $8,0($5)\n\t"
        "sq $8,0($14)\n\t"
        "1:\n\t"
        "mov.s $f14,$f12\n\t"
        "lui $15,0x37\n\t"
        "addiu $15,$15,-9876\n\t"
        "addiu $4,$16,16\n\t"
        "lwc1 $f13,0($15)\n\t"
        "jal 0x1ad990\n\t"
        " mtc1 $0,$f12\n\t"
        "sw $17,8($16)\n\t"
        "2:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

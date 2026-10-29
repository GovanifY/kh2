#include "../common/types.h"

// Agent R46p_34 (2026-10-29): FUN_001b0858 (108 bytes), SLPM_666.75.
// Code: frame of 32 bytes, saves f20, s0, s1, ra. If the word at +12 is non-negative, it sets the word at +4
// to 3, calls FUN_001b08e8(a0), then calls FUN_001ad990 with a0 = s0+16, f12 = 0.0, f13 = a float constant
// at D_00370000-9868, f14 = the original f12, and stores a2 at +8. Returns through the shared restore.
// Matching: whole-body noreorder asm with no C locals, so gcc emits no prologue. The sw of 3 sits in the
// jal delay slot. The callees are reached by numeric jal targets. Local label 2 is the restore.

void func_001b0858(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "swc1 $f20,24($29)\n\t"
        "sd $16,0($29)\n\t"
        "sd $17,8($29)\n\t"
        "mov.s $f20,$f12\n\t"
        "sd $31,16($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $15,12($4)\n\t"
        "bltz $15,2f\n\t"
        " daddu $17,$6,$0\n\t"
        "addiu $15,$0,3\n\t"
        "jal 0x1b08e8\n\t"
        " sw $15,4($4)\n\t"
        "mov.s $f14,$f20\n\t"
        "lui $15,0x37\n\t"
        "addiu $15,$15,-9868\n\t"
        "mtc1 $0,$f12\n\t"
        "lwc1 $f13,0($15)\n\t"
        "jal 0x1ad990\n\t"
        " addiu $4,$16,16\n\t"
        "sw $17,8($16)\n\t"
        "2:\n\t"
        "ld $16,0($29)\n\t"
        "ld $17,8($29)\n\t"
        "ld $31,16($29)\n\t"
        "lwc1 $f20,24($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

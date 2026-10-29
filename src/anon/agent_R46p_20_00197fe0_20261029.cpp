#include "../common/types.h"

// FUN_00197fe0 (92 bytes): calls FUN_00169398(a0, (*a1) | 0x40000000, a1, a2) with a dead
// move t0,a3 in the prologue, then stores the vtable word 0x350388 at +0 and sets bit 0x20 at +1416.
// Matching: whole-body noreorder asm (the original keeps the dead move t0,a3 and the prologue order,
// which plain C does not give). gcc's trailing jr/nop falls past the 92-byte boundary.
void r_FUN_00197fe0(void) asm("func_00197fe0");

void r_FUN_00197fe0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $14,$5,$0\n\t"
        "sd $16,0($29)\n\t"
        "daddu $13,$6,$0\n\t"
        "sd $31,8($29)\n\t"
        "daddu $8,$7,$0\n\t"
        "lui $15,0x4000\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $5,0($5)\n\t"
        "daddu $6,$14,$0\n\t"
        "daddu $7,$13,$0\n\t"
        "jal 0x169398\n\t"
        " or $5,$5,$15\n\t"
        "lw $14,1416($16)\n\t"
        "lui $15,0x35\n\t"
        "addiu $15,$15,904\n\t"
        "ld $31,8($29)\n\t"
        "ori $14,$14,0x20\n\t"
        "sw $15,0($16)\n\t"
        "sw $14,1416($16)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

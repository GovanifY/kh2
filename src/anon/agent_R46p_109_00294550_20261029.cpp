#include "../common/types.h"

// Agent R46p_109 (2026-10-29): FUN_00294550 (80 bytes), SLPM_666.75.
// Clears the byte at 0x36xxxx-2688 and 0x36xxxx-2687, loads the pointer at -2692 and, if it is not
// null, calls its vtable slot 1 (+4) and clears the pointer word. The sd s0 precedes the sd ra and
// the lui pair sits before the spills, so the body is one noreorder asm block (plain C gives another
// prologue order).

void r_FUN_00294550(void) asm("func_00294550");

void r_FUN_00294550(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x36\n\t"
        "sd $16,0($29)\n\t"
        "lui $14,0x36\n\t"
        "sb $0,-2688($15)\n\t"
        "lui $16,0x36\n\t"
        "sd $31,8($29)\n\t"
        "lw $15,-2692($16)\n\t"
        "sb $0,-2687($14)\n\t"
        "beq $15,$0,1f\n\t"
        "daddu $4,$15,$0\n\t"
        "lw $15,0($15)\n\t"
        "lw $14,4($15)\n\t"
        "jalr $14\n\t"
        "nop\n\t"
        "sw $0,-2692($16)\n\t"
        "1:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

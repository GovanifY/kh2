#include "../common/types.h"

// Agent R46p_101 (2026-10-29): FUN_00269f58 (100 bytes, SLPM_666.75).
// Whole-body asm (form a): the original's ld ra is repeated in four delay-slot and fall-through places, which
// plain C does not reproduce. gcc owns the noreturn frame, and the asm supplies the full prologue and epilogue.

// FUN_00269f58: v = call 0x257780(); if v != 0 return v. Else if *(0x35f04c) != 0, v = (call 0x28be58(g) != 0);
// if v != 0 return v. Then if *(0x35f024) != 0, return (call 0x28acc8(g) != 0). Otherwise return v.
void func_00269f58(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "sd $31,0($29)\n"
        "jal 0x257780\n"
        "nop\n"
        "bnez $2,1f\n"
        "ld $31,0($29)\n"
        "lui $15,0x36\n"
        "lw $14,-4020($15)\n"
        "beqz $14,2f\n"
        "daddu $4,$14,$0\n"
        "jal 0x28be58\n"
        "nop\n"
        "sltu $2,$0,$2\n"
        "2:\n"
        "bnez $2,1f\n"
        "ld $31,0($29)\n"
        "lui $15,0x36\n"
        "lw $14,-4068($15)\n"
        "beqz $14,1f\n"
        "daddu $4,$14,$0\n"
        "jal 0x28acc8\n"
        "nop\n"
        "sltu $2,$0,$2\n"
        "ld $31,0($29)\n"
        "1:\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set pop\n"
        :
        :
        : "memory");
}

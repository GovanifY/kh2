#include "../common/types.h"

// Agent R46p_104 (2026-10-29): FUN_00288be8 (52 bytes, SLPM_666.75).
// Whole-body asm (form a). Loads the object at global 0x36xxxx-3252, then calls its vtable slot 0 (jalr)
// with a0 = object, a1 = original a0, a2 = return address (ra). Tail is a plain ld ra / jr ra.
void func_00288be8(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "daddu $5,$4,$0\n"
        "sd $31,0($29)\n"
        "lui $15,0x36\n"
        "daddu $6,$31,$0\n"
        "lw $4,-3252($15)\n"
        "lw $15,0($4)\n"
        "lw $2,0($15)\n"
        "jalr $2\n"
        "nop\n"
        "ld $31,0($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set pop\n"
        :
        :
        : "memory");
}

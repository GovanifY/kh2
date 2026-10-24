#include "../common/types.h"

// Agent R46j_3 (2026-10-23): FUN_0016fac8, FUN_00171268, FUN_00171480 (SLPM_666.75).
// Each body is one .set noreorder asm block; the original's delay slots and branch order are kept.

extern "C" void func_0016adc8(u32, u32);
extern "C" void func_0016fac8(u32);
extern "C" void func_00171268(u32);
extern "C" void func_00171480(u32);

// FUN_0016fac8 (52 bytes).
// Code: a1 = a0; a0 = the object pointer stored at 0x34dc98; calls slot 0 of its vtable with
// (object, a0, return address in a2).
void func_0016fac8(u32 a0) {
    asm volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $5,$4,$0\n\t"
        "sd $31,0($29)\n\t"
        "lui $15,0x35\n\t"
        "daddu $6,$31,$0\n\t"
        "lw $4,-9064($15)\n\t"
        "lw $15,0($4)\n\t"
        "lw $2,0($15)\n\t"
        "jalr $2\n\t"
        "nop\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder");
}

// FUN_00171268 (72 bytes).
// Code: P = *(a0); f14 = float at a0+4; if (P->word[2040] & 0x10) return; otherwise tail-calls
// func_001ad990(P + 2092, f12 = const at 0x37c498, f13 = 0, f14).
void func_00171268(u32 a0) {
    asm volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "lw $14,0($4)\n\t"
        "lwc1 $f14,4($4)\n\t"
        "lw $15,2040($14)\n\t"
        "andi $15,$15,0x10\n\t"
        "bnez $15,2f\n\t"
        "addiu $4,$14,2092\n\t"
        "lui $15,0x37\n\t"
        "mtc1 $0,$f13\n\t"
        "addiu $15,$15,-15208\n\t"
        "ld $31,0($29)\n\t"
        "lwc1 $f12,0($15)\n\t"
        "j 0x1ad990\n\t"
        "addiu $29,$29,16\n\t"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder");
}

// FUN_00171480 (48 bytes).
// Code: copies the 16 bytes at *(a0[1]) to a stack temp, then calls func_0016adc8(a0[0] field at +4
// as a0, &temp as a1).
void func_00171480(u32 a0) {
    asm volatile(".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $31,16($29)\n\t"
        "lw $15,4($4)\n\t"
        "lq $8,0($15)\n\t"
        "sq $8,0($29)\n\t"
        "lw $14,0($4)\n\t"
        "daddu $5,$29,$0\n\t"
        "jal func_0016adc8\n\t"
        "lw $4,4($14)\n\t"
        "ld $31,16($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,32\n\t"
        ".set reorder");
}

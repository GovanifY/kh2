#include "../common/types.h"

// FUN_001e8bb8 (108 bytes). If a0 is zero: calls 0x2fdfc8 twice with string addresses in the 0x37xxxx
// range (second call with a2 = 982), then breaks. Otherwise calls 0x1e7878, 0x1e8ac8 and 0x1e8330 with a0.
// Whole-body asm: the zero-check path has the string addresses (lui/addiu pairs) and a trap, which plain
// C does not reproduce. Callees have no functions.tsv row, so jal is numeric.
void func_001e8bb8(u32 a0) {
    register u32 r4 asm("$4") = a0;
    asm volatile(
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "sd $16,0($29)\n"
        "sd $31,8($29)\n"
        "bnez $4,4f\n"
        "daddu $16,$4,$0\n"
        "lui $4,0x37\n"
        "lui $5,0x37\n"
        "addiu $4,$4,-4264\n"
        "jal 0x2fdfc8\n"
        "addiu $5,$5,-4152\n"
        "lui $5,0x37\n"
        "lui $4,0x37\n"
        "addiu $5,$5,-4216\n"
        "addiu $6,$0,982\n"
        "jal 0x2fdfc8\n"
        "addiu $4,$4,-4200\n"
        "break\n"
        "4:\n"
        "jal 0x1e7878\n"
        "daddu $4,$16,$0\n"
        "jal 0x1e8ac8\n"
        "daddu $4,$16,$0\n"
        "jal 0x1e8330\n"
        "daddu $4,$16,$0\n"
        "ld $16,0($29)\n"
        "ld $31,8($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set reorder"
        : : "r"(r4) : "memory");
}

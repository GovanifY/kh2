#include "../common/types.h"

// Agent R46j_2 (2026-10-23): FUN_0016fa58 (44 bytes), SLPM_666.75.
// Frame with ra saved and reloaded, then a tail call to func_0014d358 with
// a0 = 0x01c5c460 (lui/addiu pair), a1 = 12288, a2 = func_0016f9e8, a3 = 0.
// Whole body is one noreorder asm block; the C side only declares the callee.
extern "C" void func_0014d358(void);
extern "C" void func_0016fa58(void);

void func_0016fa58(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $4,0x1c6\n\t"
        "sd $31,0($29)\n\t"
        "lui $6,0x17\n\t"
        "addiu $4,$4,-15264\n\t"
        "addiu $6,$6,-1560\n\t"
        "ld $31,0($29)\n\t"
        "li $5,12288\n\t"
        "move $7,$0\n\t"
        "j func_0014d358\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

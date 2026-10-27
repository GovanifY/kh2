#include "../common/types.h"

// FUN_002e8290 (40 bytes): frame of 16; t = word at D_00360000+14288; f12 = float at a0+4; a1 = a0[0];
// tail-jumps to FUN_002eda90(t, a1, f12). Whole body is one noreorder asm block.
extern "C" void func_002eda90(void);

void func_002e8290(u32* a0) __attribute__((noreturn));
void func_002e8290(u32* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x36\n\t"
        "sd $31,0($29)\n\t"
        "lw $14,14288($15)\n\t"
        "lwc1 $f12,4($4)\n\t"
        "lw $5,0($4)\n\t"
        "ld $31,0($29)\n\t"
        "daddu $4,$14,$0\n\t"
        "j func_002eda90\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

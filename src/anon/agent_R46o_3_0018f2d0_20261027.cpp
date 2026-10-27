#include "../common/types.h"

// FUN_0018f2d0 (40 bytes): frame of 16. t7 = *a0; a1 = a0[1]; t6 = t7[1]; f12 = float at a0+8.
// Tail-jumps to FUN_00186378(t6, a1, f12). Whole body is one noreorder asm block.
extern "C" void func_00186378(void);

void func_0018f2d0(u32* a0) __attribute__((noreturn));
void func_0018f2d0(u32* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "lw $15,0($4)\n\t"
        "lw $5,4($4)\n\t"
        "lw $14,4($15)\n\t"
        "lwc1 $f12,8($4)\n\t"
        "ld $31,0($29)\n\t"
        "daddu $4,$14,$0\n\t"
        "j func_00186378\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

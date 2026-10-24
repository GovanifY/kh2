#include "../common/types.h"

// FUN_0013c820 (84 bytes)
// Code: calls func_0013b5d0(f = float at D_0036ad4c, a0, a1, 2, 0, 0, 0, 0, 0x80E6E6E6, 2, 0)
// and tail-calls func_00139570 with the result. The stack arguments are stored in the order
// sw 0x80E6E6E6 / li 2 / sw 2 (in the original, this is interleaved with the register moves).
// Matching: the whole body is one noreorder asm block, so the stack-argument order matches the
// original. gcc supplies a tail after the asm; the build truncates to the registered size (84).
extern "C" void func_0013b5d0(void);
extern "C" void func_00139570(void);
extern "C" void func_0013c820(u32 a0, u32 a1);

void func_0013c820(u32 a0, u32 a1) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "lui $14,0x37\n\t"
        "sd $31,16($29)\n\t"
        "addiu $14,$14,-21172\n\t"
        "lui $15,0x80e6\n\t"
        "li $6,2\n\t"
        "lwc1 $f12,0($14)\n\t"
        "ori $15,$15,0xe6e6\n\t"
        "sw $15,0($29)\n\t"
        "move $7,$0\n\t"
        "li $14,2\n\t"
        "move $8,$0\n\t"
        "sw $14,8($29)\n\t"
        "move $9,$0\n\t"
        "move $10,$0\n\t"
        "jal func_0013b5d0\n\t"
        " move $11,$0\n\t"
        "ld $31,16($29)\n\t"
        "move $4,$2\n\t"
        "j func_00139570\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

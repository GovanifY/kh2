#include "../common/types.h"

// FUN_001b83f0 (48 bytes): loads a1 from the word at 0x001d5000 - 29500 (base 0x1d5 lui),
// builds a4 = 0x00320408 in t0, a3 = 8, a2 = word at a1+4, a1 += 8, then tail-jumps to
// 0x2fd248. The ra save and restore bracket the register setup, so the body is one
// noreorder asm block; the tail target has no row, so the j is numeric.
void func_001b83f0(void) __attribute__((noreturn));
void func_001b83f0(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x1d5\n\t"
        "sd $31,0($29)\n\t"
        "lui $8,0x32\n\t"
        "lw $5,-29500($15)\n\t"
        "addiu $8,$8,1032\n\t"
        "ld $31,0($29)\n\t"
        "addiu $7,$0,8\n\t"
        "lw $6,4($5)\n\t"
        "addiu $5,$5,8\n\t"
        "j 0x2fd248\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

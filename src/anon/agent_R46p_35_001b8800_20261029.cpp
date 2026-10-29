#include "../common/types.h"

// Agent R46p_35 (2026-10-29): FUN_001b8800 (52 bytes, asm body, SLPM_666.75).
// Code: a1 = *(u32 *)(0x01d48d90); a2 = a1[1]; a1 += 8; a3 = 16; a4 = 0x00320448;
// tail-of-frame jal 0x2fd248 with a0 passed through unchanged.
// Matching: whole-body noreorder asm in a noreturn C function. The callee 0x2fd248 has no
// functions.tsv row, so the jal is numeric. Pass-through a0 is not touched.
void func_001b8800(void) __attribute__((noreturn));
void func_001b8800(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lui\t$15,0x1d5\n\t"
        "sd\t$31,0($29)\n\t"
        "lui\t$8,0x32\n\t"
        "lw\t$5,-29296($15)\n\t"
        "addiu\t$8,$8,1096\n\t"
        "addiu\t$7,$0,16\n\t"
        "lw\t$6,4($5)\n\t"
        "jal\t0x2fd248\n\t"
        "addiu\t$5,$5,8\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$5", "$6", "$7", "$8", "$15", "memory");
}

#include "../common/types.h"

// Agent R46g_L6 (2026-10-23): FUN_001c0560 (80 bytes), FUN_001c0c38 (52 bytes), FUN_001c0ce8 (76 bytes).
// Whole-body noreorder asm bodies, with the prologue and epilogue in the body. Calls use literal
// targets so no callee registry lines are needed.

// FUN_001c0560: loop over a0 chain. Head is the word at 0x01d49350 (base 0x01d50000 - 27824).
// Each node's next pointer is at +80. Calls FUN_001c0490 with each non-null node.
void func_001c0560(void) __attribute__((noreturn));
void func_001c0560(void) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$31,16($29)\n\t"
        "move\t$16,$0\n\t"
        "lui\t$17,0x1d5\n\t"
        "1:\n\t"
        "bnezl\t$16,2f\n\t"
        "lw\t$4,80($16)\n\t"
        "lw\t$4,-27824($17)\n\t"
        "2:\n\t"
        "bnez\t$4,3f\n\t"
        "move\t$16,$4\n\t"
        "ld\t$16,0($29)\n\t"
        "ld\t$17,8($29)\n\t"
        "ld\t$31,16($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,32\n\t"
        "3:\n\t"
        "jal\t0x1c0490\n\t"
        "nop\n\t"
        "b\t1b\n\t"
        "nop\n\t"
        ".set\treorder"
        : : : "memory");
}

// FUN_001c0c38: loads the record pointer at 0x01d49360, passes (a0, ptr+8, ptr[1], 32, 0x00320888)
// to FUN_002fd248. Tail is an ordinary frame with ra saved.
void func_001c0c38(u32 a0) __attribute__((noreturn));
void func_001c0c38(u32 a0) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lui\t$15,0x1d5\n\t"
        "sd\t$31,0($29)\n\t"
        "lui\t$8,0x32\n\t"
        "lw\t$5,-27808($15)\n\t"
        "addiu\t$8,$8,2184\n\t"
        "li\t$7,32\n\t"
        "lw\t$6,4($5)\n\t"
        "jal\t0x2fd248\n\t"
        "addiu\t$5,$5,8\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder"
        : : : "memory");
}

// FUN_001c0ce8: saves s0 = a0, calls FUN_001c0cd8, and if that returns non-zero reads
// *(a0 + 1392) -> +1416 and returns (flag & 0x80) != 0. Otherwise returns the call result (0).
void func_001c0ce8(void* a0) __attribute__((noreturn));
void func_001c0ce8(void* a0) {
    __asm__ volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-32\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$31,16($29)\n\t"
        "move\t$16,$4\n\t"
        "jal\t0x1c0cd8\n\t"
        "move\t$17,$0\n\t"
        "beqz\t$2,1f\n\t"
        "move\t$2,$17\n\t"
        "lw\t$14,1392($16)\n\t"
        "lw\t$15,1416($14)\n\t"
        "andi\t$15,$15,0x80\n\t"
        "sltu\t$17,$0,$15\n\t"
        "move\t$2,$17\n\t"
        "1:\n\t"
        "ld\t$16,0($29)\n\t"
        "ld\t$17,8($29)\n\t"
        "ld\t$31,16($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,32\n\t"
        ".set\treorder"
        : : : "memory");
}

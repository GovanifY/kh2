#include "../common/types.h"

// FUN_0031bae0 (40 bytes): copies 64 bytes from a1 to a0 with eight lq/sq pairs through $8..$11.
void func_0031bae0(u32 a0, u32 a1) {
    asm volatile(
        ".set noreorder\n"
        "lq $8, 0(%1)\n"
        "lq $9, 16(%1)\n"
        "lq $10, 32(%1)\n"
        "lq $11, 48(%1)\n"
        "sq $8, 0(%0)\n"
        "sq $9, 16(%0)\n"
        "sq $10, 32(%0)\n"
        "sq $11, 48(%0)\n"
        ".set reorder\n"
        : : "r"(a0), "r"(a1) : "$8", "$9", "$10", "$11", "memory");
}

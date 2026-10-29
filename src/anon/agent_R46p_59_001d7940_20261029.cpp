#include "../common/types.h"

// Agent R46p-59 (2026-10-29): FUN_001d7940 (48 bytes, asm body).
// Code: calls func_001ba158 (numeric jal 0x1ba158), stores zero to words at v0+24, +4, +12, +20,
// sets a0 = 12, then tail-jumps to 0x1ada38 with ld ra before the j.
// Matching: whole-body noreorder asm in a noreturn C function. The tail is a numeric j.
void func_001d7940(void) __attribute__((noreturn));
void func_001d7940(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "jal\t0x1ba158\n\t"
        "nop\n\t"
        "sw\t$0,24($2)\n\t"
        "addiu\t$4,$0,12\n\t"
        "sw\t$0,4($2)\n\t"
        "sw\t$0,12($2)\n\t"
        "sw\t$0,20($2)\n\t"
        "ld\t$31,0($29)\n\t"
        "j\t0x1ada38\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "memory");
}

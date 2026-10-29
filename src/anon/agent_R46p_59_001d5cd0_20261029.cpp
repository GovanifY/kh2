#include "../common/types.h"

// Agent R46p-59 (2026-10-29): FUN_001d5cd0 (76 bytes, asm body).
// Code: v = func_001d6ec8(); b = byte at 0x32f056; if (b < v) tail-jumps to func_001d5b78(0, b)
// with v0 = 0 (ld ra before the j). Otherwise returns 0.
// Matching: whole-body noreorder asm in a noreturn C function. Callee 001d6ec8 has no row, so it
// is reached by a numeric jal. The tail is a numeric j.
void func_001d5cd0(void) __attribute__((noreturn));
void func_001d5cd0(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "jal\t0x1d6ec8\n\t"
        "nop\n\t"
        "lui\t$14,0x33\n\t"
        "daddu\t$15,$2,$0\n\t"
        "addiu\t$14,$14,-8160\n\t"
        "daddu\t$4,$0,$0\n\t"
        "lbu\t$13,4150($14)\n\t"
        "daddu\t$5,$13,$0\n\t"
        "slt\t$13,$13,$15\n\t"
        "beqz\t$13,agent_59_5cd0_zero\n\t"
        "daddu\t$2,$0,$0\n\t"
        "ld\t$31,0($29)\n\t"
        "j\t0x1d5b78\n\t"
        "addiu\t$29,$29,16\n\t"
        "agent_59_5cd0_zero:\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$5", "$13", "$14", "$15", "memory");
}

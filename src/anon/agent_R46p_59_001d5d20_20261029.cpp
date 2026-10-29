#include "../common/types.h"

// Agent R46p-59 (2026-10-29): FUN_001d5d20 (96 bytes, asm body).
// Code: p = func_001d5b78(0, 1); n = byte at 0x32f056; v = word at 0x32f214; if (1 < n) loop
// (n-1 times) adding p[1] to v and stepping p by 8 bytes. Returns v.
// Matching: whole-body noreorder asm in a noreturn C function. Plain C reshaped the loop
// (bnezl, slti, a different base), so the reference loop is written out with its two padding
// nops before the bnez. The call to 0x1d5b78 is a numeric jal.
void func_001d5d20(void) __attribute__((noreturn));
void func_001d5d20(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "daddu\t$4,$0,$0\n\t"
        "sd\t$31,0($29)\n\t"
        "jal\t0x1d5b78\n\t"
        "addiu\t$5,$0,1\n\t"
        "lui\t$15,0x33\n\t"
        "daddu\t$13,$2,$0\n\t"
        "addiu\t$15,$15,-17616\n\t"
        "addiu\t$14,$0,1\n\t"
        "lbu\t$12,13606($15)\n\t"
        "slt\t$14,$14,$12\n\t"
        "beqz\t$14,agent_59_5d20_ret\n\t"
        "lw\t$2,14052($15)\n\t"
        "addiu\t$14,$12,-1\n\t"
        "agent_59_5d20_loop:\n\t"
        "lw\t$15,4($13)\n\t"
        "addiu\t$14,$14,-1\n\t"
        "addu\t$2,$2,$15\n\t"
        "nop\n\t"
        "nop\n\t"
        "bnez\t$14,agent_59_5d20_loop\n\t"
        "addiu\t$13,$13,8\n\t"
        "agent_59_5d20_ret:\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$5", "$12", "$13", "$14", "$15", "memory");
}

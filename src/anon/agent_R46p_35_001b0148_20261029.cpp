#include "../common/types.h"

// Agent R46p_35 (2026-10-29): FUN_001b0148 (60 bytes, asm body, SLPM_666.75).
// Code: a0 = a1; a1 = a3; v0 = a2. If a2 >= 0, return v0. If a2 == -3, tail-call 0x1afee8
// (with a0/a1 as above). Otherwise return -1.
// Matching: whole-body noreorder asm in a noreturn C function. The callee 0x1afee8 has no
// functions.tsv row, so the j is numeric. The moves use daddu to match the reference bytes.
void func_001b0148(void) __attribute__((noreturn));
void func_001b0148(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "daddu\t$4,$5,$0\n\t"
        "sd\t$31,0($29)\n\t"
        "daddu\t$5,$7,$0\n\t"
        "bgez\t$6,agent_r46p35_b0148_ret\n\t"
        "daddu\t$2,$6,$0\n\t"
        "addiu\t$15,$0,-3\n\t"
        "bne\t$6,$15,agent_r46p35_b0148_ret\n\t"
        "addiu\t$2,$0,-1\n\t"
        "ld\t$31,0($29)\n\t"
        "j\t0x1afee8\n\t"
        "addiu\t$29,$29,16\n\t"
        "agent_r46p35_b0148_ret:\n\t"
        "ld\t$31,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$5", "$15", "memory");
}

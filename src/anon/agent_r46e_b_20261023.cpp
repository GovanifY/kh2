#include "../common/types.h"

// Agent R46e_b (2026-10-23): FUN_00154ee8 (72 bytes) and FUN_00136968 (80 bytes), SLPM_666.75.
//
// FUN_00154ee8: returns 67 when the word at +24 of arg0 is 1, otherwise 72. The original branches
// with bnel t6,t7 (branch-likely, delay slot li v0,72), which gcc 3.2 never emits, so the whole
// function is one noreorder asm block with the 18 words in the original order. gcc appends a dead
// jr ra; nop after the block, which lies past the 72-byte boundary.
//
// FUN_00136968: five stores after two calls, with the epilogue ld ra right after li t5,-1, then a
// tail jump with an addiu in the delay slot. The whole function is one noreorder asm block, with a
// gcc-owned prologue absent (no C locals), so the ld ra lands where the original has it.

extern "C" void func_001369d0(void);
extern "C" void func_001369f0(void);

// FUN_00154ee8 (72 bytes).
extern "C" void func_00154ee8(u32 a0);
void func_00154ee8(u32 a0) {
    asm volatile(
        ".set\tnoreorder\n\t"
        "lw\t$14,24($4)\n\t"
        "li\t$2,67\n\t"
        "li\t$15,1\n\t"
        "beq\t$14,$15,1f\n\t"
        "slti\t$13,$14,2\n\t"
        "beqzl\t$13,2f\n\t"
        "li\t$15,2\n\t"
        "beqz\t$14,3f\n\t"
        "nop\n\t"
        "li\t$2,72\n\t"
        "1:\n\t"
        "jr\t$31\n\t"
        "nop\n\t"
        "3:\n\t"
        "jr\t$31\n\t"
        "li\t$2,72\n\t"
        "2:\n\t"
        "bnel\t$14,$15,1b\n\t"
        "li\t$2,72\n\t"
        "b\t3b\n\t"
        "nop\n\t"
        ".set\treorder\n\t"
        : : : "memory", "$2", "$13", "$14", "$15");
}

// FUN_00136968 (80 bytes).
extern "C" void func_00136968(void);
void func_00136968(void) {
    asm volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "jal\tfunc_001369d0\n\t"
        "nop\n\t"
        "jal\tfunc_001369f0\n\t"
        "nop\n\t"
        "li\t$13,-1\n\t"
        "ld\t$31,0($29)\n\t"
        "lui\t$15,0x34\n\t"
        "lui\t$11,0x3c\n\t"
        "sw\t$13,32032($15)\n\t"
        "addiu\t$12,$11,-29920\n\t"
        "lui\t$14,0x3c\n\t"
        "sh\t$13,2($12)\n\t"
        "lui\t$15,0x34\n\t"
        "sw\t$13,-29896($14)\n\t"
        "sh\t$13,-29920($11)\n\t"
        "sw\t$13,32036($15)\n\t"
        "j\t0x136a50\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "memory", "$11", "$12", "$13", "$14", "$15");
}

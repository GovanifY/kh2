#include "../common/types.h"

// Agent X01 (2026-10-22): FUN_0016b040, FUN_0016b518, FUN_0016b740 (SLPM_666.75).

// FUN_0016b040 (44 bytes, asm body).
// Code: loads the float at a1+1644 into $f12 before the frame is saved, calls RotToDir
// (func_0017d0e8), then returns a0 (kept in s0).
// Matching: whole-body noreorder asm in a noreturn C function. The float load comes before
// sd s0 and the move into s0 sits in the jal delay slot, which plain C does not reproduce.
u32 func_0016b040(u32 a0, u32 a1) __attribute__((noreturn));
u32 func_0016b040(u32 a0, u32 a1) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lwc1\t$f12,1644($5)\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "jal\tfunc_0017d0e8\n\t"
        "move\t$16,$4\n\t"
        "move\t$2,$16\n\t"
        "ld\t$31,8($29)\n\t"
        "ld\t$16,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$5", "$f12", "memory");
}

// FUN_0016b518 (60 bytes, asm body).
// Code: if the word at a0+1416 has bit 4 set, returns func_00176db0(a0). Otherwise returns
// func_0016b558(a0, a2, a2, a3), with a1 replaced by a2 for that call only.
// Matching: whole-body noreorder asm in a noreturn C function. Plain C (and a volatile asm
// move) keeps the a1 = a2 copy in the beqz delay slot or before the jal, and gcc never fills
// the jal delay slot with it; the original has the move in the jal delay slot and the second
// path ends with "b" to the shared jr with ld ra in the delay slot.
u32 func_0016b518(u32 a0, u32 a1, u32 a2, u32 a3) __attribute__((noreturn));
u32 func_0016b518(u32 a0, u32 a1, u32 a2, u32 a3) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "lw\t$15,1416($4)\n\t"
        "andi\t$15,$15,0x4\n\t"
        "beqz\t$15,agent_x01_b518_second\n\t"
        "nop\n\t"
        "jal\tfunc_00176db0\n\t"
        "nop\n\t"
        "ld\t$31,0($29)\n\t"
        "agent_x01_b518_ret:\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        "agent_x01_b518_second:\n\t"
        "jal\tfunc_0016b558\n\t"
        "move\t$5,$6\n\t"
        "b\tagent_x01_b518_ret\n\t"
        "ld\t$31,0($29)\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$5", "$15", "memory");
}

// FUN_0016b740 (96 bytes, asm body).
// Code: if a0 == 566, returns the word at D_00350000 - 5816 (lui 0x35 / lw). Otherwise
// key = func_0016e920(a0) (kept in s0). Then loops: cur = func_001b9bc8(cur), starting at 0.
// The loop returns 0 when cur is 0, or cur when the word at cur+8 equals key.
// Matching: whole-body noreorder asm. The loop uses branch-likely (beqzl, beql) with the
// loads in the delay slots, which gcc 3.2 does not emit. The shared epilogue sits between the
// 566 path and the loop, as in the original.
u32 func_0016b740(u32 a0) __attribute__((noreturn));
u32 func_0016b740(u32 a0) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "addiu\t$15,$0,566\n\t"
        "sd\t$16,0($29)\n\t"
        "sd\t$31,8($29)\n\t"
        "bne\t$4,$15,agent_x01_b740_slow\n\t"
        "lui\t$15,0x35\n\t"
        "lw\t$2,-5816($15)\n\t"
        "ld\t$16,0($29)\n\t"
        "agent_x01_b740_ret:\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        "agent_x01_b740_slow:\n\t"
        "jal\tfunc_0016e920\n\t"
        "nop\n\t"
        "move\t$16,$2\n\t"
        "move\t$2,$0\n\t"
        "agent_x01_b740_loop:\n\t"
        "jal\tfunc_001b9bc8\n\t"
        "move\t$4,$2\n\t"
        "beqzl\t$2,agent_x01_b740_ret\n\t"
        "ld\t$16,0($29)\n\t"
        "lw\t$15,8($2)\n\t"
        "beql\t$15,$16,agent_x01_b740_ret\n\t"
        "ld\t$16,0($29)\n\t"
        "b\tagent_x01_b740_loop\n\t"
        "nop\n\t"
        ".set\treorder\n\t"
        : : : "$2", "$4", "$15", "memory");
}

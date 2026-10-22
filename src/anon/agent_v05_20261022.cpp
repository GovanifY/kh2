#include "../common/types.h"

// Agent V05 (2026-10-22): FUN_00160d70, FUN_00160e50, FUN_00160f10 (SLPM_666.75).
//
// All three have the same body (108 bytes each). They walk the singly linked list that starts at
// the word at 0x004f3b38, following the next pointer at +128. For each node whose word at +424
// equals the argument, they call a callee and continue the walk. The callees are:
//   FUN_00160d70 -> FUN_00160d18
//   FUN_00160e50 -> FUN_00160d38
//   FUN_00160f10 -> FUN_001604d8
//
// Matching: the loop uses bnezl (branch-likely, delay slot = the load of +128 or the head) and a
// bnez whose delay slot is `move s0,a0`. gcc 3.2 never emits branch-likely, and it rotates the
// loop, so the body is one noreorder asm block. The block contains the whole prologue, the
// loop, the epilogue and the out-of-line tail, in the original order. The `.align 4` before the
// tail puts the label at 0x160dc0 with the same nop as the original. gcc appends a dead jr ra;
// nop after the asm, which lies past the 108-byte boundary and is cut by normalize-cxx-layout.

extern "C" void func_00160d18(void);   // callee of FUN_00160d70
extern "C" void func_00160d38(void);   // callee of FUN_00160e50
extern "C" void func_001604d8(void);   // callee of FUN_00160f10

#define AGENT_V05_BODY(CALLEE) \
    asm volatile( \
        ".set\tnoreorder\n\t" \
        "addiu\t$29,$29,-32\n\t" \
        "sd\t$16,0($29)\n\t" \
        "sd\t$17,8($29)\n\t" \
        "sd\t$18,16($29)\n\t" \
        "move\t$16,$0\n\t" \
        "sd\t$31,24($29)\n\t" \
        "move\t$17,$4\n\t" \
        "lui\t$18,0x4f\n\t" \
        "1:\n\t" \
        "bnezl\t$16,2f\n\t" \
        "lw\t$4,128($16)\n\t" \
        "lw\t$4,15160($18)\n\t" \
        "2:\n\t" \
        "bnez\t$4,3f\n\t" \
        "move\t$16,$4\n\t" \
        "ld\t$16,0($29)\n\t" \
        "ld\t$17,8($29)\n\t" \
        "ld\t$18,16($29)\n\t" \
        "ld\t$31,24($29)\n\t" \
        "jr\t$31\n\t" \
        "addiu\t$29,$29,32\n\t" \
        ".align\t4\n\t" \
        "3:\n\t" \
        "lw\t$15,424($4)\n\t" \
        "bne\t$15,$17,1b\n\t" \
        "nop\n\t" \
        "jal\t" #CALLEE "\n\t" \
        "nop\n\t" \
        "b\t1b\n\t" \
        "nop\n\t" \
        ".set\treorder\n\t" \
        : : : "memory")

// FUN_00160d70 (108 bytes). Walks the list and calls FUN_00160d18 on each match.
void func_00160d70(u32 a0) __attribute__((noreturn));
void func_00160d70(u32 a0) {
    AGENT_V05_BODY(func_00160d18);
}

// FUN_00160e50 (108 bytes). Same walk, calls FUN_00160d38 on each match.
void func_00160e50(u32 a0) __attribute__((noreturn));
void func_00160e50(u32 a0) {
    AGENT_V05_BODY(func_00160d38);
}

// FUN_00160f10 (108 bytes). Same walk, calls FUN_001604d8 on each match.
void func_00160f10(u32 a0) __attribute__((noreturn));
void func_00160f10(u32 a0) {
    AGENT_V05_BODY(func_001604d8);
}

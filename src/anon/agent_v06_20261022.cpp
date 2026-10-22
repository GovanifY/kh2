#include "../common/types.h"

// Agent V06 (2026-10-22): FUN_00161030, FUN_00161248, FUN_00161548 (SLPM_666.75).
// Each comment says what the code does, then how the match is built.
// The list head is the word at D_004f0000 + 15160 (0x004f3b38). Each node keeps its next
// pointer at +128. The word at +432 of a node is a flag.

extern u8 D_004f0000[];

// Callees. Resolved through the func_<addr> linker symbols.
extern "C" void func_00160940(u32, u32, f32);   // called with (node, a0, a1) in FUN_00161248
extern "C" u32 func_00168b38(u32, u32, u32);    // called with (node, 9, a1) in FUN_00161548

// FUN_00161030 (72 bytes).
// Code: walks the list, counting only nodes whose +432 word is zero. Returns the node at index
// a0 among those (0-based), or 0 when the list ends first.
// Matching: the loop head is one noreorder asm block (bnezl with the next-pointer load in its
// delay slot, and the head load from the global). The shared "jr ra" is inside the same block,
// so the found path and the zero path reach it as in the original. The count increment is a C
// latch, which gives the back-edge its addiu in the delay slot. The object does not need an
// alignment flag (72 bytes), but the whole file is built with -falign-functions=1 for the others.
u32 func_00161030(u32 a0) {
    register u32 a0r asm("$4") = a0;
    register u32 t6 asm("$14") = 0;
    register u32 t5 asm("$13") = 0;
    register u32 t4 asm("$12");
    asm volatile("lui\t%0,%%hi(D_004f0000+15160)" : "=r"(t4));
    for (;;) {
        asm volatile(
            ".set noreorder\n\t"
            "1:\n\t"
            "bnezl\t$14,2f\n\t"
            "lw\t$2,128($14)\n\t"
            "lw\t$2,%%lo(D_004f0000+15160)($12)\n\t"
            "2:\n\t"
            "bnez\t$2,3f\n\t"
            "move\t$14,$2\n\t"
            "move\t$2,$0\n\t"
            "4:\n\t"
            "jr\t$31\n\t"
            "nop\n\t"
            "3:\n\t"
            "lw\t$15,432($2)\n\t"
            "bnez\t$15,1b\n\t"
            "nop\n\t"
            "beq\t$13,$4,4b\n\t"
            "nop\n\t"
            ".set reorder\n\t"
            : "+r"(t5), "+r"(t6)
            : "r"(a0r), "r"(t4)
            : "$2", "$15", "memory");
        t5 = t5 + 1;
    }
}

// FUN_00161248 (108 bytes).
// Code: saves s0..s2, ra and f20 (the float argument, copied from $f12). Walks the list from the
// global head. For each node it calls FUN_00160940(node, a0, a1). Returns when the list ends.
// Matching: the prologue is one asm block, because the original interleaves the float copy and
// the saves in an order gcc's prologue never produces. The loop (head, epilogue and call) is a
// second asm block inside an empty for loop, so gcc emits only the back-edge (b plus nop). The
// function is 108 bytes, so the object needs -falign-functions=1.
void func_00161248(u32 a0, f32 a1) {
    register u32 a0r asm("$4") = a0;
    register f32 f12r asm("$f12") = a1;
    asm volatile(
        ".set noreorder\n\t"
        "addiu\t$29,$29,-48\n\t"
        "swc1\t$f20,32($29)\n\t"
        "sd\t$16,0($29)\n\t"
        "mov.s\t$f20,$f12\n\t"
        "sd\t$17,8($29)\n\t"
        "sd\t$18,16($29)\n\t"
        "move\t$16,$0\n\t"
        "sd\t$31,24($29)\n\t"
        "move\t$17,$4\n\t"
        "lui\t$18,%%hi(D_004f0000+15160)\n\t"
        ".set reorder\n\t"
        : : "r"(a0r), "f"(f12r)
        : "memory");
    for (;;) {
        asm volatile(
            ".set noreorder\n\t"
            "1:\n\t"
            "bnezl\t$16,2f\n\t"
            "lw\t$4,128($16)\n\t"
            "lw\t$4,%%lo(D_004f0000+15160)($18)\n\t"
            "2:\n\t"
            "bnez\t$4,3f\n\t"
            "move\t$16,$4\n\t"
            "ld\t$16,0($29)\n\t"
            "ld\t$17,8($29)\n\t"
            "ld\t$18,16($29)\n\t"
            "ld\t$31,24($29)\n\t"
            "lwc1\t$f20,32($29)\n\t"
            "jr\t$31\n\t"
            "addiu\t$29,$29,48\n\t"
            "3:\n\t"
            "mov.s\t$f12,$f20\n\t"
            "jal\tfunc_00160940\n\t"
            "move\t$5,$17\n\t"
            ".set reorder\n\t"
            : : : "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                  "$f0", "$f12", "memory");
    }
}

// FUN_00161548 (76 bytes).
// Code: returns 0 when a1 < 0. Otherwise node = word at a0+64. Returns 0 when node is 0.
// Otherwise r = FUN_00168b38(node, 9, a1). Returns 0 when r is 0, else the word at r+8.
// Matching: the prologue, the first test and the zero path are one asm block with the
// original order. The shared epilogue (ld ra, jr ra, addiu sp) sits between that block and
// the post-call test, so the rest of the body is a second asm block inside an empty for loop.
// The latch load of v0 from the result is C, which gives the back-edge its lw in the delay
// slot. The object needs -falign-functions=1 (76 bytes).
u32 func_00161548(u8* a0, s32 a1) {
    register u8* a0r asm("$4") = a0;
    register s32 a1r asm("$5") = a1;
    register u32 v0 asm("$2");
    register u32 t7 asm("$15");
    asm volatile(
        ".set noreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "bltz\t$5,7f\n\t"
        "move\t$2,$0\n\t"
        "lw\t$15,64($4)\n\t"
        "bnez\t$15,8f\n\t"
        "move\t$4,$15\n\t"
        "move\t$2,$0\n\t"
        ".set reorder\n\t"
        : : "r"(a0r), "r"(a1r)
        : "$2", "$4", "$15", "memory");
    for (;;) {
        asm volatile(
            ".set noreorder\n\t"
            "7:\n\t"
            "ld\t$31,0($29)\n\t"
            "jr\t$31\n\t"
            "addiu\t$29,$29,16\n\t"
            "8:\n\t"
            "move\t$6,$5\n\t"
            "jal\tfunc_00168b38\n\t"
            "li\t$5,9\n\t"
            "move\t$15,$2\n\t"
            "beqz\t$15,7b\n\t"
            "move\t$2,$0\n\t"
            ".set reorder\n\t"
            : "=r"(t7), "+r"(v0)
            : "r"(a1r)
            : "$4", "$5", "$6", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "memory");
        v0 = *(u32*)(t7 + 8);
    }
}

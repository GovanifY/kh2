#include "../common/types.h"

// FUN_0016f470 (68 bytes)
// Code: if arg1 == 0 then s = 0x4f63b0. Calls FUN_002fee78(s, 0x36c440, arg0 + 8)
// (the fourth argument is passed through) and returns s.
// Guess: a "use the given pointer or a default table" helper that passes a
// record and a 0x36c440 data pointer to a loader.
extern u8 D_00370000;
extern u8 D_004f63b0;

extern "C" u32 func_002fee78_4(u32, u32, u32, u32) asm("func_002fee78");

__attribute__((noreturn)) void func_0016f470(u8* a0, u32 a1);
void func_0016f470(u8* a0, u32 a1) {
    register u32 r4 asm("$4") = (u32)a0;
    register u32 r5 asm("$5") = a1;
    u64 frame[1];
    asm volatile("" : "=m"(frame));
    asm volatile(
        ".set noreorder\n\t"
        "addiu $6,$4,8\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "bnez $5,1f\n\t"
        "move $16,$5\n\t"
        "lui $15,%%hi(D_004f63b0)\n\t"
        "addiu $16,$15,%%lo(D_004f63b0)\n\t"
        "1:\n\t"
        "lui $5,%%hi(D_00370000-15296)\n\t"
        "move $4,$16\n\t"
        "jal func_002fee78\n\t"
        "addiu $5,$5,%%lo(D_00370000-15296)\n\t"
        "move $2,$16\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : "+r"(r4), "+r"(r5) : : "$2", "$3", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
}

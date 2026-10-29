#include "../common/types.h"

// Agent R46p_28 (2026-10-29): FUN_001ac700 (40 bytes, SLPM_666.75).
// Stores 4 at +112 of a0, loads the word at +128 into a1, then tail-jumps to func_001991a8(34, a1)
// with the frame restored in the j delay slot.
// Matching: whole-body asm (form a). Plain C puts ld ra before the lw a1 and drops the move t6,a0;
// the asm writes the original order, with the frame in the asm itself and memory-only clobbers.
extern "C" void func_001991a8(u32, u32);


void func_001ac700(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $15,$0,4\n\t"
        "sd $31,0($29)\n\t"
        "daddu $14,$4,$0\n\t"
        "sw $15,112($4)\n\t"
        "lw $5,128($14)\n\t"
        "ld $31,0($29)\n\t"
        "addiu $4,$0,34\n\t"
        "j func_001991a8\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

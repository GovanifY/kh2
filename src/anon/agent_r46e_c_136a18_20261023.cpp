#include "../common/types.h"

// Agent R46e_c (2026-10-23), retry of FUN_00136a18 (56 bytes), from SLPM_666.75.
// Code: calls FUN_00136840(), then FUN_001369d0(), then sets the byte at 0x00347d28 to 1.
//       The original restores ra and sp, jumps (j) over an alignment nop to an 8-aligned
//       block, and returns from there with the store in the jr delay slot.
// Guess: runs two setup steps, then marks a flag byte at 0x347d28.
// Tricks: the two calls and the restore/jump part are one .set noreorder asm block, which
//         ends at an empty local label 1 placed right after the nop. The C store after it
//         gives gcc's own tail, li t6 / lui t7 / jr ra / sb, which is the original 8-aligned
//         block. The memory clobber keeps the store after the calls. No caller-saved
//         registers are listed, so gcc keeps a frame-less leaf (no prologue or epilogue).
//         Listing $14 as a clobber made gcc save s0 and add a frame, so it is left out.
extern u8 D_00347d28;

void func_00136a18(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29, $29, -16\n"
        "sd $31, 0($29)\n"
        "jal func_00136840\n"
        "nop\n"
        "jal func_001369d0\n"
        "nop\n"
        "ld $31, 0($29)\n"
        "j 1f\n"
        "addiu $29, $29, 16\n"
        "nop\n"
        "1:\n"
        ".set pop\n"
        :
        :
        : "memory", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$15", "$24", "$25");
    D_00347d28 = 1;
}

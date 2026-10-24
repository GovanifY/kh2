#include "../common/types.h"

// Agent R46e_c (2026-10-23), retry of FUN_0013e3b0 (96 bytes), from SLPM_666.75.
// Code: saves s0, s1 and ra, copies the 16-byte block at a1 to the stack and calls
//       FUN_001391a8(a0, sp). If FUN_00139d78(a0 + 448) returns non-zero, copies the same
//       block again and calls FUN_001391a8(a0 + 448, sp). Restores and returns.
// Guess: pushes a 16-byte record to a sub-object at +448 and, when a check passes, pushes it
//        once more.
// Tricks: the whole body is one .set noreorder asm block. gcc owns the 48-byte frame (unused
//         u64 local plus an "=m" output), so gcc emits the addiu sp prologue and jr/addiu
//         epilogue. The saves, the move s0,a1 and the beqzl with its ld s0 delay slot are
//         written in the original order inside the asm. s0, s1 and ra are not listed as
//         clobbers, so gcc does not add its own saves.
void func_0013e3b0(u32 a0, u32 a1) {
    u64 frame[6];
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "sd $16, 16($29)\n"
        "sd $17, 24($29)\n"
        "move $16, $5\n"
        "sd $31, 32($29)\n"
        "lq $8, 0($5)\n"
        "sq $8, 0($29)\n"
        "addiu $17, $4, 448\n"
        "jal func_001391a8\n"
        "move $5, $29\n"
        "jal func_00139d78\n"
        "move $4, $17\n"
        "beqzl $2, 1f\n"
        "ld $16, 16($29)\n"
        "lq $8, 0($16)\n"
        "sq $8, 0($29)\n"
        "move $4, $17\n"
        "jal func_001391a8\n"
        "move $5, $29\n"
        "ld $16, 16($29)\n"
        "1:\n"
        "ld $17, 24($29)\n"
        "ld $31, 32($29)\n"
        ".set pop\n"
        : "=m"(frame)
        : "r"(a0), "r"(a1)
        : "$2", "$3", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25"
    );
}

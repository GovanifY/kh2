#include "../common/types.h"

// Agent R46h_a (2026-10-23): three 84-byte functions from SLPM_666.75.
// Shape (all three alike): saves s0, s1, ra; s0 = a0; s1 = FUN_0022b688(id); copies the
// 16-byte block at s0 to the stack; FUN_001391a8(s1, sp); FUN_002251c8(event); returns s1.
// The body is one .set noreorder asm block. gcc owns the 48-byte frame (unused u64 local
// plus an "=m" output), so gcc emits the addiu sp prologue and the jr/addiu epilogue.
// The return value is pinned to $2 through the "=r" output, so gcc adds no move.
// Build with -falign-functions=1 (84 bytes is not a multiple of 8).

// FUN_0022ae98 (84 bytes)
u32 func_0022ae98(u8* a0) {
    register u32 rv asm("$2");
    u64 frame[6];
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "sd $16, 16($29)\n"
        "sd $17, 24($29)\n"
        "sd $31, 32($29)\n"
        "move $16, $4\n"
        "jal func_0022b688\n"
        "li $4, 142\n"
        "move $17, $2\n"
        "lq $8, 0($16)\n"
        "sq $8, 0($29)\n"
        "move $4, $2\n"
        "jal func_001391a8\n"
        "move $5, $29\n"
        "jal func_002251c8\n"
        "li $4, 12101\n"
        "move $2, $17\n"
        "ld $16, 16($29)\n"
        "ld $17, 24($29)\n"
        "ld $31, 32($29)\n"
        ".set pop\n"
        : "=r"(rv), "=m"(frame)
        :
        : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    return rv;
}

// FUN_0022aef0 (84 bytes): id 141, event 12102.
u32 func_0022aef0(u8* a0) {
    register u32 rv asm("$2");
    u64 frame[6];
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "sd $16, 16($29)\n"
        "sd $17, 24($29)\n"
        "sd $31, 32($29)\n"
        "move $16, $4\n"
        "jal func_0022b688\n"
        "li $4, 141\n"
        "move $17, $2\n"
        "lq $8, 0($16)\n"
        "sq $8, 0($29)\n"
        "move $4, $2\n"
        "jal func_001391a8\n"
        "move $5, $29\n"
        "jal func_002251c8\n"
        "li $4, 12102\n"
        "move $2, $17\n"
        "ld $16, 16($29)\n"
        "ld $17, 24($29)\n"
        "ld $31, 32($29)\n"
        ".set pop\n"
        : "=r"(rv), "=m"(frame)
        :
        : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    return rv;
}

// FUN_0022af48 (84 bytes): id 140, event 12103.
u32 func_0022af48(u8* a0) {
    register u32 rv asm("$2");
    u64 frame[6];
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "sd $16, 16($29)\n"
        "sd $17, 24($29)\n"
        "sd $31, 32($29)\n"
        "move $16, $4\n"
        "jal func_0022b688\n"
        "li $4, 140\n"
        "move $17, $2\n"
        "lq $8, 0($16)\n"
        "sq $8, 0($29)\n"
        "move $4, $2\n"
        "jal func_001391a8\n"
        "move $5, $29\n"
        "jal func_002251c8\n"
        "li $4, 12103\n"
        "move $2, $17\n"
        "ld $16, 16($29)\n"
        "ld $17, 24($29)\n"
        "ld $31, 32($29)\n"
        ".set pop\n"
        : "=r"(rv), "=m"(frame)
        :
        : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    return rv;
}

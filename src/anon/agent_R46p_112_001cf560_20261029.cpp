#include "../common/types.h"

// Agent R46p_112 (2026-10-29): FUN_001cf560 (80 bytes), form (b): top-level asm body. Saves s0, s1, ra in a 32-byte
// frame, calls func_001ca448(a0) with s1 = 0 in the delay slot, and uses a bnezl (branch-likely) so that
// li s1,1 runs only on the taken path. If the call result is zero, it compares the word at +340 with 44.
// Returns s1 through v0. gcc 3.2 does not emit bnezl from plain C, so the body is written out directly.
u32 r_FUN_001cf560(u8* a0) asm("func_001cf560");
#if 0
u32 r_FUN_001cf560(u8* a0) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_001cf560,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001cf560\n"
    ".type func_001cf560, @function\n"
    "func_001cf560:\n"
    "addiu $29,$29,-32\n"
    "sd $16,0($29)\n"
    "sd $17,8($29)\n"
    "sd $31,16($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1ca448\n"
    "daddu $17,$0,$0\n"
    "bnezl $2,2f\n"
    "addiu $17,$0,1\n"
    "lw $14,340($16)\n"
    "addiu $15,$0,44\n"
    "bne $14,$15,3f\n"
    "daddu $2,$17,$0\n"
    "addiu $17,$0,1\n"
    "2:\n"
    "daddu $2,$17,$0\n"
    "3:\n"
    "ld $16,0($29)\n"
    "ld $17,8($29)\n"
    "ld $31,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_001cf560, .-func_001cf560\n"
    ".text\n");

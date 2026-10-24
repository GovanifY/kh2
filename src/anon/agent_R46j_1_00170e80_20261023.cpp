#include "../common/types.h"

// Agent R46j_1 (2026-10-23): FUN_00170e80 (100 bytes), SLPM_666.75.
// Leaf list walk. Starts from the pointer at 0x34dca0 (node +60 is the next node). Skips a node
// whose word at +40 is >= 10000, and when the walk ends returns (word at 0x34dc9c) - t2, where t2 is
// 0x4fa440 or a sum of two node words updated on the way.
// Top-level asm (no prologue, no epilogue): the body is the original 25-instruction sequence.
u32 r_FUN_00170e80(void) asm("func_00170e80");
// Disabled definition text: the registry resolves the alias above only when this body exists.
#if 0
u32 r_FUN_00170e80(void) {
    return 0;
}
#endif

__asm__(
    ".section .text.func_00170e80,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00170e80\n"
    ".type func_00170e80, @function\n"
    "func_00170e80:\n"
    "lui $15,0x35\n"
    "lui $14,0x35\n"
    "lw $2,-9060($15)\n"
    "move $12,$0\n"
    "lw $11,-9056($14)\n"
    "lui $15,0x50\n"
    "addiu $10,$15,-23488\n"
    "1: beqz $12,2f\n"
    " move $13,$11\n"
    "lw $13,60($12)\n"
    "2: bnez $13,3f\n"
    " move $12,$13\n"
    "jr $31\n"
    " subu $2,$2,$10\n"
    "3: lw $14,40($13)\n"
    "slti $15,$14,10000\n"
    "xori $15,$15,1\n"
    "bnez $15,1b\n"
    " nop\n"
    "bltzl $14,1b\n"
    " lw $2,48($13)\n"
    "lw $14,44($13)\n"
    "lw $15,48($13)\n"
    "b 1b\n"
    " addu $10,$15,$14\n"
    ".set pop\n"
    ".size func_00170e80, .-func_00170e80\n"
    ".text\n");

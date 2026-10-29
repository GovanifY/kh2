#include "../common/types.h"

// FUN_001e7cc0 (96 bytes). Walks a singly linked list hanging off a0+116: calls 0x1e7be0(node) for each
// node, following the word at +0 of each node. Then clears a0+116. If a0+128 is non-zero, calls 0x1e7798
// with the global at 0x01d9e6e4 and clears a0+128.
// Whole-body asm in a noreturn function: the duplicated sw-zero in the delay slot of beqzl needs the asm form.
// Callees have no functions.tsv row, so jal is numeric.
void func_001e7cc0(u32 a0) __attribute__((noreturn));
void func_001e7cc0(u32 a0) {
    register u32 r4 asm("$4") = a0;
    asm volatile(
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $17,8($29)\n"
        "sd $16,0($29)\n"
        "sd $31,16($29)\n"
        "daddu $17,$4,$0\n"
        "lw $4,116($4)\n"
        "beqzl $4,1f\n"
        "sw $0,116($17)\n"
        "2:\n"
        "jal 0x1e7be0\n"
        "lw $16,0($4)\n"
        "bnez $16,2b\n"
        "daddu $4,$16,$0\n"
        "sw $0,116($17)\n"
        "1:\n"
        "lw $5,128($17)\n"
        "beqz $5,3f\n"
        "lui $15,0x1da\n"
        "jal 0x1e7798\n"
        "lw $4,-6428($15)\n"
        "sw $0,128($17)\n"
        "3:\n"
        "ld $16,0($29)\n"
        "ld $17,8($29)\n"
        "ld $31,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set reorder"
        : : "r"(r4) : "memory");
}

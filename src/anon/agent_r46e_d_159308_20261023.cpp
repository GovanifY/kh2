#include "../common/types.h"

// FUN_00159308 (92 bytes, 23 instructions). Whole body is one noreorder asm block. gcc supplies
// the 16-byte frame through an unused u128 local with an empty "=m" output, so gcc emits the
// addiu sp,-16 prologue and the asm does the ra save/restore, the flag test, the call and the
// tail jump in the original order. a0 is pinned to $4.
typedef int u128 __attribute__((mode(TI)));

void func_00159308(u32 a0) {
    register u32 p asm("$4") = a0;
    u128 tmp;
    asm volatile(
        ".set noreorder\n\t"
        "ld $15,8($4)\n\t"
        "lui $14,0x40\n\t"
        "sd $31,0($29)\n\t"
        "and $15,$15,$14\n\t"
        "beqz $15,1f\n\t"
        "ld $31,0($29)\n\t"
        "jal func_00162098\n\t"
        "nop\n\t"
        "bnez $2,2f\n\t"
        "lui $14,0x35\n\t"
        "lw $15,-22008($14)\n\t"
        "lui $13,0x37\n\t"
        "addiu $13,$13,-19660\n\t"
        "ld $31,0($29)\n\t"
        "xori $15,$15,1\n\t"
        "lwc1 $f12,0($13)\n\t"
        "sw $15,-22008($14)\n\t"
        "j func_00162058\n\t"
        "addiu $29,$29,16\n\t"
        "2:\n\t"
        "ld $31,0($29)\n\t"
        "1:\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : "=m"(tmp)
        : "r"(p)
        : "$2", "$3", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$f12", "memory");
    (void)tmp;
}

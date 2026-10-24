#include "../common/types.h"

// FUN_0010f9f0 (52 bytes, 13 instructions, leaf). Whole body is one noreorder asm block. Copies
// 16 bytes from a1 to a0+0xc00 with lq/sq through $8 unless the destination equals a1. Then sets
// bit 0x80 in the word at a0+0xb7c when (a2 & 0xff) != 0, else clears it. The shared "jr ra; sw"
// tail is reached by fallthrough from the set path and by a branch from the clear path.
// Needs -falign-functions=1 for this object (52 bytes).
void r_func_0010f9f0(u8* a0, u8* a1, u32 a2) asm("func_0010f9f0");

void r_func_0010f9f0(u8* a0, u8* a1, u32 a2) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $15,$4,3072\n\t"
        "beq $15,$5,1f\n\t"
        "andi $6,$6,0xff\n\t"
        "lq $8,0($5)\n\t"
        "sq $8,0($15)\n\t"
        "1:\n\t"
        "beqz $6,2f\n\t"
        "lw $15,2940($4)\n\t"
        "ori $15,$15,0x80\n\t"
        "3:\n\t"
        "jr $31\n\t"
        "sw $15,2940($4)\n\t"
        "2:\n\t"
        "li $14,-129\n\t"
        "b 3b\n\t"
        "and $15,$15,$14\n\t"
        ".set reorder"
        :
        :
        : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
}

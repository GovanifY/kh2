#include "../common/types.h"

// Agent R46k_2: FUN_00171518 (76 bytes), SLPM_666.75.
// Calls FUN_0016af58(sp buffer, word at +4 of *(arg0+0)). Then, unless the buffer is
// already at 0x01c5f480, copies 16 bytes from the buffer to 0x01c5f480. Stores 0x01c5f480
// at arg0+0 on both paths.
// The body is one noreorder asm block. gcc owns only the 32-byte frame (unused local plus a
// trailing empty asm), so the prologue is addiu sp and the epilogue is jr ra. The asm does
// the saves and restores itself, in the original order (ra before s0 on the way out).
typedef int u128 __attribute__((mode(TI)));

extern "C" void func_00171518(u32* a0);

void func_00171518(u32* a0) {
    u128 frame[2];
    asm volatile(
        ".set noreorder\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "move $16,$4\n\t"
        "lw $15,0($4)\n\t"
        "lw $5,4($15)\n\t"
        "jal func_0016af58\n\t"
        "move $4,$29\n\t"
        "lui $15,0x1c6\n\t"
        "addiu $15,$15,-2944\n\t"
        "beql $29,$15,1f\n\t"
        "sw $15,0($16)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($15)\n\t"
        "sw $15,0($16)\n"
        "1:\n\t"
        "ld $31,24($29)\n\t"
        "ld $16,16($29)\n\t"
        ".set reorder"
        : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
              "$14", "$15", "$24", "$25", "memory");
    asm volatile("" : "=m"(frame));
}

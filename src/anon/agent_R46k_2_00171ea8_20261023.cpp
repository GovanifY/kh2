#include "../common/types.h"

// Agent R46k_2: FUN_00171ea8 (88 bytes), SLPM_666.75.
// Calls FUN_001ca148(sp buffer, word at +4 of *(arg0+0), word at +4 of *(arg0+4), float at +8).
// Then the same guarded 16-byte copy and store to 0x01c5f480 as FUN_00171518.
// Same structure as FUN_00171518: gcc owns the frame, one noreorder asm body does the saves,
// call, copy, restores and the float load in the jal delay slot.
typedef int u128 __attribute__((mode(TI)));

extern "C" void func_00171ea8(u32* a0);

void func_00171ea8(u32* a0) {
    u128 frame[2];
    asm volatile(
        ".set noreorder\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "move $16,$4\n\t"
        "lw $14,0($4)\n\t"
        "lw $15,4($16)\n\t"
        "lw $5,4($14)\n\t"
        "move $4,$29\n\t"
        "lw $6,4($15)\n\t"
        "jal func_001ca148\n\t"
        "lwc1 $f12,8($16)\n\t"
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
              "$14", "$15", "$24", "$25", "$f12", "memory");
    asm volatile("" : "=m"(frame));
}

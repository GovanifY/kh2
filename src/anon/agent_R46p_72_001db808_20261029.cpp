#include "../common/types.h"

// FUN_001db808 (72 bytes)
// Code: stores a vtable pointer (0x352a38) at arg0[0], saves arg0 in s0, loads
// obj = arg0[4] and arg1 = arg0[12], calls the virtual slot at vtable[1] of obj with
// obj as this, then tail-jumps to 0x106420 with arg0 restored.
// Guess: destructor-like or initializer that dispatches a virtual call on a member.
// Whole-body asm: the tail jump has a numeric target (0x106420 is a Tz::LoadDataFree
// row with no callable symbol) and the epilogue loads interleave with it.
void func_001db808(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x35\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,10808\n\t"
        "sd $31,8($29)\n\t"
        "sw $15,0($4)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $13,4($4)\n\t"
        "lw $5,12($4)\n\t"
        "lw $15,0($13)\n\t"
        "lw $14,4($15)\n\t"
        "jalr $14\n\t"
        "daddu $4,$13,$0\n\t"
        "daddu $4,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "j 0x106420\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : : : "memory");
}

#include "../common/types.h"

// Agent R46f_b (2026-10-23): retry of FUN_001584f8 and FUN_00158548 (SLPM_666.75).
//
// FUN_001584f8 (76 bytes): r = FUN_00242ce8(a0). Loads the 64-bit word at a0 and ANDs it with
// the 64-bit entry at 0x0034a970 + (r * 2 + 1) * 8. Returns 1 if the result is non-zero, else 0.
//
// FUN_00158548 (88 bytes): r = FUN_00242ce8(a0) ^ 1, masked to a byte. Then ANDs the 64-bit word
// at a0 with the 64-bit entry at 0x0034a970 + (r * 2 + 1) * 8 and returns 1 if non-zero, else 0.
//
// Both use the whole-function noreorder asm body approach (as FUN_00158450 and FUN_001584a0),
// with the original instruction order: ld ra is placed after the lui/sll, and the restores come
// in the original order. The table base is built with literal lui/addiu, so no relocation. The
// call uses the registry symbol func_00242ce8. gcc appends a dead jr ra; nop after the asm,
// past the function boundary.

extern "C" void func_00242ce8(void);   // FUN_00242ce8, called with a0 in $4

void func_001584f8(void) __attribute__((noreturn));
void func_001584f8(void) {
    __asm__ volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal func_00242ce8\n\t"
        "move $16,$4\n\t"
        "lui $15,0x35\n\t"
        "ld $31,8($29)\n\t"
        "sll $14,$2,3\n\t"
        "addiu $15,$15,-22160\n\t"
        "addu $14,$14,$15\n\t"
        "ld $2,0($16)\n\t"
        "ld $13,16($14)\n\t"
        "ld $16,0($29)\n\t"
        "and $2,$2,$13\n\t"
        "sltu $2,$0,$2\n\t"
        "dsll32 $2,$2,0\n\t"
        "dsra32 $2,$2,0\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder" : : : "memory");
}

void func_00158548(void) __attribute__((noreturn));
void func_00158548(void) {
    __asm__ volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal func_00242ce8\n\t"
        "move $16,$4\n\t"
        "xori $2,$2,1\n\t"
        "ld $14,0($16)\n\t"
        "andi $2,$2,0xff\n\t"
        "ld $31,8($29)\n\t"
        "lui $15,0x35\n\t"
        "ld $16,0($29)\n\t"
        "addiu $15,$15,-22160\n\t"
        "sll $2,$2,3\n\t"
        "addu $2,$2,$15\n\t"
        "ld $13,16($2)\n\t"
        "and $14,$14,$13\n\t"
        "sltu $14,$0,$14\n\t"
        "dsll32 $14,$14,0\n\t"
        "dsra32 $14,$14,0\n\t"
        "move $2,$14\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder" : : : "memory");
}

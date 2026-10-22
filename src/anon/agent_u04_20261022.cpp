#include "../common/types.h"

u32 func_001a1de0(u32 a0);
void func_00138c10(u32 a0, u32 a1);

// FUN_00157aa0 (60 bytes)
// Code: s0 = a0. v = FUN_001a1de0(*(*(a0 + 52) + 1164)). Then tail-calls
// FUN_00138c10(a0 + 10000, v != 0 ? 111 : 117). The 117 default sits in the delay slot of
// the beqz; 111 is the fall-through store. The asm barrier on the pointer keeps the
// addiu a0,s0,10000 after the jal, as in the original.
// Guess: picks one of two codes (111 or 117) from a status result and sends it to a
// sub-object at +10000.
void func_00157aa0(u8* a0) {
    u8* s0 = a0;
    u32 v = func_001a1de0(*(u32*)(*(u32*)(s0 + 52) + 1164));
    register u8* p asm("$4");
    __asm__ volatile("addiu %0,%1,10000" : "=r"(p) : "r"(s0));
    u32 a1 = 117;
    if (v != 0) {
        __asm__ volatile("");
        a1 = 111;
    }
    func_00138c10((u32)p, a1);
}

// FUN_00158450 (76 bytes)
// Code: r = FUN_00242d58(a0). Loads the 64-bit word at a0 and ANDs it with the 64-bit
// entry at 0x0034a970 + r * 8. Returns 1 if the result is non-zero, else 0 (sign-extended).
// Guess: tests a 64-bit flag word at a0 against a per-index mask table.
// Written as one asm body: the compiler's branch-free code had the wrong instruction
// scheduling (ld ra placement and register use), and a C version could not reproduce it.
// The table base is built with the lui/addiu pair from literal constants, so no relocation.
s32 func_00158450(u8* a0) __attribute__((noreturn));
s32 func_00158450(u8* a0) {
    __asm__ volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal func_00242d58\n\t"
        "move $16,$4\n\t"
        "lui $15,0x35\n\t"
        "ld $31,8($29)\n\t"
        "sll $14,$2,3\n\t"
        "addiu $15,$15,-22160\n\t"
        "addu $14,$14,$15\n\t"
        "ld $2,0($16)\n\t"
        "ld $13,0($14)\n\t"
        "ld $16,0($29)\n\t"
        "and $2,$2,$13\n\t"
        "sltu $2,$0,$2\n\t"
        "dsll32 $2,$2,0\n\t"
        "dsra32 $2,$2,0\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder" : : "r"(a0) : "memory");
}

// FUN_001584a0 (88 bytes)
// Code: r = FUN_00242d58(a0) ^ 1, masked to a byte. Then ANDs the 64-bit word at a0 with
// the 64-bit entry at 0x0034a970 + r * 8 and returns 1 if non-zero, else 0.
// Guess: the opposite-sense version of FUN_00158450 for the same flag word.
// Same asm-body approach as FUN_00158450.
s32 func_001584a0(u8* a0) __attribute__((noreturn));
s32 func_001584a0(u8* a0) {
    __asm__ volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "jal func_00242d58\n\t"
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
        "ld $13,0($2)\n\t"
        "and $14,$14,$13\n\t"
        "sltu $14,$0,$14\n\t"
        "dsll32 $14,$14,0\n\t"
        "dsra32 $14,$14,0\n\t"
        "move $2,$14\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder" : : "r"(a0) : "memory");
}

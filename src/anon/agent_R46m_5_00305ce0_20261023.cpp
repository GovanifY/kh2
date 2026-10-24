#include "../common/types.h"

// FUN_00305ce0 (40 bytes): calls FUN_00316d08(), stores 5 through the returned pointer, returns -1.
// Whole-body asm (gcc emits the store before the epilogue load, and the original has the load
// first). The call goes to the registry symbol func_00316d08.
s32 func_00305ce0(void) __attribute__((noreturn));
s32 func_00305ce0(void) {
    __asm__ volatile(".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal func_00316d08\n\t"
        "nop\n\t"
        "li $3,5\n\t"
        "ld $31,0($29)\n\t"
        "sw $3,0($2)\n\t"
        "li $2,-1\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder" : : : "memory");
}

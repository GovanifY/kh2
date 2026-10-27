#include "../common/types.h"

// FUN_0018f248 (52 bytes): whole-body asm. Copies a0 into $15, loads the fields of *a0 and of the object,
// then tail-jumps to FUN_00186740 with a0..a3 and f12/f13 set.
void func_0018f248(u32* a0) __attribute__((noreturn));
void func_0018f248(u32* a0) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "move $15,$4\n\t"
        "sd $31,0($29)\n\t"
        "lw $14,0($4)\n\t"
        "lw $5,4($4)\n\t"
        "lwc1 $f13,20($15)\n\t"
        "lw $4,4($14)\n\t"
        "lw $6,8($15)\n\t"
        "lw $7,12($15)\n\t"
        "lwc1 $f12,16($15)\n\t"
        "ld $31,0($29)\n\t"
        "j func_00186740\n\t"
        "addiu $29,$29,16\n\t"
        ".set pop" : : "r"(a0));
}

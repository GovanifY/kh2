#include "../common/types.h"

// FUN_0018f9b8 (44 bytes): whole-body asm. Loads a0 from *a0 and the floats/ints of the object at $15,
// then tail-jumps to FUN_001a4d40.
void func_0018f9b8(u32* a0) __attribute__((noreturn));
void func_0018f9b8(u32* a0) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "move $15,$4\n\t"
        "sd $31,0($29)\n\t"
        "lw $4,0($4)\n\t"
        "lwc1 $f13,16($15)\n\t"
        "lw $5,4($15)\n\t"
        "lw $6,8($15)\n\t"
        "lwc1 $f12,12($15)\n\t"
        "ld $31,0($29)\n\t"
        "j func_001a4d40\n\t"
        "addiu $29,$29,16\n\t"
        ".set pop" : : "r"(a0));
}

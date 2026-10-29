#include "../common/types.h"

// FUN_001b6f48 (64 bytes): saves s0 and ra in a 16-byte frame, loads two floats from
// 0x0036dac4 and 0x0036dac8 (f12, f13), calls 0x17c870, then returns a0 in v0.
// Whole body is one noreorder asm block; the callee has no row, so the jal is numeric.
void func_001b6f48(u8* a0) __attribute__((noreturn));
void func_001b6f48(u8* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x37\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,-9532\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lwc1 $f12,0($15)\n\t"
        "lui $15,0x37\n\t"
        "addiu $15,$15,-9528\n\t"
        "jal 0x17c870\n\t"
        " lwc1 $f13,0($15)\n\t"
        "daddu $2,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

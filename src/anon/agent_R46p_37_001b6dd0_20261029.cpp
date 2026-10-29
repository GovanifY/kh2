#include "../common/types.h"

// FUN_001b6dd0 (56 bytes): saves s0 and ra in a 32-byte frame, copies 16 bytes from *a1
// to the frame, calls 0x17c4c8 with (a0 saved in s0, frame pointer), then stores 3 as a
// byte at s0+1300. Whole body is one noreorder asm block; the callee has no row, so the
// jal is numeric.
void func_001b6dd0(u8* a0, u8* a1) __attribute__((noreturn));
void func_001b6dd0(u8* a0, u8* a1) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lq $8,0($5)\n\t"
        "sq $8,0($29)\n\t"
        "jal 0x17c4c8\n\t"
        " daddu $5,$29,$0\n\t"
        "addiu $15,$0,3\n\t"
        "ld $31,24($29)\n\t"
        "sb $15,1300($16)\n\t"
        "ld $16,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

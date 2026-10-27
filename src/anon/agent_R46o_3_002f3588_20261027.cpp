#include "../common/types.h"

// FUN_002f3588 (40 bytes): leaf. If (a0 >> 28) == 7, a0 = (a0 & 0x0fffffff) | 0x80000000. Returns a0.
// Whole body is one noreorder asm block (the jr ra delay slot carries the return move).
u32 func_002f3588(u32 a0) __attribute__((noreturn));
u32 func_002f3588(u32 a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $3,$0,7\n\t"
        "srl $2,$4,28\n\t"
        "bne $2,$3,1f\n\t"
        " lui $2,0xfff\n\t"
        "lui $3,0x8000\n\t"
        "ori $2,$2,0xffff\n\t"
        "and $4,$4,$2\n\t"
        "or $4,$4,$3\n"
        "1:\n\t"
        "jr $31\n\t"
        " daddu $2,$4,$0\n\t"
        ".set reorder"
        ::: "memory");
}

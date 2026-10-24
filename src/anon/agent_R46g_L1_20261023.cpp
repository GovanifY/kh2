#include "../common/types.h"

// FUN_0016d640 (80 bytes)
// Code: frame of 32 bytes. Calls func_0017d5e8(&tmp, *(a0+0), f(a0+4)), where tmp is a
// 16-byte stack slot. Then stores 0x004f62a0 in t7. If tmp is at t7 it stores t7 to
// *a0 (branch-likely delay slot). Otherwise copies 16 bytes from tmp to t7 and stores t7 to *a0.
// Whole body is one noreorder asm block, so the frame and the beql shape match.
extern "C" void func_0017d5e8(void);

void func_0016d640(u8* a0) __attribute__((noreturn));
void func_0016d640(u8* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $5,0($4)\n\t"
        "lwc1 $f12,4($16)\n\t"
        "jal func_0017d5e8\n\t"
        " daddu $4,$29,$0\n\t"
        "lui $15,0x4f\n\t"
        "addiu $15,$15,25248\n\t"
        "beql $29,$15,1f\n\t"
        " sw $15,0($16)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($15)\n\t"
        "sw $15,0($16)\n"
        "1:\n\t"
        "ld $31,24($29)\n\t"
        "ld $16,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

// FUN_0016d800 (72 bytes)
// Code: frame of 32 bytes. Loads s0 = *a0, a2 = a0+4 word, f12 = a0+8 float. Calls
// func_0017d348(&tmp, s0, a2, f12). If tmp != s0 it copies 16 bytes from tmp to s0.
// Guess: a constructor-style step that writes a 16-byte vector to a pointed-to slot.
extern "C" void func_0017d348(void);

void func_0016d800(u8* a0) __attribute__((noreturn));
void func_0016d800(u8* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "daddu $15,$4,$0\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "lw $16,0($4)\n\t"
        "lw $6,4($15)\n\t"
        "lwc1 $f12,8($15)\n\t"
        "daddu $4,$29,$0\n\t"
        "jal func_0017d348\n\t"
        " daddu $5,$16,$0\n\t"
        "beql $16,$29,1f\n\t"
        " ld $16,16($29)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($16)\n\t"
        "ld $16,16($29)\n"
        "1:\n\t"
        "ld $31,24($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

// FUN_0016d8d0 (80 bytes)
// Code: same shape as FUN_0016d640. Calls func_0017d698(&tmp, *(a0+0), *(a0+4), f(a0+8)),
// then stores 0x004f62a0 to *a0, copying the 16-byte tmp to that address first unless
// tmp is already there.
extern "C" void func_0017d698(void);

void func_0016d8d0(u8* a0) __attribute__((noreturn));
void func_0016d8d0(u8* a0) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $5,0($4)\n\t"
        "lw $6,4($16)\n\t"
        "lwc1 $f12,8($16)\n\t"
        "jal func_0017d698\n\t"
        " daddu $4,$29,$0\n\t"
        "lui $15,0x4f\n\t"
        "addiu $15,$15,25248\n\t"
        "beql $29,$15,1f\n\t"
        " sw $15,0($16)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($15)\n\t"
        "sw $15,0($16)\n"
        "1:\n\t"
        "ld $31,24($29)\n\t"
        "ld $16,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        ::: "memory");
}

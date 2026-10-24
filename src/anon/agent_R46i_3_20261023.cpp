#include "../common/types.h"

// Batch R46i_3: three functions from SLPM_666.75 (lay36 lines 7, 11, 15 among remaining).
// Each body is one noreorder asm block (frame owned by asm, no C locals), as in the R46h_b batch.

// FUN_0016df28 (72 bytes)
// Code: frame of 16 bytes. f = float(*arg0) * *(float*)0x37c24c. r = FUN_0014aba8(). Tail-calls FUN_0014aa58(r, (int)f, 1).
void r_FUN_0016df28(void) asm("func_0016df28");

void r_FUN_0016df28(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x37\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,-15796\n\t"
        "sd $31,8($29)\n\t"
        "lwc1 $f1,0($15)\n\t"
        "lwc1 $f0,0($4)\n\t"
        "mul.s $f0,$f0,$f1\n\t"
        "cvt.w.s $f1,$f0\n\t"
        "jal func_0014aba8\n\t"
        "mfc1 $16,$f1\n\t"
        "daddu $5,$16,$0\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "daddu $4,$2,$0\n\t"
        "addiu $6,$0,1\n\t"
        "j func_0014aa58\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

// FUN_0016e200 (60 bytes)
// Code: frame of 16 bytes. s0 = arg0. v = FUN_001dc648(*arg0). If v != *(s0 + 4), copy the 16-byte value at *(s0+4) to v.
void r_FUN_0016e200(void) asm("func_0016e200");

void r_FUN_0016e200(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "jal _ZN3ryj6EFFECT5angleEv\n\t"
        "lw $4,0($4)\n\t"
        "lw $15,4($16)\n\t"
        "beq $2,$15,1f\n\t"
        "ld $16,0($29)\n\t"
        "lq $8,0($15)\n\t"
        "sq $8,0($2)\n\t"
        "ld $16,0($29)\n\t"
        "1:\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

// FUN_0016f4b8 (100 bytes)
// Code: frame of 16 bytes. If (byte at +72 of arg0) is 0, return 0. Otherwise s0 = arg1, or if arg1 == 0, s0 = 0x4f63d8.
// Then FUN_002fee78(s0, 0x36c450-ish pointer, arg0 + 8, *(word at 0x33caf0)). Return s0 (or 0 on the early exit).
void r_FUN_0016f4b8(void) asm("func_0016f4b8");

void r_FUN_0016f4b8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "addiu $6,$4,8\n\t"
        "sd $16,0($29)\n\t"
        "daddu $2,$0,$0\n\t"
        "sd $31,8($29)\n\t"
        "lbu $15,72($4)\n\t"
        "xori $15,$15,1\n\t"
        "andi $15,$15,1\n\t"
        "beqz $15,2f\n\t"
        "daddu $16,$5,$0\n\t"
        "bnez $5,1f\n\t"
        "lui $15,0x34\n\t"
        "lui $15,0x4f\n\t"
        "addiu $16,$15,25560\n\t"
        "lui $15,0x34\n\t"
        "1:\n\t"
        "lui $5,0x37\n\t"
        "lw $7,-13584($15)\n\t"
        "addiu $5,$5,-15280\n\t"
        "jal func_002fee78\n\t"
        "daddu $4,$16,$0\n\t"
        "daddu $2,$16,$0\n\t"
        "2:\n\t"
        "ld $16,0($29)\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

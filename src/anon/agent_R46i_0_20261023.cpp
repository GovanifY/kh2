#include "../common/types.h"

// Agent R46i_0 (2026-10-23): three 72-80 byte functions, SLPM_666.75. Each is one file-scope __asm__
// block (whole body, transcribed from the original), registered by asm label alias.
void r_FUN_0016d920(void) asm("func_0016d920");
void r_FUN_0016df70(void) asm("func_0016df70");
void r_FUN_0016e240(void) asm("func_0016e240");
#if 0
void r_FUN_0016d920(void) {
}
void r_FUN_0016df70(void) {
}
void r_FUN_0016e240(void) {
}
#endif

// FUN_0016d920 (72 bytes). Copies 16 bytes from *(a0->+4) to the stack, copies *(a0->+0) to sp+16,
// calls FUN_0017d160(sp+16, sp), stores the float result to a0+0.
__asm__(
    ".section .text.func_0016d920,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0016d920\n"
    ".type func_0016d920, @function\n"
    "func_0016d920:\n"
    "addiu $29,$29,-48\n"
    "sd $16,32($29)\n"
    "sd $31,40($29)\n"
    "daddu $16,$4,$0\n"
    "lw $15,4($4)\n"
    "lq $8,0($15)\n"
    "sq $8,0($29)\n"
    "addiu $4,$29,16\n"
    "lw $15,0($16)\n"
    "lq $8,0($15)\n"
    "sq $8,0($4)\n"
    "jal 0x17d160\n"
    "daddu $5,$29,$0\n"
    "swc1 $f0,0($16)\n"
    "ld $31,40($29)\n"
    "ld $16,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_0016d920, .-func_0016d920\n"
    ".text\n");

// FUN_0016df70 (72 bytes). f = float(a0[0]) * D_0037c250, i = trunc(f), then
// tail-calls FUN_0014aa80(FUN_0014aba8(a0, a1), i, 1).
__asm__(
    ".section .text.func_0016df70,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0016df70\n"
    ".type func_0016df70, @function\n"
    "func_0016df70:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x37\n"
    "sd $16,0($29)\n"
    "addiu $15,$15,-15792\n"
    "sd $31,8($29)\n"
    "lwc1 $f1,0($15)\n"
    "lwc1 $f0,0($4)\n"
    "mul.s $f0,$f0,$f1\n"
    "cvt.w.s $f1,$f0\n"
    "jal 0x14aba8\n"
    "mfc1 $16,$f1\n"
    "daddu $5,$16,$0\n"
    "ld $31,8($29)\n"
    "ld $16,0($29)\n"
    "daddu $4,$2,$0\n"
    "addiu $6,$0,1\n"
    "j 0x14aa80\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0016df70, .-func_0016df70\n"
    ".text\n");

// FUN_0016e240 (80 bytes). s1 = FUN_001dc648(*a0); FUN_0017d050(sp, a0[1]); if s1 != sp,
// copy the 16 bytes at sp to s1.
__asm__(
    ".section .text.func_0016e240,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0016e240\n"
    ".type func_0016e240, @function\n"
    "func_0016e240:\n"
    "addiu $29,$29,-48\n"
    "sd $16,16($29)\n"
    "sd $17,24($29)\n"
    "sd $31,32($29)\n"
    "daddu $16,$4,$0\n"
    "jal 0x1dc648\n"
    "lw $4,0($4)\n"
    "lw $5,4($16)\n"
    "daddu $17,$2,$0\n"
    "jal 0x17d050\n"
    "daddu $4,$29,$0\n"
    "beq $17,$29,r46i_c_join\n"
    "ld $16,16($29)\n"
    "lq $8,0($29)\n"
    "sq $8,0($17)\n"
    "ld $16,16($29)\n"
    "r46i_c_join: ld $17,24($29)\n"
    "ld $31,32($29)\n"
    "jr $31\n"
    "addiu $29,$29,48\n"
    ".set pop\n"
    ".size func_0016e240, .-func_0016e240\n"
    ".text\n");

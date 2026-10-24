#include "../common/types.h"

// FUN_0016e048 (72 bytes)
// Code: f = *(float*)arg0 * (float at 0x36c25c); n = (s32)f; then
// tail-calls FUN_0014aa80(FUN_0014aba8(), n, 0).
// Guess: scale a float by a tuning constant and pass the integer result to
// a queue or table call.
u32 func_0014aba8(void);
extern "C" u32 func_0014aa80_3(u8*, u32, u32) asm("func_0014aa80");
extern u8 D_00370000;

__attribute__((noreturn)) void func_0016e048(float* a0);
void func_0016e048(float* a0) {
    register float* r4 asm("$4") = a0;
    u64 frame[1];
    asm volatile("" : "=m"(frame));
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,%%hi(D_00370000-15780)\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,%%lo(D_00370000-15780)\n\t"
        "sd $31,8($29)\n\t"
        "lwc1 $f1,0($15)\n\t"
        "lwc1 $f0,0($4)\n\t"
        "mul.s $f0,$f0,$f1\n\t"
        "cvt.w.s $f1,$f0\n\t"
        "jal func_0014aba8\n\t"
        "mfc1 $16,$f1\n\t"
        "move $5,$16\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "move $4,$2\n\t"
        "move $6,$0\n\t"
        "j func_0014aa80\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder\n\t"
        : : "r"(r4) : "$2", "$3", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");

}

#include "../common/types.h"

// Agent R46l_0: FUN_00172a80 (96 bytes), SLPM_666.75.
// s0 = record(arg0)[+4][+2072]; if s0 is null, or (s0[+4] & 0xff & 1) is set, tail-calls
// FUN_0019a1a0(s0 path). Otherwise calls FUN_0019ae60(s0), then tail-calls FUN_0019a1a0 with a1 = 0.
// One noreorder asm body. The asm saves and restores s0 and ra itself (branch-likely forms
// are not emitted by gcc 3.2). gcc owns the 16-byte frame.
typedef int u128 __attribute__((mode(TI)));

extern "C" void func_0019ae60(void);
extern "C" void func_0019a1a0(void);
extern "C" void func_00172a80(u32* a0);

void func_00172a80(u32* a0) {
    u128 frame[1];
    asm volatile(
        ".set noreorder\n\t"
        "sd $16,0($29)\n\t"
        "sd $31,8($29)\n\t"
        "lw $15,0($4)\n\t"
        "lw $14,4($15)\n\t"
        "lw $16,2072($14)\n\t"
        "beqzl $16,1f\n\t"
        "ld $16,0($29)\n\t"
        "lw $15,4($16)\n\t"
        "andi $15,$15,0x1\n\t"
        "andi $15,$15,0xff\n\t"
        "bnezl $15,1f\n\t"
        "ld $16,0($29)\n\t"
        "jal func_0019ae60\n\t"
        "move $4,$16\n\t"
        "move $4,$16\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "move $5,$0\n\t"
        "j func_0019a1a0\n\t"
        "addiu $29,$29,16\n\t"
        "1:\n\t"
        "ld $31,8($29)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "$4", "$5", "$14", "$15", "memory");
    asm volatile("" : "=m"(frame));
}

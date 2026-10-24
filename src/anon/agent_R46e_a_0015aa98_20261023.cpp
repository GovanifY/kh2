#include "../common/types.h"

// Agent R46e_a (2026-10-23): FUN_0015aa98 (92 bytes), SLPM_666.75.
// Code: frame of 48 bytes. Saves f20, s1, s2, s0, ra in the original interleaved order, copies
// the float arg into f20, the a2 arg into s1 and a1 into s2, s0 = a0. Calls func_001391c8(s0, 11000, 0).
// Then stores s1 at +32, s2 at +24 and f20 at +28 on s0, restores and returns.
// Matching: the whole function is one noreorder asm block with no C locals, so gcc emits no
// prologue of its own (no frame, no callee-saved uses it knows about). The asm writes the
// prologue in the original order itself. gcc's trailing jr ra; nop falls past the 92-byte boundary.
extern "C" void func_001391c8(u32, u32, u32);

void r_FUN_0015aa98(void) asm("func_0015aa98");

void r_FUN_0015aa98(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-48\n\t"
        "swc1 $f20,32($29)\n\t"
        "sd $17,8($29)\n\t"
        "mov.s $f20,$f12\n\t"
        "sd $18,16($29)\n\t"
        "sd $16,0($29)\n\t"
        "daddu $17,$6,$0\n\t"
        "sd $31,24($29)\n\t"
        "daddu $18,$5,$0\n\t"
        "daddu $16,$4,$0\n\t"
        "addiu $5,$0,11000\n\t"
        "jal func_001391c8\n\t"
        " daddu $6,$0,$0\n\t"
        "sw $17,32($16)\n\t"
        "sw $18,24($16)\n\t"
        "swc1 $f20,28($16)\n\t"
        "ld $17,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "ld $18,16($29)\n\t"
        "ld $31,24($29)\n\t"
        "lwc1 $f20,32($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,48\n\t"
        ".set reorder"
        ::: "memory");
}

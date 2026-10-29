#include "../common/types.h"

// Agent R46p_32 (2026-10-29): FUN_001a78c0 (88 bytes), SLPM_666.75.
// Code: frame of 80 bytes. Saves f14/f15 (float args) in f20/f21 and s0 = a0. Calls
// func_001a7a48(&tmp) with a 16-byte stack slot tmp at sp, then calls func_001a7da8(a0, f14, f15, &tmp).
// Returns a0 in v0. Neither callee has a functions.tsv row, so both are reached by numeric jal in asm.
// Form: whole-body asm (form a), noreturn C function with the full frame inside the asm.
void func_001a78c0(void* a0, float a1, float a2) __attribute__((noreturn));
void func_001a78c0(void* a0, float a1, float a2) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-80\n\t"
        "swc1 $f21,68($29)\n\t"
        "swc1 $f20,64($29)\n\t"
        "mov.s $f21,$f15\n\t"
        "sd $16,48($29)\n\t"
        "mov.s $f20,$f14\n\t"
        "sd $31,56($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "jal 0x1a7a48\n\t"
        " daddu $4,$29,$0\n\t"
        "mov.s $f12,$f20\n\t"
        "daddu $4,$16,$0\n\t"
        "mov.s $f13,$f21\n\t"
        "jal 0x1a7da8\n\t"
        " daddu $5,$29,$0\n\t"
        "daddu $2,$16,$0\n\t"
        "ld $31,56($29)\n\t"
        "ld $16,48($29)\n\t"
        "lwc1 $f21,68($29)\n\t"
        "lwc1 $f20,64($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,80\n\t"
        ".set reorder"
        ::: "memory");
}

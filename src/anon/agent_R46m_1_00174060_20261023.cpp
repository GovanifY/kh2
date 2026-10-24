#include "../common/types.h"

// Agent R46m_1: FUN_00174060 (44 bytes), SLPM_666.75.
// Code: frame, t7 = word at +0 of arg0, a2 = word at +12, t6 = word at +4 of t7, f12 = float at
// +4 of arg0, a1 = word at +8, ld ra, tail jump to func_00199468 with a0 = t6.
// Matching: whole-body noreorder asm in a noreturn C function. Plain C moves arg0 to a
// callee-saved temporary first and reorders the loads and the sd ra.
void func_00174060(u32* s) __attribute__((noreturn));
void func_00174060(u32* s) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "lw\t$15,0($4)\n\t"
        "lw\t$6,12($4)\n\t"
        "lw\t$14,4($15)\n\t"
        "lwc1\t$f12,4($4)\n\t"
        "lw\t$5,8($4)\n\t"
        "ld\t$31,0($29)\n\t"
        "move\t$4,$14\n\t"
        "j\tfunc_00199468\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$5", "$6", "$14", "$15", "$f12", "memory");
}

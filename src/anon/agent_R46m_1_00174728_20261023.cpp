#include "../common/types.h"

// Agent R46m_1: FUN_00174728 (44 bytes), SLPM_666.75.
// Code: frame, f14 = float at +12 of arg0, t7 = word at +0, f12 = float at +4, f13 = float at +8,
// ld ra, a0 = word at +4 of t7 + 2248, tail jump to func_001ad990.
// Matching: whole-body noreorder asm in a noreturn C function (the float loads sit before the
// t7 load, and the ld ra sits between the float loads and the a0 computation).
void func_00174728(u32* s) __attribute__((noreturn));
void func_00174728(u32* s) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "lwc1\t$f14,12($4)\n\t"
        "lw\t$15,0($4)\n\t"
        "lwc1\t$f12,4($4)\n\t"
        "lwc1\t$f13,8($4)\n\t"
        "ld\t$31,0($29)\n\t"
        "lw\t$4,4($15)\n\t"
        "addiu\t$4,$4,2248\n\t"
        "j\tfunc_001ad990\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$15", "$f12", "$f13", "$f14", "memory");
}

#include "../common/types.h"

// Agent R46m_1: FUN_00175108 (36 bytes), SLPM_666.75.
// Code: frame, then a0 = word at +0 of arg0, a1 = word at +4, a2 = word at +8 (loads from arg0
// itself), ld ra, then tail jump to func_001a2438 with a0 replaced by the first word.
// Matching: whole-body noreorder asm in a noreturn C function. Plain C loads the first word into
// a0 early and moves the arg0 pointer into t7 first, so the loads differ from the original order.
void func_00175108(u32* p) __attribute__((noreturn));
void func_00175108(u32* p) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "sd\t$31,0($29)\n\t"
        "lw\t$15,0($4)\n\t"
        "lw\t$6,8($4)\n\t"
        "lw\t$5,4($4)\n\t"
        "ld\t$31,0($29)\n\t"
        "move\t$4,$15\n\t"
        "j\tfunc_001a2438\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$5", "$6", "$15", "memory");
}

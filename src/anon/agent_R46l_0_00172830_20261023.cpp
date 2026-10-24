#include "../common/types.h"

// Agent R46l_0: FUN_00172830 (36 bytes), SLPM_666.75.
// Tail call: f12 = float arg0[+4]; a0 = (arg0->record[+4]) + 1184; j YS::LOOKAT::release(float).
// One noreorder asm body. gcc owns the 16-byte frame (unused local plus a trailing empty asm).
typedef int u128 __attribute__((mode(TI)));

extern "C" void func_00172830(u32* a0);

void func_00172830(u32* a0) {
    u128 frame[1];
    asm volatile(
        ".set noreorder\n\t"
        "sd $31,0($29)\n\t"
        "lw $15,0($4)\n\t"
        "lwc1 $f12,4($4)\n\t"
        "ld $31,0($29)\n\t"
        "lw $4,4($15)\n\t"
        "addiu $4,$4,1184\n\t"
        "j _ZN2YS6LOOKAT7releaseEf\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "$4", "$15", "$f12", "memory");
    asm volatile("" : "=m"(frame));
}

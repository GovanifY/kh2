#include "../common/types.h"

// Agent R46l_0: FUN_00172078 (44 bytes), SLPM_666.75.
// Tail call: a0 is an object whose +0 word points to a record; calls FUN_001945a0 with
// t = record[+4], a1 = obj[+4], a2 = obj[+8], f12 = float obj[+12].
// One noreorder asm body. gcc owns the 16-byte frame (unused local plus a trailing empty asm).
typedef int u128 __attribute__((mode(TI)));

extern "C" void func_001945a0(void);
extern "C" void func_00172078(u32* a0);

void func_00172078(u32* a0) {
    u128 frame[1];
    asm volatile(
        ".set noreorder\n\t"
        "sd $31,0($29)\n\t"
        "lw $15,0($4)\n\t"
        "lwc1 $f12,12($4)\n\t"
        "lw $14,4($15)\n\t"
        "lw $5,4($4)\n\t"
        "lw $6,8($4)\n\t"
        "ld $31,0($29)\n\t"
        "move $4,$14\n\t"
        "j func_001945a0\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "$4", "$5", "$6", "$14", "$15", "$f12", "memory");
    asm volatile("" : "=m"(frame));
}

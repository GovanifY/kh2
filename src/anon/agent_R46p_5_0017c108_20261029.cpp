#include "../common/types.h"

// FUN_0017c108 (88 bytes): obj = a1. Tests obj->+352 bit 0x4 (tail-call), or bit 0x10 with a2 != 0,
// then tail-calls FUN_0017f540(obj + 320, a2, float at 0x36c500, 0.0f). Otherwise returns.
// Whole-body noreorder asm: plain C put the lui/mtc1/addiu/ld ra slots in a different order, and
// the move a0,a1 must come before the ld ra store with the addiu after it.
extern "C" void func_0017f540(u32, u32, float, float);

void r_FUN_0017c108(void) asm("func_0017c108");

void r_FUN_0017c108(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "move $4,$5\n\t"
        "sd $31,0($29)\n\t"
        "addiu $4,$4,320\n\t"
        "lw $15,352($5)\n\t"
        "andi $14,$15,0x10\n\t"
        "andi $15,$15,0x4\n\t"
        "bnez $15,1f\n\t"
        " move $5,$6\n\t"
        "beqz $14,2f\n\t"
        " ld $31,0($29)\n\t"
        "beqz $6,2f\n\t"
        " nop\n\t"
        "1:\n\t"
        "lui $15,0x37\n\t"
        "mtc1 $0,$f13\n\t"
        "addiu $15,$15,-15104\n\t"
        "ld $31,0($29)\n\t"
        "lwc1 $f12,0($15)\n\t"
        "j func_0017f540\n\t"
        " addiu $29,$29,16\n\t"
        "2:\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

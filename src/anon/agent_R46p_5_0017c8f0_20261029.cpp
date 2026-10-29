#include "../common/types.h"

// FUN_0017c8f0 (64 bytes): calls FUN_0017c870(obj, float at 0x36c524, float at 0x36c528) and returns obj.
// Whole-body noreorder asm (same form as R46e_a): the lui/addiu pairs for the two float constants sit
// in the original order around the sd ra and move s0,a0; the jal delay slot holds lwc1 f13.
void r_FUN_0017c8f0(void) asm("func_0017c8f0");

void r_FUN_0017c8f0(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,0x37\n\t"
        "sd $16,0($29)\n\t"
        "addiu $15,$15,-15068\n\t"
        "sd $31,8($29)\n\t"
        "move $16,$4\n\t"
        "lwc1 $f12,0($15)\n\t"
        "lui $15,0x37\n\t"
        "addiu $15,$15,-15064\n\t"
        "jal 0x17c870\n\t"
        " lwc1 $f13,0($15)\n\t"
        "move $2,$16\n\t"
        "ld $31,8($29)\n\t"
        "ld $16,0($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

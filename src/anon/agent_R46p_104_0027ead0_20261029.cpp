#include "../common/types.h"

// Agent R46p_104 (2026-10-29): FUN_0027ead0 (60 bytes, SLPM_666.75).
// Whole-body asm (form a). Reads a signed byte at 0x36xxxx-3508 and a word at 0x36xxxx-3516 (into a0), multiplies
// the byte by 6 with the R5900 3-operand mult (raw .word), adds 0x37xxxx+16464 and loads a halfword at +4 into a1,
// then tail-jumps to 0x28da70. The mult and addu are raw .word encodings.
void func_0027ead0(void) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "lui $15,0x36\n"
        "sd $31,0($29)\n"
        "addiu $14,$0,6\n"
        "lui $13,0x36\n"
        "lb $12,-3508($15)\n"
        "lw $4,-3516($13)\n"
        ".word 0x018e6018\n"
        "ld $31,0($29)\n"
        "lui $15,0x37\n"
        "addiu $15,$15,16464\n"
        ".word 0x018f6021\n"
        "lh $5,4($12)\n"
        "j 0x28da70\n"
        "addiu $29,$29,16\n"
        ".set pop\n"
        :
        :
        : "memory");
}

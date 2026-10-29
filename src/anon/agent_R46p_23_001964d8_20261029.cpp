#include "../common/types.h"

// Agent R46p_23 (2026-10-29): FUN_001964d8 (100 bytes), SLPM_666.75.
// Stack buffer at sp+16 is filled by FUN_00196328(buf, a0); its first 10 bytes are copied to sp+0..9
// through ldl/ldr/sdl/sdr; then FUN_001967f0(buf[0], buf[1], 1) is called. The 0xffff stores before
// the copy are dead but gcc would drop them, so the whole body is one noreorder asm block.
// FUN_001967f0 has no registry row, so its jal is numeric.
void r_FUN_001964d8(void) asm("func_001964d8");

void r_FUN_001964d8(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-48\n\t"
        "ori $15,$0,0xffff\n\t"
        "sd $31,32($29)\n\t"
        "daddu $5,$4,$0\n\t"
        "sh $15,8($29)\n\t"
        "addiu $4,$29,16\n\t"
        "sb $15,0($29)\n\t"
        "sb $15,1($29)\n\t"
        "sb $15,2($29)\n\t"
        "sh $15,4($29)\n\t"
        "jal func_00196328\n\t"
        " sh $15,6($29)\n\t"
        "ldl $12,23($29)\n\t"
        "ldr $12,16($29)\n\t"
        "lh $13,24($29)\n\t"
        "sdl $12,7($29)\n\t"
        "sdr $12,0($29)\n\t"
        "sh $13,8($29)\n\t"
        "addiu $6,$0,1\n\t"
        "lbu $4,0($29)\n\t"
        "jal 0x1967f0\n\t"
        " lbu $5,1($29)\n\t"
        "ld $31,32($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,48\n\t"
        ".set reorder"
        :
        :
        : "memory");
}

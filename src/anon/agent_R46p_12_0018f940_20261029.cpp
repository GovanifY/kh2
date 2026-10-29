#include "../common/types.h"

// Agent R46p_12 (2026-10-29): FUN_0018f940 (104 bytes, SLPM_666.75).
// If the flag byte at 0x1c60cf0 is clear, set it and call 0x2fd188(0x190c8). Then call 0x1a4b78(sp, *arg0)
// and copy the 16-byte stack temp to 0x1c60d00 unless the stack temp is already there. The word at
// *arg0 is stored as 0x1c60d00 in both paths.
// Matching: plain C gives beq with the copy in the delay slot, not the original beql. gcc 3.2 has no
// branch-likely, so the whole body is one file-scope asm block with the original instruction order.
void r_FUN_0018f940(void) asm("func_0018f940");
#if 0
void r_FUN_0018f940(void) {
}
#endif

__asm__(
    ".section .text.func_0018f940,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0018f940\n"
    ".type func_0018f940, @function\n"
    "func_0018f940:\n"
    "addiu $29,$29,-32\n"
    "lui $14,0x1c6\n"
    "sd $16,16($29)\n"
    "sd $31,24($29)\n"
    "lb $15,3312($14)\n"
    "bne $15,$0,agent_R46p_12_0018f940_L1\n"
    "daddu $16,$4,$0\n"
    "addiu $15,$0,1\n"
    "lui $4,0x19\n"
    "sb $15,3312($14)\n"
    "jal 0x2fd188\n"
    "addiu $4,$4,200\n"
    "agent_R46p_12_0018f940_L1:\n"
    "lw $5,0($16)\n"
    "jal 0x1a4b78\n"
    "daddu $4,$29,$0\n"
    "lui $15,0x1c6\n"
    "addiu $15,$15,3328\n"
    "beql $29,$15,agent_R46p_12_0018f940_L2\n"
    "sw $15,0($16)\n"
    "lq $8,0($29)\n"
    "sq $8,0($15)\n"
    "sw $15,0($16)\n"
    "agent_R46p_12_0018f940_L2:\n"
    "ld $31,24($29)\n"
    "ld $16,16($29)\n"
    "jr $31\n"
    "addiu $29,$29,32\n"
    ".set pop\n"
    ".size func_0018f940, .-func_0018f940\n"
    ".text\n");

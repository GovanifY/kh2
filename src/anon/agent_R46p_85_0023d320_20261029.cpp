#include "../common/types.h"

// Agent R46p_85 (2026-10-29): FUN_0023d320 (72 bytes, SLPM_666.75).
// Loads the word at 0x350000-25060 and stores it at 0x360000-5292. Stores the byte
// (0x350000-25056 == 0) at 0x360000-5296. If that byte is non-zero, calls dk::Vsync::setFrameType(1).
// Then tail-calls dk::Vsync::setLimit(0).
// Matching: plain C gives different register assignment and hoists the li. The whole body is one
// file-scope asm block with the original instruction order.
void r_FUN_0023d320(void) asm("func_0023d320");
#if 0
void r_FUN_0023d320(void) {
}
#endif

__asm__(
    ".section .text.func_0023d320,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_0023d320\n"
    ".type func_0023d320, @function\n"
    "func_0023d320:\n"
    "addiu $29,$29,-16\n"
    "lui $15,0x35\n"
    "sd $31,0($29)\n"
    "lui $14,0x35\n"
    "lw $12,-25060($14)\n"
    "lbu $13,-25056($15)\n"
    "lui $15,0x36\n"
    "sltiu $13,$13,1\n"
    "sw $12,-5292($15)\n"
    "lui $15,0x36\n"
    "beqz $13,agent_R46p_85_0023d320_L1\n"
    "sb $13,-5296($15)\n"
    "jal 0x14ce20\n"
    "addiu $4,$0,1\n"
    "agent_R46p_85_0023d320_L1:\n"
    "ld $31,0($29)\n"
    "daddu $4,$0,$0\n"
    "j 0x14ce30\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_0023d320, .-func_0023d320\n"
    ".text\n");

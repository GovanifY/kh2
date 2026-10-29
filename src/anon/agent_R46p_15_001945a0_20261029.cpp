#include "../common/types.h"

// FUN_001945a0 (108 bytes). Whole-body asm (form b): calls func_001bfd60(this+2272, a1, f12, a2),
// stores the four bytes of a2 at +4..+7 of the returned pointer (little endian), loads the float
// at D_00370000-12544 and tail-calls func_001ad990(ret+8, 0.0f, that float, f12).
void r_FUN_001945a0(void) asm("func_001945a0");
#if 0
void r_FUN_001945a0(void) {
}
#endif

__asm__(
    ".section .text.func_001945a0,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001945a0\n"
    ".type func_001945a0, @function\n"
    "func_001945a0:\n"
    "addiu $29,$29,-32\n"
    "addiu $4,$4,2272\n"
    "swc1 $f20,16($29)\n"
    "sd $16,0($29)\n"
    "mov.s $f20,$f12\n"
    "sd $31,8($29)\n"
    "jal 0x1bfd60\n"
    "daddu $16,$6,$0\n"
    "lui $14,0x37\n"
    "mov.s $f14,$f20\n"
    "addiu $14,$14,-12544\n"
    "sb $16,4($2)\n"
    "lwc1 $f13,0($14)\n"
    "addiu $15,$2,4\n"
    "srl $12,$16,24\n"
    "mtc1 $0,$f12\n"
    "srl $14,$16,8\n"
    "sb $12,3($15)\n"
    "srl $13,$16,16\n"
    "sb $14,1($15)\n"
    "sb $13,2($15)\n"
    "addiu $4,$2,8\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "lwc1 $f20,16($29)\n"
    "j 0x1ad990\n"
    "addiu $29,$29,32\n"
    "nop\n"
    ".set pop\n"
    ".size func_001945a0, .-func_001945a0\n"
    ".text\n");

#include "../common/types.h"

// Agent R46l_3 (2026-10-23): three tail-call wrappers, whole-body asm (SLPM_666.75).
// FUN_001727c8 (52 bytes): ld/lwc1 setup from arg0, then j FUN_001b0798 with $f12 set.
// FUN_00172a10 (64 bytes): conditional jal to 0x19ba60, then j set_unit_arg with a0/a1/a2 from the object.
// FUN_00172f00 (44 bytes): loads a0..a3 from the object, then j FUN_00187a18.

void r_FUN_001727c8(void) asm("func_001727c8");
#if 0
void r_FUN_001727c8(void) {
}
#endif

__asm__(
    ".section .text.func_001727c8,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001727c8\n"
    ".type func_001727c8, @function\n"
    "func_001727c8:\n"
    "addiu $29,$29,-16\n"
    "daddu $15,$4,$0\n"
    "sd $31,0($29)\n"
    "addiu $6,$0,1\n"
    "lw $13,4($4)\n"
    "lw $14,0($4)\n"
    "lw $5,4($13)\n"
    "lw $4,4($14)\n"
    "lwc1 $f12,8($15)\n"
    "ld $31,0($29)\n"
    "addiu $4,$4,1184\n"
    "j func_001b0798\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001727c8, .-func_001727c8\n"
    ".text\n");

void r_FUN_00172a10(void) asm("func_00172a10");
#if 0
void r_FUN_00172a10(void) {
}
#endif

__asm__(
    ".section .text.func_00172a10,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00172a10\n"
    ".type func_00172a10, @function\n"
    "func_00172a10:\n"
    "addiu $29,$29,-16\n"
    "sd $16,0($29)\n"
    "sd $31,8($29)\n"
    "lw $15,0($4)\n"
    "beq $15,$0,1f\n"
    "daddu $16,$4,$0\n"
    "jal _Z16ctarget_0019ba60jjjj\n"
    "lw $4,4($15)\n"
    "lw $15,0($16)\n"
    "1:\n"
    "lw $6,8($16)\n"
    "lw $5,4($16)\n"
    "lw $4,4($15)\n"
    "ld $16,0($29)\n"
    "ld $31,8($29)\n"
    "j _ZN2YS3OBJ12set_unit_argEii\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00172a10, .-func_00172a10\n"
    ".text\n");

void r_FUN_00172f00(void) asm("func_00172f00");
#if 0
void r_FUN_00172f00(void) {
}
#endif

__asm__(
    ".section .text.func_00172f00,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_00172f00\n"
    ".type func_00172f00, @function\n"
    "func_00172f00:\n"
    "addiu $29,$29,-16\n"
    "daddu $15,$4,$0\n"
    "sd $31,0($29)\n"
    "addiu $8,$4,16\n"
    "lw $7,12($4)\n"
    "lw $5,4($15)\n"
    "lw $4,0($4)\n"
    "lw $6,8($15)\n"
    "ld $31,0($29)\n"
    "j func_00187a18\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_00172f00, .-func_00172f00\n"
    ".text\n");

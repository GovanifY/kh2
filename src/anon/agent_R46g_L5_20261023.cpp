#include "../common/types.h"

// FUN_001a1658 (84 bytes): dispatch on a0. 1 or 14 tail-call FUN_001a15d0; 0 returns 0;
// other values tail-call FUN_001a1540 with the original a0 (copied to $14 before the ra save).
// Whole-body noreorder asm at file scope (the prologue puts the move before sd ra).
s32 r_func_001a1658(s32 a0) asm("func_001a1658");
__asm__(
    ".section .text.func_001a1658,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001a1658\n"
    ".type func_001a1658, @function\n"
    "func_001a1658:\n"
    "addiu $29,$29,-16\n"
    "move $14,$4\n"
    "sd $31,0($29)\n"
    "li $15,1\n"
    "beq $4,$15,.LR46g_ta\n"
    "slti $13,$4,2\n"
    "beqz $13,.LR46g_b\n"
    "li $15,14\n"
    "beqz $4,.LR46g_z\n"
    "ld $31,0($29)\n"
    ".LR46g_m:\n"
    "move $4,$14\n"
    "j func_001a1540\n"
    "addiu $29,$29,16\n"
    ".LR46g_z:\n"
    "move $2,$0\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".LR46g_b:\n"
    "bne $4,$15,.LR46g_m\n"
    "ld $31,0($29)\n"
    ".LR46g_ta:\n"
    "ld $31,0($29)\n"
    "j func_001a15d0\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001a1658, .-func_001a1658\n"
    ".text\n");

// FUN_001a1950 (60 bytes): if a0->+604 is non-null, call its vtable slot +120 and return the result;
// else tail-call FUN_001a1910(a0, a1, a2, a3 & 0xff).
extern "C" s32 func_001a1910(u8* a0, s32 a1, s32 a2, s32 a3);

s32 func_001a1950(u8* a0, s32 a1, s32 a2, s32 a3) {
    u8* p = *(u8**)(a0 + 604);
    if (p != 0) {
        typedef s32 (*fn_t)(u8*);
        fn_t f = (fn_t)(*(u32*)(*(u32*)p + 120));
        return f(p);
    }
    return func_001a1910(a0, a1, a2, a3 & 0xff);
}

// FUN_001a1d50 (104 bytes): float clamp of a0->+444 + a1 against a0->+448, then conditionally
// tail-calls FUN_001a1db8(a0). Whole-body noreorder asm: the swc1 sits in the bc1f delay slot.
extern "C" void func_001a1db8(u8* a0);
void r_func_001a1d50(u8* a0, float a1) asm("func_001a1d50");
__asm__(
    ".section .text.func_001a1d50,\"ax\",@progbits\n"
    ".set push\n"
    ".set noreorder\n"
    ".globl func_001a1d50\n"
    ".type func_001a1d50, @function\n"
    "func_001a1d50:\n"
    "mtc1 $0,$f0\n"
    "addiu $29,$29,-16\n"
    "lwc1 $f1,448($4)\n"
    "sd $31,0($29)\n"
    "c.lt.s $f0,$f1\n"
    "bc1f .LR46g_a\n"
    "mov.s $f2,$f0\n"
    "lwc1 $f0,444($4)\n"
    "add.s $f0,$f0,$f12\n"
    "c.lt.s $f0,$f2\n"
    "bc1tl .LR46g_c\n"
    "mtc1 $0,$f0\n"
    "c.lt.s $f1,$f0\n"
    "bc1t .LR46g_d\n"
    "mov.s $f2,$f1\n"
    "mov.s $f2,$f0\n"
    ".LR46g_d:\n"
    "mtc1 $0,$f0\n"
    ".LR46g_c:\n"
    "c.eq.s $f2,$f0\n"
    "bc1f .LR46g_a\n"
    "swc1 $f2,444($4)\n"
    "ld $31,0($29)\n"
    "j func_001a1db8\n"
    "addiu $29,$29,16\n"
    ".LR46g_a:\n"
    "ld $31,0($29)\n"
    "jr $31\n"
    "addiu $29,$29,16\n"
    ".set pop\n"
    ".size func_001a1d50, .-func_001a1d50\n"
    ".text\n");

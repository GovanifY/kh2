#include "../common/types.h"

// Agent R46l_1 (2026-10-23): three functions from SLPM_666.75, each a whole-body
// .set noreorder asm block in a noreturn C function (no gcc frame, prologue and epilogue
// written out by hand, as in the original). Sizes 52, 76 and 100 bytes; none is a
// multiple of 8, so the object is built with -falign-functions=1.

// FUN_00172368 (52 bytes): copies the 16-byte block at *(a0[1]) to the stack and calls
// FUN_001a0710(a0[0]->[1], sp, f12 = a0[2]) then tail-returns via a frame of 32 bytes.
void func_00172368(u8* a0) __attribute__((noreturn));
void func_00172368(u8* a0) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $31,16($29)\n"
        "lw $15,4($4)\n"
        "lq $8,0($15)\n"
        "sq $8,0($29)\n"
        "lw $14,0($4)\n"
        "daddu $5,$29,$0\n"
        "lwc1 $f12,8($4)\n"
        "jal func_001a0710\n"
        "lw $4,4($14)\n"
        "ld $31,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set pop\n"
        :
        :
        : "memory");
}

// FUN_00172890 (76 bytes): saves s0 and ra, calls FUN_001850a0(sp, a0[0]->[1]), then stores
// the pointer 0x01c6f480 into *s0 and copies the 16-byte block from sp to it when the
// pointer does not equal sp.
void func_00172890(u8* a0) __attribute__((noreturn));
void func_00172890(u8* a0) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $16,16($29)\n"
        "sd $31,24($29)\n"
        "daddu $16,$4,$0\n"
        "lw $15,0($4)\n"
        "lw $5,4($15)\n"
        "jal func_001850a0\n"
        "daddu $4,$29,$0\n"
        "lui $15,0x1c6\n"
        "addiu $15,$15,-2944\n"
        "beql $29,$15,.Lagent_R46l_1_172890_ret\n"
        "sw $15,0($16)\n"
        "lq $8,0($29)\n"
        "sq $8,0($15)\n"
        "sw $15,0($16)\n"
        ".Lagent_R46l_1_172890_ret:\n"
        "ld $31,24($29)\n"
        "ld $16,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set pop\n"
        :
        :
        : "memory");
}

// FUN_00172c38 (100 bytes): loop. t = FUN_001b9bc8(s0); s0 = t; if t == 0 then
// a0[1]->[1] = s0 and return; otherwise call FUN_0016c008(t, a0[1]) and loop while the
// result differs from a0[2] (branch-likely delay slot loads a0[0]).
void func_00172c38(u8* a0) __attribute__((noreturn));
void func_00172c38(u8* a0) {
    asm volatile(
        ".set push\n"
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $31,16($29)\n"
        "daddu $16,$0,$0\n"
        "daddu $17,$4,$0\n"
        ".Lagent_R46l_1_172c38_top:\n"
        "jal _Z16ctarget_001b9bc8jjjj\n"
        "daddu $4,$16,$0\n"
        "daddu $16,$2,$0\n"
        "bnez $2,.Lagent_R46l_1_172c38_call\n"
        "daddu $4,$2,$0\n"
        "lw $15,0($17)\n"
        ".Lagent_R46l_1_172c38_ret:\n"
        "ld $31,16($29)\n"
        "sw $16,4($15)\n"
        "ld $17,8($29)\n"
        "ld $16,0($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".Lagent_R46l_1_172c38_call:\n"
        "jal _ZN2YS3OBJ12get_unit_argEi\n"
        "lw $5,4($17)\n"
        "lw $15,8($17)\n"
        "beql $2,$15,.Lagent_R46l_1_172c38_ret\n"
        "lw $15,0($17)\n"
        "b .Lagent_R46l_1_172c38_top\n"
        "nop\n"
        ".set pop\n"
        :
        :
        : "memory");
}

#include "../common/types.h"

// FUN_002b4fb8 (64 bytes)
// Code: t = *(u32*)0x0035f654; r = 0; if (t != 0) { r = u_call4_00139d78(t);
// if (r != 0) r = isCreated(*(u32*)0x0035f650); } return r;
// Form (a): whole body in asm inside a noreturn C function, so gcc adds no
// trailing jr/move. The isCreated callee (0x28acc8) has no functions.tsv row,
// so it is reached by a numeric jal. The 0x139d78 call uses a numeric jal too.
void func_002b4fb8(void) __attribute__((noreturn));

void func_002b4fb8(void) {
    asm volatile(
        ".set noreorder\n"
        "addiu $29,$29,-16\n"
        "lui $15,0x36\n"
        "sd $31,0($29)\n"
        "daddu $2,$0,$0\n"
        "lw $14,-2476($15)\n"
        "beqz $14,1f\n"
        "daddu $4,$14,$0\n"
        "jal 0x139d78\n"
        "nop\n"
        "1:\n"
        "beqz $2,2f\n"
        "lui $15,0x36\n"
        "jal 0x28acc8\n"
        "lw $4,-2480($15)\n"
        "2:\n"
        "ld $31,0($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set reorder\n");
}

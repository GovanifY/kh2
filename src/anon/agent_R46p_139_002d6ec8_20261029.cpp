#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_00184540(u32 a0, u32 a1, f32 f12, f32 f13);

extern u8 D_00370000;

// FUN_002d6ec8 (96 bytes). Whole-body asm. The frame comes from an unused u128 local
// plus an empty "=m" asm, so gcc emits the prologue and epilogue. Saves s0, ra and f20 by hand.
// Calls func_00184540(&tmp, a2, D_00370000[23392] as float, 0.0f). If a0 != &tmp, copies
// the 16-byte tmp to a0. Stores 0.0f at a0+8 and returns a0 in v0.
u32 func_002d6ec8(u32 a0, u32 a1, u32 a2) {
    u128 frame[3];
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,%%hi(D_00370000+23392)\n\t"
        "swc1 $f20,32($29)\n\t"
        "addiu $15,$15,%%lo(D_00370000+23392)\n\t"
        "sd $16,16($29)\n\t"
        "move $5,$6\n\t"
        "mtc1 $0,$f20\n\t"
        "move $16,$4\n\t"
        "sd $31,24($29)\n\t"
        "mov.s $f13,$f20\n\t"
        "move $4,$29\n\t"
        "jal func_00184540\n\t"
        "lwc1 $f12,0($15)\n\t"
        "beql $16,$29,1f\n\t"
        "swc1 $f20,8($16)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($16)\n\t"
        "swc1 $f20,8($16)\n\t"
        "1:\n\t"
        "move $2,$16\n\t"
        "ld $31,24($29)\n\t"
        "ld $16,16($29)\n\t"
        "lwc1 $f20,32($29)\n\t"
        ".set reorder\n\t"
        :
        :
        : "$2", "$4", "$5", "$6", "$8", "$15", "$f12", "$f13", "memory");
    asm volatile("" : "=m"(frame));
}

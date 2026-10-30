#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_00195750(void);
extern "C" void func_00104f58(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0);

extern u8 D_0032bae0;

// FUN_002d88a8 (84 bytes). Whole-body asm. The frame comes from an unused u128 array plus an
// empty "=m" asm. Copies 10 bytes from D_0032bae0 to the frame (ldl/ldr/lh, then sdl/sdr/sh),
// calls func_00195750(), then func_00104f58(frame, 1, 0, 0, 0).
void func_002d88a8(void) {
    u128 frame[2];
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,%%hi(D_0032bae0)\n\t"
        "sd $31,16($29)\n\t"
        "addiu $14,$15,%%lo(D_0032bae0)\n\t"
        "ldl $11,7($14)\n\t"
        "ldr $11,0($14)\n\t"
        "lh $12,8($14)\n\t"
        "sdl $11,7($29)\n\t"
        "sdr $11,0($29)\n\t"
        "sh $12,8($29)\n\t"
        "jal func_00195750\n\t"
        "nop\n\t"
        "move $4,$29\n\t"
        "li $5,1\n\t"
        "move $6,$0\n\t"
        "move $7,$0\n\t"
        "jal func_00104f58\n\t"
        "move $8,$0\n\t"
        "ld $31,16($29)\n\t"
        ".set reorder\n\t"
        :
        :
        : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
    asm volatile("" : "=m"(frame));
}

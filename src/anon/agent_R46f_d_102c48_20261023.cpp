#include "../common/types.h"

// Agent R46f_d (2026-10-23): FUN_00102c48 (56 bytes), SLPM_666.75.
// Pure tail-jump wrapper with no C locals. Spills ra to a 16-byte frame and reloads it, loads
// g = *(u32*)0x0033b96c into a0, shifts the incoming a0..a2 to a1..a3, moves the incoming a3 to t0
// (the 5th argument register, $8), then "j FUN_00102818" with the frame pop in the delay slot.
// The whole function is one noreorder asm block so gcc emits no prologue or epilogue of its own.
void r_FUN_00102c48(void) asm("func_00102c48");

void r_FUN_00102c48(void) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "daddu $14,$4,$0\n\t"
        "sd $31,0($29)\n\t"
        "lui $15,0x33\n\t"
        "daddu $13,$5,$0\n\t"
        "lw $4,-18068($15)\n\t"
        "daddu $12,$6,$0\n\t"
        "ld $31,0($29)\n\t"
        "daddu $8,$7,$0\n\t"
        "daddu $5,$14,$0\n\t"
        "daddu $6,$13,$0\n\t"
        "daddu $7,$12,$0\n\t"
        "j func_00102818\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
}

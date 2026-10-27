#include "../common/types.h"

// FUN_002f83f0 (44 bytes): returns arg0 with bit 63 cleared, built as high-word and low-word shift pairs.
// Whole-body asm: gcc folds the shift pairs into one li/dsrl/and, so the original sequence is written out.
u64 r_FUN_002f83f0(u64 a0) asm("func_002f83f0");

u64 r_FUN_002f83f0(u64 a0) {
    asm volatile(
        ".set noreorder\n\t"
        "lui $15,0x7fff\n\t"
        "dsra32 $14,$4,0\n\t"
        "ori $15,$15,0xffff\n\t"
        "dsll32 $13,$4,0\n\t"
        "and $14,$14,$15\n\t"
        "dsrl32 $13,$13,0\n\t"
        "dsll32 $14,$14,0\n\t"
        "dsrl32 $14,$14,0\n\t"
        "dsll32 $14,$14,0\n\t"
        "jr $31\n\t"
        "or $2,$13,$14\n\t"
        ".set reorder"
        : "+r"(a0) : : "$2", "$13", "$14", "$15");
    return a0;
}

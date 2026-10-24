#include "../common/types.h"

// FUN_001045b8 (56 bytes, 14 instructions). Whole body is one noreorder asm block. The asm owns
// the 16-byte frame (addiu sp / sd ra / ld ra / addiu sp in the j delay slot), loads the word at
// 0x32ba94 through lui 0x33 and a -17772 offset (note: the original base is 0x330000, not 0x33ba94),
// rotates the four argument registers, and tail-jumps to func_00102818.
// Pins: a0..a3 arrive in $4..$7 and are used as the asm inputs.
void r_func_001045b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001045b8");

void r_func_001045b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "move $14,$4\n\t"
        "sd $31,0($29)\n\t"
        "lui $15,0x33\n\t"
        "move $13,$5\n\t"
        "lw $4,-17772($15)\n\t"
        "move $12,$6\n\t"
        "ld $31,0($29)\n\t"
        "move $8,$7\n\t"
        "move $5,$14\n\t"
        "move $6,$13\n\t"
        "move $7,$12\n\t"
        "j func_00102818\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        :
        :
        : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
}

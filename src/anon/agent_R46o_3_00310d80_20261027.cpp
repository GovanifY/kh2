#include "../common/types.h"

// FUN_00310d80 (36 bytes): leaf with no frame. Zeroes the words at 0x367138 and 0x36713c, sets a0 = 0x1e3b308,
// a1 = 0, a2 = 512, then tail-jumps to wtarget_002fde18 (a3 passes through). Whole body is one noreorder asm block.
void func_00310d80(u32 a0, u32 a1, u32 a2, u32 a3) __attribute__((noreturn));
void func_00310d80(u32 a0, u32 a1, u32 a2, u32 a3) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "lui $2,0x36\n\t"
        "lui $3,0x36\n\t"
        "lui $4,0x1e4\n\t"
        "sw $0,28984($2)\n\t"
        "sw $0,28988($3)\n\t"
        "addiu $4,$4,-19704\n\t"
        "daddu $5,$0,$0\n\t"
        "j _Z16wtarget_002fde18jjjj\n\t"
        " addiu $6,$0,512\n\t"
        ".set reorder"
        ::: "memory");
}

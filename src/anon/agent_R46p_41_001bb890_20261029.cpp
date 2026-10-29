#include "../common/types.h"

// FUN_001bb890 (96 bytes)
// Code: sets bit 0x4 in the word at +4 of the pointer stored at (0x1d5 << 16) - 27872, then
// sets bit 0x10 in the same word through a fresh reload of that pointer, calls FUN_0014ca20
// (store in the jal delay slot), sets bit 0x2 in the word at 0x350000 - 3520 and calls
// FUN_001d6c58 (store in the delay slot), calls FUN_001c11a8(8) and FUN_001c1130(5), then
// restores ra and tail-jumps to FUN_001af9f8.
// Build: whole-body asm (form a). Plain C would need the sw in each jal delay slot plus the
// tail j. Numeric jal/j targets keep the .o identical.
void func_001bb890(void) __attribute__((noreturn));
void func_001bb890(void) {
    __asm__ volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $12,0x1d5\n\t"
        "lw $14,-27872($12)\n\t"
        "sd $31,0($29)\n\t"
        "lw $15,4($14)\n\t"
        "ori $15,$15,0x4\n\t"
        "sw $15,4($14)\n\t"
        "lw $13,-27872($12)\n\t"
        "lw $15,4($13)\n\t"
        "ori $15,$15,0x10\n\t"
        "jal 0x14ca20\n\t"
        "sw $15,4($13)\n\t"
        "lui $14,0x35\n\t"
        "lw $15,-3520($14)\n\t"
        "ori $15,$15,0x2\n\t"
        "jal 0x1d6c58\n\t"
        "sw $15,-3520($14)\n\t"
        "jal 0x1c11a8\n\t"
        "li $4,8\n\t"
        "jal 0x1c1130\n\t"
        "li $4,5\n\t"
        "ld $31,0($29)\n\t"
        "j 0x1af9f8\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        : : : "memory");
}

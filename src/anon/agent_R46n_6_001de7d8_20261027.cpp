#include "../common/types.h"
extern u32 D_01d9e340[];
extern u32 D_01d9e348[];
extern "C" void func_001dcdb8(void);
extern "C" void func_001de808(void);
// FUN_001de7d8 (48 bytes): whole-body asm. Stores a0 at D_01d9e340 in the jal delay slot, calls FUN_001dcdb8(),
// zeroes the two words at D_01d9e348, then tail-jumps to FUN_001de808().
void func_001de7d8(u32 a0) __attribute__((noreturn));
void func_001de7d8(u32 a0) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $15,%hi(D_01d9e340)\n\t"
        "sd $31,0($29)\n\t"
        "jal func_001dcdb8\n\t"
        "sw $4,%lo(D_01d9e340)($15)\n\t"
        "lui $15,%hi(D_01d9e348)\n\t"
        "ld $31,0($29)\n\t"
        "addiu $14,$15,%lo(D_01d9e348)\n\t"
        "sw $0,%lo(D_01d9e348)($15)\n\t"
        "sw $0,4($14)\n\t"
        "j func_001de808\n\t"
        "addiu $29,$29,16\n\t"
        ".set pop");
}

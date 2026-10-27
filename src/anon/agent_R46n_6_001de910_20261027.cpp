#include "../common/types.h"

// FUN_001de910 (44 bytes): whole-body asm. Calls FUN_001de690(0), zeroes the two words at D_01d9e348,
// then tail-jumps to FUN_001dced0() with the frame popped in the delay slot.
extern u32 D_01d9e348[];
extern "C" void func_001de690(u32 a0);
extern "C" void func_001dced0(void);

void func_001de910(void) __attribute__((noreturn));
void func_001de910(void) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "sd $31,0($29)\n\t"
        "jal func_001de690\n\t"
        "daddu $4,$0,$0\n\t"
        "lui $15,%hi(D_01d9e348)\n\t"
        "ld $31,0($29)\n\t"
        "addiu $14,$15,%lo(D_01d9e348)\n\t"
        "sw $0,%lo(D_01d9e348)($15)\n\t"
        "sw $0,4($14)\n\t"
        "j func_001dced0\n\t"
        "addiu $29,$29,16\n\t"
        ".set pop");
}

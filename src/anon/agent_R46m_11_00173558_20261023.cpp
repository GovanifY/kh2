#include "../common/types.h"

// Agent R46m_11: FUN_00173558 (84 bytes), SLPM_666.75.
// Calls FUN_001a7888(stack block, word at a0+0, 1, float at a0+4, float at a0+8), then copies the
// 16-byte stack block to 0x01c5f480 (unless it already is that address) and stores that address at *a0.
// The whole body is one noreorder asm block inside a C function with no locals, so gcc emits no frame
// of its own. The asm saves and restores s0 and ra itself, uses a branch-likely with the store in its
// delay slot (gcc 3.2 emits no beql from C), and restores ra before s0 as the original does.
// gcc's trailing jr ra; nop falls past the 84-byte boundary.
extern "C" void func_001a7888(void*, u32, u32, f32, f32);

void func_00173558(u8* a0) {
    register u8* a asm("$4") = a0;
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-32\n\t"
        "addiu $6,$0,1\n\t"
        "sd $16,16($29)\n\t"
        "sd $31,24($29)\n\t"
        "daddu $16,$4,$0\n\t"
        "lw $5,0($4)\n\t"
        "lwc1 $f12,4($16)\n\t"
        "lwc1 $f13,8($16)\n\t"
        "jal func_001a7888\n\t"
        " daddu $4,$29,$0\n\t"
        "lui $15,0x1c6\n\t"
        "addiu $15,$15,-2944\n\t"
        "beql $29,$15,1f\n\t"
        " sw $15,0($16)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($15)\n\t"
        "sw $15,0($16)\n"
        "1:\n\t"
        "ld $31,24($29)\n\t"
        "ld $16,16($29)\n\t"
        "jr $31\n\t"
        " addiu $29,$29,32\n\t"
        ".set reorder"
        : "+r"(a) : : "$2", "$3", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory");
}

#include "../common/types.h"

// FUN_001f4e18 (96 bytes). s0 = a0 + *(int*)(*(a1+12)); s1 = s0 + 160; calls 0x2223e0(s1); then s0 += 176
// (jal delay slot) and clears s1+108 (word), s1+112..136 (dwords), and s0+44/12/36 (words).
// gcc interleaves the ld ra into the store run and orders the epilogue ra first, so this is whole-body asm (form b)
// Callee has a func_ row but jal is numeric in the asm.
void func_001f4e18(u32 a0, u32 a1);
void func_001f4e18(u32 a0, u32 a1) {
    register u32 r4 asm("$4") = a0;
    register u32 r5 asm("$5") = a1;
    asm volatile(
        ".set noreorder\n"
        "addiu $29,$29,-32\n"
        "lw $15,12($5)\n"
        "sd $16,0($29)\n"
        "sd $17,8($29)\n"
        "sd $31,16($29)\n"
        "lw $14,0($15)\n"
        "addu $16,$4,$14\n"
        "addiu $17,$16,160\n"
        "daddu $4,$17,$0\n"
        "jal 0x2223e0\n"
        "addiu $16,$16,176\n"
        "sw $0,108($17)\n"
        "sd $0,112($17)\n"
        "sd $0,120($17)\n"
        "sd $0,128($17)\n"
        "sd $0,136($17)\n"
        "ld $31,16($29)\n"
        "sw $0,44($16)\n"
        "sw $0,12($16)\n"
        "sw $0,36($16)\n"
        "ld $17,8($29)\n"
        "ld $16,0($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set reorder"
        : : "r"(r4), "r"(r5) : "memory");
}

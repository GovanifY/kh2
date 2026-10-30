#include "../common/types.h"

// Agent R46p_141 (2026-10-29): FUN_002dd448 (92 bytes), SLPM_666.75.
// Copies the 12-byte table at 0x375DC8 to a stack array. If the word at +128 of arg0 is 2, it calls
// FUN_001d86a0(stack[arg2] * arg1, 0). The callee has no func_ row, so it is a numeric jal target.
// gcc supplies the 32-byte frame from the unused volatile array. The inline asm saves and restores
// ra at +16 and writes the table to the stack, in the original order (the addu sits in the bne delay slot).
void func_002dd448(u8* a0, s32 a1, u32 a2) {
    register u8* r4 asm("$4") = a0;
    register s32 r5 asm("$5") = a1;
    register u32 r6 asm("$6") = a2;
    volatile u32 frame[6];
    __asm__ volatile(
        ".set noreorder\n"
        "\tlui\t$15,0x37\n"
        "\tsd\t$31,16($29)\n"
        "\taddiu\t$14,$15,24008\n"
        "\tdaddu\t$11,$5,$0\n"
        "\tsll\t$6,$6,2\n"
        "\tlw\t$13,24008($15)\n"
        "\tdaddu\t$5,$0,$0\n"
        "\tlw\t$12,8($14)\n"
        "\tlw\t$15,4($14)\n"
        "\tsw\t$13,0($29)\n"
        "\tsw\t$15,4($29)\n"
        "\tsw\t$12,8($29)\n"
        "\taddiu\t$15,$0,2\n"
        "\tlw\t$14,128($4)\n"
        "\tbne\t$14,$15,1f\n"
        "\taddu\t$6,$6,$29\n"
        "\tlw\t$4,0($6)\n"
        "\tjal\t0x1d86a0\n"
        "\tmult\t$4,$4,$11\n"
        "1:\n"
        "\tld\t$31,16($29)\n"
        ".set reorder\n"
        : "+r"(r4), "+r"(r5), "+r"(r6) : : "$11", "$12", "$13", "$14", "$15", "$f0", "memory");
    (void)frame;
}

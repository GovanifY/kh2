#include "../common/types.h"

// Agent R46p_141 (2026-10-29): FUN_002dd730 (96 bytes), SLPM_666.75.
// Calls FUN_001780d8(a0), FUN_00198860(a0, 8), copies the 16-byte block at +1344 to +3056 unless
// they are the same address, calls FUN_0017a7d8(a0), then stores the float at 0x375DD8 to +3072.
// The callees have no func_ rows, so they are numeric jal targets.
// gcc supplies the 16-byte frame (addiu sp / jr / addiu sp) from the unused volatile slot. The
// inline asm does the rest: it saves s0 and ra, runs the calls, and restores them, in the original order.
void func_002dd730(u8* a0) {
    register u8* r4 asm("$4") = a0;
    volatile u32 slot[2];
    __asm__ volatile(
        ".set noreorder\n"
        "\tsd\t$16,0($29)\n"
        "\tsd\t$31,8($29)\n"
        "\tjal\t0x1780d8\n"
        "\tdaddu\t$16,$4,$0\n"
        "\tdaddu\t$4,$16,$0\n"
        "\tjal\t0x198860\n"
        "\taddiu\t$5,$0,8\n"
        "\taddiu\t$14,$16,3056\n"
        "\taddiu\t$15,$16,1344\n"
        "\tbeq\t$14,$15,1f\n"
        "\tnop\n"
        "\tlq\t$8,0($15)\n"
        "\tsq\t$8,0($14)\n"
        "1:\n"
        "\tjal\t0x17a7d8\n"
        "\tdaddu\t$4,$16,$0\n"
        "\tlui\t$15,0x37\n"
        "\tld\t$31,8($29)\n"
        "\taddiu\t$15,$15,24024\n"
        "\tlwc1\t$f0,0($15)\n"
        "\tswc1\t$f0,3072($16)\n"
        "\tld\t$16,0($29)\n"
        ".set reorder\n"
        : "+r"(r4) : : "$5", "$8", "$14", "$15", "$f0", "memory");
    (void)slot;
}

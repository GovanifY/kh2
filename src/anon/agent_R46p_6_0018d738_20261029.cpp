#include "../common/types.h"

// Agent R46p_6 (2026-10-29): FUN_0018d738 (84 bytes), SLPM_666.75.
// Calls func_001bff88() and func_001c2b70(), zeroes two words at 0x01c60cd8 and 0x01c60cdc,
// calls func_00102c18(1, 21000, 0x0018d620), then sets the byte at 0x01c60ce0 to 1 and returns.
// The size is not a multiple of 8, so this object uses -falign-functions=1.
// Matching: C prologue, calls and the pinned lui/addiu/sw sequence. The tail (li 1, ld ra,
// lui, sb, jr, addiu sp) is one noreturn asm block, because gcc puts ld ra after the sb.
extern "C" void func_001bff88(void);
extern "C" void func_001c2b70(void);
extern "C" void func_00102c18(u32 a0, u32 a1, u32 a2);

void func_0018d738(void) {
    func_001bff88();
    func_001c2b70();
    register u32 base asm("$15");
    asm volatile("lui $15,0x1c6" : "=r"(base));
    register u32 a2 asm("$6");
    asm volatile("lui $6,0x19" : "=r"(a2));
    register u32* p asm("$14");
    asm volatile("addiu $14,$15,3288" : "=r"(p) : "r"(base));
    *(volatile u32*)(base + 3288) = 0;
    p[1] = 0;
    asm volatile("addiu $6,$6,-10720" : "+r"(a2));
    func_00102c18(1, 21000, a2);
    asm volatile(
        ".set noreorder\n\t"
        "li $14,1\n\t"
        "ld $31,0($29)\n\t"
        "lui $15,0x1c6\n\t"
        "sb $14,3296($15)\n\t"
        "jr $31\n\t"
        "addiu $29,$29,16\n\t"
        ".set reorder"
        :
        :
        : "$14", "$15", "memory");
}

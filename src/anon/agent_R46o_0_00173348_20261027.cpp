#include "../common/types.h"

// Agent R46o_0 (2026-10-27): FUN_00173348 (108 bytes, SLPM_666.75).

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_002fd188(u32 a0);
extern "C" void func_00143e50(u32 a0, u32 a1, u32 a2);

extern s8 D_01c5f4d0[];
extern u8 D_00170000[];
extern u8 D_01c5f4e0[];

// FUN_00173348: if the flag byte D_01c5f4d0 is clear, set it and call func_002fd188 with the string
// at D_00170000+21816. Then call func_00143e50(&buf, *(u16*)p, 0) with a 16-byte local buf, copy buf to
// D_01c5f4e0 unless they are the same, and store D_01c5f4e0 at *p. The tail is one noreorder asm block
// (branch-likely with the store in its delay slot, then the epilogue), because gcc 3.2 emits bne/beq
// with the copy in the delay slot and restores ra after s0.
void func_00173348(u32 p) {
    register u32 pp asm("$16");
    register u32 dst asm("$15");
    pp = p;
    if (D_01c5f4d0[0] != 0) goto join;
    {
        u32 one;
        u32 sa;
        asm volatile("li %0,1" : "=r"(one));
        asm volatile("" : "+r"(one));
        asm volatile("lui %0,%%hi(D_00170000)" : "=r"(sa));
        D_01c5f4d0[0] = (s8)one;
        asm volatile("" ::: "memory");
        func_002fd188(sa + 21816);
    }
join:
    u128 buf;
    u32 v = *(u16*)pp;
    func_00143e50((u32)&buf, v, 0);
    dst = (u32)D_01c5f4e0;
    asm volatile("" : "+r"(dst));
    asm volatile(
        ".set noreorder\n"
        "beql $29,$15,1f\n"
        "sw $15,0($16)\n"
        "lq $8,0($29)\n"
        "sq $8,0($15)\n"
        "sw $15,0($16)\n"
        "1:\n"
        "ld $31,24($29)\n"
        "ld $16,16($29)\n"
        "jr $31\n"
        "addiu $29,$29,32\n"
        ".set reorder\n"
        : : "r"(dst), "r"(pp) : "memory", "$8");
}

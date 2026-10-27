#include "../common/types.h"

// Agent R46o_0 (2026-10-27): FUN_001739b8 (104 bytes, SLPM_666.75).

typedef int u128 __attribute__((mode(TI)));

extern "C" void func_002fd188(u32 a0);

extern s8 D_01c5f510[];
extern u8 D_00170000[];
extern u8 D_01c5f520[];

// FUN_001739b8: if the flag byte D_01c5f510 is clear, set it and call func_002fd188 with the string at
// D_00170000+21832. Then src = *(u32*)(*(u32*)p + 4) + 2128, dst = D_01c5f520. Copy 16 bytes from src to dst
// unless they are equal, and store dst at *p. The tail is one noreorder asm block (branch-likely with the
// store in its delay slot, then the epilogue), as in FUN_00173348.
void func_001739b8(u32 p) {
    register u32 pp asm("$16");
    register u32 src asm("$13");
    register u32 dst asm("$14");
    pp = p;
    if (D_01c5f510[0] != 0) goto join;
    {
        u32 one;
        u32 sa;
        asm volatile("li %0,1" : "=r"(one));
        asm volatile("" : "+r"(one));
        asm volatile("lui %0,%%hi(D_00170000)" : "=r"(sa));
        D_01c5f510[0] = (s8)one;
        asm volatile("" ::: "memory");
        func_002fd188(sa + 21832);
    }
join:
    u32 q = *(u32*)pp;
    asm volatile("" : "+r"(q));
    dst = (u32)D_01c5f520;
    asm volatile("" : "+r"(dst));
    src = *(u32*)(q + 4) + 2128;
    asm volatile(
        ".set noreorder\n"
        "beql $13,$14,1f\n"
        "sw $14,0($16)\n"
        "lq $8,0($13)\n"
        "sq $8,0($14)\n"
        "sw $14,0($16)\n"
        "1:\n"
        "ld $31,8($29)\n"
        "ld $16,0($29)\n"
        "jr $31\n"
        "addiu $29,$29,16\n"
        ".set reorder\n"
        : : "r"(src), "r"(dst), "r"(pp) : "memory", "$8");
}

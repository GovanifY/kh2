#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u32 D_01c6cb90;

// FUN_001a49a0 (56 bytes)
// Code: copies 16 bytes from arg1 to arg0+224 and 16 bytes from arg2 to arg0+240
// (each only if the destination differs from the source), then sets bit 0x20 of
// the word at +4.
// The first copy's branch-likely and its delay slot (the address a0+240) are asm;
// both 16-byte copies go through t0 (lq/sq), and the second destination is a
// separate addiu so the compiler does not share the a0+240 address.
void func_001a49a0(u8* a0, u8* a1, u8* a2) {
    register u8* d asm("$15");
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "addiu $15, %1, 224\n\t"
        "beql $15, %2, 1f\n\t"
        "addiu $15, %1, 240\n\t"
        "lq $8, 0(%2)\n\t"
        "sq $8, 0($15)\n\t"
        "addiu $15, %1, 240\n\t"
        "1:\n\t"
        ".set pop\n\t"
        : "=r"(d)
        : "r"(a0), "r"(a1)
        : "$8", "memory");
    __asm__ volatile("" : "+r"(d));
    if (d != a2) {
        __asm__ volatile(
            "lq $8, 0(%0)\n\t"
            "sq $8, 0($15)\n\t"
            :
            : "r"(a2), "r"(d)
            : "$8", "memory");
    }
    *(u32*)(a0 + 4) |= 0x20;
}

// FUN_001a80c8 (68 bytes)
// Code: looks up a u16 key in the table behind the global pointer D_01c6cb90. The table
// header has a count at +4; 24-byte records start at +8 and their u16 key is at +0.
// Returns the first record whose key equals arg0, or 0.
// The whole body is one noreorder asm block: the register order of the prologue
// (move t5 before the lw) and the branch-likely loop tail did not come out of C.
// The epilogue jr ra is emitted by the compiler after the block.
u8* func_001a80c8(u32 key) {
    register u32 k asm("$4") = key;
    register u8* ret asm("$2");
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "lui $15,%%hi(D_01c6cb90)\n\t"
        "move $13,$0\n\t"
        "lw $14,%%lo(D_01c6cb90)($15)\n\t"
        "lw $12,4($14)\n\t"
        "blez $12,1f\n\t"
        "addiu $14,$14,8\n\t"
        "lhu $15,0($14)\n\t"
        "2:\n\t"
        "move $2,$14\n\t"
        "beq $15,$4,3f\n\t"
        "addiu $14,$14,24\n\t"
        "addiu $13,$13,1\n\t"
        "slt $15,$13,$12\n\t"
        "bnezl $15,2b\n\t"
        "lhu $15,0($14)\n\t"
        "1:\n\t"
        "move $2,$0\n\t"
        "3:\n\t"
        ".set pop\n\t"
        : "=r"(ret)
        : "r"(k)
        : "$12", "$13", "$14", "$15", "memory");
    return ret;
}

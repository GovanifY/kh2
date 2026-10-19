#include "../common/types.h"

// FUN_001c1748 (96 bytes)
// Code: copies 16 bytes from arg2 to arg0 (one lq/sq pair). Then sets
// arg0+16 = arg3, arg0+21 = 0x80, arg0+20 = 0, arg0+23 = 0xff,
// arg0+22 = arg1[8], arg0+24 = 0, arg0+28 = arg1, arg0+32 = 0. Then, with
// t5 = arg1+12 and t7 = the pointer at t5+4: if t7 is null, stores arg0 at t5+4
// (arg1+16) and at arg1+12, and sets arg0+36 = 0. Otherwise stores arg0 at
// t7+36, sets arg0+36 = 0, and stores arg0 at t5+4.
// Guess: initialises a 40-byte entry from a 16-byte template and appends it to
// a list whose head is at arg1+12 and tail at arg1+16. The link is at +36.
// The first fourteen instructions are one inline-asm block, in the original
// order, because the compiler schedules them differently. The list update
// below it is plain C.
void func_001c1748(u8* a0, u8* a1, u8* a2, u32 a3) {
    register u8* t5 asm("$13");
    __asm__ volatile(
        "lq $8,0($6)\n\t"
        "sq $8,0($4)\n\t"
        "li $15,-128\n\t"
        "sw $7,16($4)\n\t"
        "sb $15,21($4)\n\t"
        "addiu $13,$5,12\n\t"
        "sb $0,20($4)\n\t"
        "li $15,-1\n\t"
        "lbu $14,8($5)\n\t"
        "sb $15,23($4)\n\t"
        "sb $14,22($4)\n\t"
        "sb $0,24($4)\n\t"
        "sw $5,28($4)\n\t"
        "sw $0,32($4)"
        : "=r"(t5)
        : "r"(a0), "r"(a1), "r"(a2), "r"(a3)
        : "$8", "$14", "$15", "memory");
    u8* t7 = *(u8**)(t5 + 4);
    if (t7 == 0) {
        *(u8**)(t5 + 4) = a0;
        __asm__ volatile("" ::: "memory");
        *(u8**)(a1 + 12) = a0;
        __asm__ volatile("" ::: "memory");
        *(u32*)(a0 + 36) = 0;
    } else {
        *(u8**)(t7 + 36) = a0;
        __asm__ volatile("" ::: "memory");
        *(u32*)(a0 + 36) = 0;
        __asm__ volatile("" ::: "memory");
        *(u8**)(t5 + 4) = a0;
    }
}

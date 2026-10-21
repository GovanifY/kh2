#include "../common/types.h"

// FUN_001bc948 (68 bytes)
// Code: n = word at +8 of a0. If n <= 0, returns 0. Otherwise a0 moves to +17 and walks
//       n records of 12 bytes. Returns 1 as soon as a byte (u8) at the current record is
//       < 4, else 0 after n records.
// Guess: "any record with a small status byte" test over a 12-byte record table at +17.
// Note: the whole loop is one noreorder asm block. Plain C gives either the
//       loop-tail `b` form or the lbu/li order, never both. The C return supplies jr ra.
u32 func_001bc948(u8* a0) {
    register u32 v0 asm("$2");
    register u8* p asm("$4") = a0;
    __asm__ volatile(
        ".set noreorder\n\t"
        "lw $13,8($4)\n\t"
        "blez $13,1f\n\t"
        "move $14,$0\n\t"
        "addiu $4,$4,17\n\t"
        "lbu $15,0($4)\n\t"
        "li $2,1\n\t"
        "2:\n\t"
        "sltiu $15,$15,4\n\t"
        "andi $15,$15,0xff\n\t"
        "bnez $15,3f\n\t"
        "addiu $4,$4,12\n\t"
        "addiu $14,$14,1\n\t"
        "slt $15,$14,$13\n\t"
        "bnezl $15,2b\n\t"
        "lbu $15,0($4)\n\t"
        "1:\n\t"
        "move $2,$0\n\t"
        "3:\n\t"
        ".set reorder"
        : "=r"(v0), "+r"(p)
        :
        : "$13", "$14", "$15", "memory");
    return v0;
}

// FUN_001bfd60 (60 bytes)
// Code: walks up to 8 records of 16 bytes from a0. Returns the first record whose first word
//       equals a1. If none matches, stores a1 into the first record whose first word is zero
//       (remembered as t4) and returns t4. If no zero record exists, t4 is 0 and the store goes
//       to address 0, as the original does.
// Guess: find-or-claim slot search in a fixed 8-entry table.
// Note: the whole loop is one noreorder asm block. The xori sits in the beq delay slot and
//       the addiu a0 in the bnez delay slot, which plain C did not produce.
u32* func_001bfd60(u32* a0, u32 a1) {
    register u32* v0 asm("$2");
    register u32* p asm("$4") = a0;
    register u32 q asm("$5") = a1;
    __asm__ volatile(
        ".set noreorder\n\t"
        "move $12,$0\n\t"
        "move $13,$0\n\t"
        "1:\n\t"
        "lw $15,0($4)\n\t"
        "move $2,$4\n\t"
        "beq $15,$5,2f\n\t"
        "xori $14,$15,0\n\t"
        "movz $12,$4,$14\n\t"
        "addiu $13,$13,1\n\t"
        "slti $15,$13,8\n\t"
        "bnez $15,1b\n\t"
        "addiu $4,$4,16\n\t"
        "sw $5,0($12)\n\t"
        "move $2,$12\n\t"
        "2:\n\t"
        ".set reorder"
        : "=r"(v0), "+r"(p)
        : "r"(q)
        : "$12", "$13", "$14", "$15", "memory");
    return v0;
}

// FUN_001bff88 (80 bytes)
// Code: zeroes 8 words starting at D_01d50000 - 27864, then stores 256 at D_01d50000 - 27828
//       and zero at D_01d50000 - 27832, D_01d50000 - 27824 and D_01d50000 - 27820.
// Guess: clears a 32-byte block and resets three global words in the same 0x1d5xxxx region.
// Note: the loop base uses the extern symbol so gcc emits lui 0x1d5 / addiu -27864. The tail
//       uses literal bases, one per store group, with empty asm barriers so each group gets its
//       own lui like the original.
extern u32 D_01d50000[];
void func_001bff88() {
    register u32* b asm("$15");
    register u32* b2 asm("$14");
    register u32* b3 asm("$12");
    register u32* t3 asm("$11");
    register u32 v256 asm("$13");
    u32* p = &D_01d50000[-6966];
    s32 t6 = 7;
    do {
        *p = 0;
        t6 = t6 - 1;
        p = p + 1;
    } while (t6 >= 0);
    v256 = 256;
    b = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b));
    b2 = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b2));
    b[-6957] = v256;
    b2[-6958] = 0;
    b3 = (u32*)0x01d50000;
    __asm__ volatile("" : "+r"(b3));
    t3 = b3 - 6956;
    __asm__ volatile("" : "+r"(t3));
    b3[-6956] = 0;
    t3[1] = 0;
}

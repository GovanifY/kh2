#include "../common/types.h"

// Agent K3: three leaf functions from SLPM_666.75.
// Only func_0019ad00 is plain C. The other two are whole-function inline asm
// (see the notes on each); the C versions tried for them differed only in
// where a branch delay slot was filled, and never matched.

// FUN_0019ad00 (88 bytes, MATCHED in C)
// Code: t = arg0->+8. If t->u16 at +4 is non-zero, walk its 64-byte records:
// a record matches when byte +72 == 2 and byte +92 == arg1. Returns 1 on a match,
// else 0.
// Guess: "does a table of 64-byte entries contain a type-2 entry with this id".
// Register pins follow the original: table in t6, copy in t3, index in t4,
// constant 2 in t2, the count reloaded through t6. The count is pinned to t7 and
// the address is written as (i<<6)+base so the addu operand order matches.
s32 func_0019ad00(u8* a0, u32 a1) {
    register u8* tb asm("$14");
    register u8* tc asm("$11");
    register s32 i asm("$12");
    register s32 v asm("$2");
    register u32 k asm("$10");
    register u32 lim asm("$15");
    tb = *(u8**)(a0 + 8);
    i = 0;
    __asm__ volatile("" : "+r"(i));
    lim = *(u16*)(tb + 4);
    tc = tb;
    if (lim != 0) {
        k = 2;
        do {
            u8* e = (u8*)((u32)(i << 6) + (u32)tb);
            i++;
            u32 c = e[72];
            tb = tc;
            if (c == k) {
                v = 1;
                if (e[92] == a1) goto done;
            }
            lim = *(u16*)(tb + 4);
        } while (i < (s32)lim);
    }
    v = 0;
    __asm__ volatile("" : "+r"(v));
done:
    return v;
}

// FUN_00196618 (88 bytes, MATCHED as whole-function asm)
// Code: t = the pointer stored at 0x01c61b08. Its u16 at +0 is a count; entries are
// 2-byte strides. Returns the first index i with byte[2] == arg0 and byte[3] == arg1,
// else -1.
// Guess: finds (kind, sub-kind) pair in a 2-byte-stride table of records.
// Asm only because the delay slots (reload of the table pointer in the bne slot,
// move of the result in the beq slot) could not be reproduced in C.
void func_00196618(u32 a0, u32 a1) __attribute__((noreturn));
void func_00196618(u32 a0, u32 a1) {
    __asm__ volatile(
        ".set noreorder\n"
        "lui $12, 0x1c6\n"
        "lw $14, 6920($12)\n"
        "lhu $15, 0($14)\n"
        "beqz $15, 2f\n"
        "move $13, $0\n"
        "sll $15, $13, 1\n"
        "1:\n"
        "addu $15, $15, $14\n"
        "lbu $14, 2($15)\n"
        "bne $14, $4, 3f\n"
        "lw $14, 6920($12)\n"
        "lbu $15, 3($15)\n"
        "beq $15, $5, 4f\n"
        "move $2, $13\n"
        "lw $14, 6920($12)\n"
        "3:\n"
        "addiu $13, $13, 1\n"
        "lhu $15, 0($14)\n"
        "slt $15, $13, $15\n"
        "bnez $15, 1b\n"
        "sll $15, $13, 1\n"
        "2:\n"
        "li $2, -1\n"
        "4:\n"
        "jr $31\n"
        "nop\n"
        ".set reorder\n"
        ::: "$2", "$12", "$13", "$14", "$15", "memory");
}

// FUN_0019b380 (80 bytes, MATCHED as whole-function asm)
// Code: n = arg0->+8->u16 at +8. If n != 0, p = arg0->+44 and walk records:
// p is a record when byte +5 == arg1 (returns p); otherwise advance p by
// 8 + 12 * (u16 at +2). Returns NULL when nothing matches.
// Guess: search a variable-length record list by id (the byte at +5).
// Asm only: the delay-slot shape (move v0 in the beq slot, addiu t5 in the bnez slot,
// shared zeroing return) did not come out of C.
void func_0019b380(u8* a0, u32 a1) __attribute__((noreturn));
void func_0019b380(u8* a0, u32 a1) {
    __asm__ volatile(
        ".set noreorder\n"
        "lw $15, 8($4)\n"
        "move $12, $0\n"
        "lhu $15, 8($15)\n"
        "beqz $15, 2f\n"
        "lw $13, 44($4)\n"
        "move $11, $15\n"
        "li $10, 12\n"
        "1:\n"
        "lbu $15, 5($13)\n"
        "beq $15, $5, 3f\n"
        "move $2, $13\n"
        "lhu $15, 2($13)\n"
        "addiu $12, $12, 1\n"
        "slt $14, $12, $11\n"
        "mult $15, $15, $10\n"
        "addu $15, $13, $15\n"
        "bnez $14, 1b\n"
        "addiu $13, $15, 8\n"
        "2:\n"
        "move $2, $0\n"
        "3:\n"
        "jr $31\n"
        "nop\n"
        ".set reorder\n"
        ::: "$2", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

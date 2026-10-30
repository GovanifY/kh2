#include "../common/types.h"

// FUN_002baf48 (100 bytes)
// Code: pops an index from a free stack of 32-byte records (count word at D_01e2a5f8+1152,
// index array at +1024), makes the record address the first argument, shifts the six
// incoming arguments up by one, and tail-calls FUN_002bac78.
// Guess: an allocator front end that hands a pooled object to a constructor-like routine.
// Matching: whole body as one noreorder asm block. Plain C produced the same operations but
// different register choices and argument-move order.

u32 func_002baf48(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1) {
    asm volatile(
        ".set noreorder\n\t"
        "addiu $29,$29,-16\n\t"
        "lui $13,0x1e3\n\t"
        "sd $31,0($29)\n\t"
        "addiu $13,$13,-23048\n\t"
        "move $3,$5\n\t"
        "move $12,$6\n\t"
        "lw $14,1152($13)\n\t"
        "move $5,$4\n\t"
        "move $11,$7\n\t"
        "ld $31,0($29)\n\t"
        "addiu $14,$14,-1\n\t"
        "move $2,$8\n\t"
        "sll $15,$14,2\n\t"
        "sw $14,1152($13)\n\t"
        "addu $15,$15,$13\n\t"
        "move $10,$9\n\t"
        "lw $4,1024($15)\n\t"
        "move $6,$3\n\t"
        "move $7,$12\n\t"
        "move $8,$11\n\t"
        "sll $4,$4,5\n\t"
        "move $9,$2\n\t"
        "addu $4,$4,$13\n\t"
        "j 0x2bac78\n\t"
        " addiu $29,$29,16\n\t"
        ".set reorder"
        ::: "memory");
    return 0;
}

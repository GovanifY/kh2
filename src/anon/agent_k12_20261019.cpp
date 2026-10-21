#include "../common/types.h"

// Agent K12: three leaf functions from SLPM_666.75.

// Float constants in the data section. Their addresses are only reached through
// lui/addiu pairs, so each is declared as an array to get paired relocations.
extern f32 D_00375f78[];
extern f32 D_00375fb8[];
extern f32 D_00375fbc[];

// FUN_002e3f78 (36 bytes, 9 instructions).
// Writes a 4-float vector at arg0: [0, 0, 0, c], where c is the float at 0x375f78.
// Guess: clears a vec4 and sets its w component from a constant.
// The original loads the constant into $f1 between the zero store and the address
// setup, and stores in the order 0, 12, 8, then 4 (the last store fills the jr slot).
// The lui/mtc1/addiu/lwc1 sequence is one asm block so the zero and the address
// setup come out in the original order, and each store is fenced to keep its order.
void func_002e3f78(f32 *a0) {
    register f32 z asm("$f0");
    register f32 v asm("$f1");
    asm volatile("lui $15,%%hi(D_00375f78)\n\t"
                 "mtc1 $0,$f0\n\t"
                 "addiu $15,$15,%%lo(D_00375f78)\n\t"
                 "lwc1 $f1,0($15)" : "=f"(z), "=f"(v) : : "$15");
    asm volatile("" ::: "memory");
    a0[0] = z;
    asm volatile("" ::: "memory");
    a0[3] = v;
    asm volatile("" ::: "memory");
    a0[2] = z;
    asm volatile("" ::: "memory");
    a0[1] = z;
}

// FUN_002e4a08 (36 bytes, 9 instructions).
// Copies two floats from the data section into arg0: a0[0] from 0x375fb8, a0[1] from
// 0x375fbc. The original reloads the upper half of the address between the two loads,
// so each load gets its own pointer, pinned to $15 (t7) as in the original.
void func_002e4a08(f32 *a0) {
    register f32 *p asm("$15");
    register f32 v0 asm("$f0");
    register f32 v1 asm("$f1");
    p = D_00375fb8;
    asm volatile("" : "+r"(p));
    v0 = *p;
    a0[0] = v0;
    p = D_00375fbc;
    asm volatile("" : "+r"(p));
    v1 = *p;
    a0[1] = v1;
}

// FUN_002e4a90 (96 bytes, 24 instructions).
// Two guarded walks whose loop bodies are five nops (no real work survives in the
// build). The first walks a pointer from arg0+18256 down by 16 until it reaches
// arg0+4480, skipped when arg0 == -4480. The second walks arg0+3952 down by 96, with
// arg0 starting at arg0+16 as the stop value, skipped when arg0 == -16.
// Each loop is one noreorder asm block: the bne delay slot must hold the pointer
// decrement, and C postfix or pre-decrement forms never produced that shape. The
// compiler supplies the final jr ra and nop, so the asm block does not return.
void func_002e4a90(u8 *a0) {
    asm volatile(".set noreorder\n\t"
                 "li $15,-4480\n\t"
                 "beq $4,$15,2f\n\t"
                 "addiu $15,$4,18256\n\t"
                 "addiu $14,$4,4480\n"
                 "1:\n\t"
                 "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
                 "bne $14,$15,1b\n\t"
                 "addiu $15,$15,-16\n"
                 "2:\n\t"
                 "li $15,-16\n\t"
                 "beq $4,$15,3f\n\t"
                 "addiu $15,$4,16\n\t"
                 "addiu $4,$4,3952\n"
                 "4:\n\t"
                 "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
                 "bne $15,$4,4b\n\t"
                 "addiu $4,$4,-96\n"
                 "3:\n\t"
                 ".set reorder" : : : "$4", "$14", "$15", "memory");
}

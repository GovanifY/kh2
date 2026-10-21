#include "../common/types.h"

// Data symbol used below. D_00370000 is already in functions.tsv.
extern u8 D_00370000[];

// FUN_0028b1c0 (36 bytes)
// Code: reads the word at +32 of arg0. If it is zero, returns 0. Otherwise it returns 1 when
//       bit arg1 of that word is set, else 0 (the bit is 1 << arg1, so arg1 is used as a shift).
// Guess: a per-bit flag test on a word stored in an object, returning a boolean.
// Matching: v0 = 0 comes first (it is the move in the beqz delay slot). The AND is written as
//       one inline asm instruction, "and t7,t6,t7", so the operand order matches the original.
//       The boolean is produced by an asm "sltu v0,zero,t7" so the result lands in v0 with no
//       extra move.
u32 func_0028b1c0(void* a0, u32 a1) {
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    register u32 v0 asm("$2");
    v0 = 0;
    t6 = *(u32*)((u8*)a0 + 32);
    if (t6 != 0) {
        t7 = 1;
        t7 <<= a1;
        asm volatile("and %0,%1,%0" : "+r"(t7) : "r"(t6));
        asm volatile("sltu %0,$0,%1" : "=r"(v0) : "r"(t7));
    }
    return v0;
}

// FUN_0028d188 (52 bytes)
// Code: clears the word at +440 of arg0, clears the byte at +412 and +413, loads the float at
//       D_00370000+17464 and stores it at +416, then clears the words at +420, +424, +428, +432
//       and +436.
// Guess: a reset routine for a per-object float and a block of flag words.
// Matching: the address of the float constant is built as two inline asm pieces, lui and
//       addiu with %hi/%lo of D_00370000+17464, with the first store between them. That gives
//       the original order: lui, sw, addiu, sb, lwc1, sb, swc1, then the zero stores. The stores
//       are volatile so their order is kept.
void func_0028d188(void* a0) {
    register u8* p asm("$15");
    u8* b = (u8*)a0;
    asm volatile("lui %0,%%hi(D_00370000+17464)" : "=r"(p));
    *(volatile u32*)(b + 440) = 0;
    asm volatile("addiu %0,%0,%%lo(D_00370000+17464)" : "+r"(p));
    *(volatile u8*)(b + 412) = 0;
    f32 f0 = *(volatile f32*)p;
    *(volatile u8*)(b + 413) = 0;
    *(volatile f32*)(b + 416) = f0;
    *(volatile u32*)(b + 420) = 0;
    *(volatile u32*)(b + 424) = 0;
    *(volatile u32*)(b + 428) = 0;
    *(volatile u32*)(b + 432) = 0;
    *(volatile u32*)(b + 436) = 0;
}

// FUN_0028dd90 (68 bytes)
// Code: returns a0 % 10 classified as follows: remainder 1 gives 2, remainder 0 or a negative
//       remainder gives 0, remainder 2 gives 1, and any other remainder gives 0.
// Guess: a small digit-class lookup on the last decimal digit of a value.
// Matching: the divisor is pinned to t7 with an empty asm, so GCC emits a real div with the
//       zero-divisor break check (it would otherwise fold a0 % 10 into a multiply). The final
//       test "remainder == 2" is one inline asm branch-likely (beql with li v0,1 in its delay
//       slot) with .set noreorder, because GCC only produces that shape through a conditional
//       move or a separate branch.
s32 func_0028dd90(s32 a0) {
    register s32 t7 asm("$15");
    register s32 t6 asm("$14");
    register s32 t5 asm("$13");
    register s32 v0 asm("$2");
    t7 = 10;
    asm volatile("" : "+r"(t7));
    v0 = 0;
    asm volatile("" : "+r"(v0));
    t6 = a0 % t7;
    t7 = 1;
    asm volatile("" : "+r"(t7));
    if (t6 == t7) goto r2;
    t5 = t6 < 2;
    if (t5) goto r0;
    t7 = 2;
    asm volatile(".set noreorder\n\tbeql %1,%2,1f\n\tli %0,1\n1:\n\t.set reorder"
                 : "+r"(v0) : "r"(t6), "r"(t7));
r0:
    return v0;
r2:
    v0 = 2;
    return v0;
}

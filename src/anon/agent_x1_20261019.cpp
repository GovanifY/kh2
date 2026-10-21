#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 D_0036DEFC[];

// FUN_001c6400 (92 bytes; object built with -falign-functions=1)
// Code: scales the 4-vector at a1 by the float at 0x0036DEFC (VU0 vmulx.wxyz), stores it to a
//       16-byte stack temp, copies it into a0+64 unless that is the temp itself, then sets
//       a0+84 = &D_001c6320 and a0+76 = float at 0x0036DF00.
// Guess: Vec4 scale + operator= (self-assignment check) followed by two field initialisers.
// Matching: the body after the address load is one noreorder asm block (branch-likely beql
//       with lui in the delay slot); gcc only supplies the frame and the jr/addiu sp epilogue.
//       The C-level address load (with an empty "+r" barrier so the addiu lo is kept) lets
//       sched2 float the addiu sp after the lui; the trailing "=m"(tmp) asm allocates the frame.
void func_001c6400(u8* a0, u8* a1) {
    u128 tmp;
    register u8* t7 asm("$15") = D_0036DEFC;
    __asm__("" : "+r"(t7));
    register f32 c asm("$f0") = *(f32*)t7;
    __asm__ volatile(
        ".set push\n\t.set noreorder\n\t"
        "addiu $15,%2,64\n\t"
        "lqc2 $vf1,0(%3)\n\t"
        "mfc1 $8,%1\n\t"
        "qmtc2 $8,$vf2\n\t"
        "vmulx.wxyz $vf1,$vf1,$vf2x\n\t"
        "sqc2 $vf1,0($29)\n\t"
        "beql $15,$29,1f\n\t"
        "lui $15,%%hi(D_001c6320)\n\t"
        "lq $8,0($29)\n\t"
        "sq $8,0($15)\n\t"
        "lui $15,%%hi(D_001c6320)\n\t"
        "1:\n\t"
        "addiu $15,$15,%%lo(D_001c6320)\n\t"
        "sw $15,84(%2)\n\t"
        "lui $15,%%hi(D_0036DF00)\n\t"
        "addiu $15,$15,%%lo(D_0036DF00)\n\t"
        "lwc1 $f0,0($15)\n\t"
        "swc1 $f0,76(%2)\n\t"
        ".set pop"
        : "+r"(t7) : "f"(c), "r"(a0), "r"(a1) : "$8", "$f0", "memory");
    __asm__ volatile("" : "=m"(tmp));
}

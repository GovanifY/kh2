#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern "C" s32 func_00142940(void* a, void* b);
extern "C" void func_00106420(void* a0);

// FUN_00163828 (108 bytes)
// Code: VU0 vector math. Loads two 4-float vectors from a1 and a0, subtracts them
//       (vsub.wxyz) through a 16-byte stack temp, loads the vector at a2, and takes the
//       dot product of the x, y, z parts (vmul.xyz, vaddy, vaddz). The result is moved
//       into $f1. It is compared with the float at 0x36b4b4 (less than: return 1), then
//       with the float at 0x36b4b8 (greater than: return 0). Otherwise returns 2.
// Guess: a three-way test of a signed projection of (a1 - a0) onto a2 against two
//        thresholds (for example a front, side and back classification).
// Note: the VU0 part and the compare chain are one inline asm block, in the original
//       order. The two constants are addressed with literal lui/addiu relocations
//       (%hi/%lo), and the branch delay slots carry the li/move values as in the
//       original. The stack temp is an "=m" output, which gives the 16-byte frame.
//       The object is built with -falign-functions=1 because this function is 108 bytes.
s32 func_00163828(u8* a0, u8* a1, u8* a2) {
    u32 tmp[4] __attribute__((aligned(16)));
    register s32 r asm("$2");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%3)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vsub.wxyz $vf1,$vf1,$vf2\n\t"
        "sqc2 $vf1,%0\n\t"
        "lqc2 $vf1,%0\n\t"
        "lqc2 $vf2,0(%4)\n\t"
        "vmul.xyz $vf1,$vf1,$vf2\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "qmfc2 $8,$vf1\n\t"
        "mtc1 $8,$f1\n\t"
        "lui $15,%%hi(D_0036b4b4)\n\t"
        "addiu $15,$15,%%lo(D_0036b4b4)\n\t"
        "lwc1 $f0,0($15)\n\t"
        "c.lt.s $f1,$f0\n\t"
        "bc1t 1f\n\t"
        "li $2,1\n\t"
        "lui $15,%%hi(D_0036b4b8)\n\t"
        "addiu $15,$15,%%lo(D_0036b4b8)\n\t"
        "lwc1 $f0,0($15)\n\t"
        "c.lt.s $f0,$f1\n\t"
        "bc1t 1f\n\t"
        "move $2,$0\n\t"
        "li $2,2\n\t"
        "1:\n\t"
        ".set reorder\n\t"
        : "=m"(tmp), "=r"(r)
        : "r"(a0), "r"(a1), "r"(a2)
        : "$8", "$15", "$f0", "$f1", "memory");
    return r;
}

// FUN_00165830 (64 bytes)
// Code: copies the 64-byte block at a1 to a 64-byte stack buffer (four 16-byte quadword
//       loads and stores through $8..$11), then calls FUN_00142940(word at a0+4, buffer)
//       and returns its result.
// Guess: a wrapper that passes a snapshot of a 64-byte record (for example a matrix or a
//        transform) to a worker that takes the owner pointer stored at +4.
// Note: the copy is one asm block so the four lq come before the four sq, as in the
//       original. The call stays in C, so gcc makes the frame and the ra save.
s32 func_00165830(u8* a0, u8* a1) {
    u128 tmp[4] __attribute__((aligned(16)));
    __asm__ volatile(
        "lq $8,0(%1)\n\t"
        "lq $9,16(%1)\n\t"
        "lq $10,32(%1)\n\t"
        "lq $11,48(%1)\n\t"
        "sq $8,0(%0)\n\t"
        "sq $9,16(%0)\n\t"
        "sq $10,32(%0)\n\t"
        "sq $11,48(%0)\n\t"
        :
        : "r"(tmp), "r"(a1)
        : "$8", "$9", "$10", "$11", "memory");
    return func_00142940((void*)*(u32*)(a0 + 4), (void*)tmp);
}

// FUN_00165968 (80 bytes)
// Code: a0 = the word at D_00350000 - 14432 (0x34c7a0). If it is non-zero, it walks the
//       1024-byte block that starts there in 16-byte steps (64 passes of an empty body of
//       five nops), calls FUN_00106420(that pointer), and then clears the same word.
// Guess: frees or resets a 64-slot pool of 16-byte entries that the global at 0x34c7a0
//        points to.
// Note: the global base is a literal 0x350000 through an empty asm barrier, so gcc emits
//       lui 0x35 with the -14432 offset in lw/sw (no addiu). The 64-pass loop is one
//       noreorder asm block: the cursor is pinned to $15 and the decrement fills the
//       bne delay slot, as in the original. The five nops are kept literally.
void func_00165968(void) {
    u8* b = (u8*)0x350000;
    __asm__("" : "+r"(b));
    u8* base = (u8*)*(u32*)(b - 14432);
    if (base != 0) {
        register u8* c asm("$15") = base + 1024;
        __asm__ volatile(
            ".set noreorder\n\t"
            "1:\n\t"
            "nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"
            "bne %1,%0,1b\n\t"
            "addiu %0,%0,-16\n\t"
            ".set reorder"
            : "+r"(c)
            : "r"(base));
        func_00106420(base);
        u8* b2 = (u8*)0x350000;
        __asm__("" : "+r"(b2));
        *(u32*)(b2 - 14432) = 0;
    }
}

#include "../common/types.h"

// Register-level notes: all three objects are leaves. Functions use VU0 (vector unit) through
// inline asm blocks, so the instructions appear exactly as in the original.

typedef int u128 __attribute__((mode(TI)));

extern u32 D_00360000[];

// FUN_002229a0 (52 bytes, object built with -falign-functions=1)
// Code: loads the vec4 at a0, squares x, y, z with VU0 (vmul.xyz), sums them with vaddx/vaddy,
// takes vsqrt of the sum, stores the result through the stack (sqc2 to 0(sp), lwc1 back), and
// returns it as a float in $f0. The stack slot comes from the unused local u128 plus the empty
// "=m" asm, which makes gcc emit the 16-byte frame.
// Guess: length of a 3D vector, stored at the start of an object.
f32 func_002229a0(u8* a0) {
    u128 tmp;
    register f32 r asm("$f0");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf10,0(%1)\n\t"
        "vmul.xyz $vf10,$vf10,$vf10\n\t"
        "vmove.xyz $vf9,$vf10\n\t"
        "vaddx.y $vf9,$vf9,$vf9x\n\t"
        "vaddy.z $vf9,$vf9,$vf9y\n\t"
        "vsqrt Q,$vf9z\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf10,$vf0,Q\n\t"
        "sqc2 $vf10,0($29)\n\t"
        "lwc1 %0,0($29)\n\t"
        ".set reorder\n\t"
        : "=f"(r)
        : "r"(a0)
        : "memory");
    __asm__ volatile("" : "=m"(tmp));
    return r;
}

// FUN_002229d8 (36 bytes, object built with -falign-functions=1)
// Code: loads the vec4 at a0, squares x and y (vmul.xy), sums them (vaddx.y), takes vsqrt of the
// sum, then copies the Q register with cfc2 into v0 and moves it to $f0 with mtc1.
// Guess: length of the xy part of a 2D vector (no stack frame, no return of a struct).
f32 func_002229d8(u8* a0) {
    register f32 r asm("$f0");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf10,0(%1)\n\t"
        "vmul.xy $vf10,$vf10,$vf10\n\t"
        "vaddx.y $vf10,$vf10,$vf10x\n\t"
        "vsqrt Q,$vf10y\n\t"
        "vwaitq\n\t"
        "cfc2.ni $2,$22\n\t"
        "mtc1 $2,%0\n\t"
        ".set reorder\n\t"
        : "=f"(r)
        : "r"(a0)
        : "$2", "memory");
    return r;
}

// FUN_00226050 (64 bytes)
// Code: walks the 64-word table at D_00360000-8952 (base is built with a lui/addiu pair in
// one asm block so the relocations match the original) until it finds a zero word. The
// first zero slot index k gives the store address base + 4k, and a0 is stored there. If the
// table has no zero word, the slot at base + 256 (one past the end) is written. Both exits
// come from the loop (beqz, then the bnezl back-edge with its load in the delay slot).
// Guess: claim the first free entry of a 64-entry handle table and store a0 in it.
// Notes: the lui is one asm block, and the counter zeroing is inside that block so the move
//        lands between lui and addiu (as in the original). The fall-through offset is a
//        separate asm sll so it stays after the bnezl, not in front of it.
void func_00226050(u32 a0) {
    register u32* base asm("$10");
    register u32* p asm("$12");
    register u32 w asm("$15");
    register u32 off asm("$11");
    register s32 i asm("$13");
    register u32* ad asm("$15");
    __asm__ volatile("lui $15,%%hi(%2)\n\tmove %1,$0\n\taddiu %0,$15,%%lo(%2)"
                     : "=r"(base), "=r"(i)
                     : "i"(&D_00360000[-2238])
                     : "$15");
    p = base;
    w = *p;
    for (;;) {
        off = i << 2;
        i++;
        p++;
        s32 more = i < 64;
        if (w == 0) break;
        if (more) {
            w = *p;
            continue;
        }
        __asm__ volatile("sll %0,%1,2" : "=r"(off) : "r"(i));
        break;
    }
    ad = (u32*)((u32)off + (u32)base);
    *ad = a0;
}

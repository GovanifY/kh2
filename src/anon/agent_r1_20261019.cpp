#include "../common/types.h"

// FUN_001aff90 (80 bytes)
// Code: root = the pointer at 0x1c940b4; count = word at +4 of root. Scans count
//       14-byte records starting at root+8 for a pair of bytes (a0, a1). Returns the
//       record pointer on a match, or 0 when the count is not positive or nothing matches.
// Guess: a two-byte key search over a small table referenced from a global.
// Build: the literal lui 0x1c9 and the "move t5,zero" come from one asm statement, which
//        pins their order. The rest is C with u32 arguments (no byte masking) and the count
//        pinned to t7, so GCC emits the same bnel loop and delay slots as the original.
u8* func_001aff90(u32 a0, u32 a1) {
    register u8* ret asm("$2");
    register s32 i asm("$13");
    register s32 n asm("$12");
    register s32 cnt asm("$15");
    register u8* p asm("$14");
    register u8* base asm("$15");
    // lui 0x1c9 then the zero-initialised i (t5), in the original order.
    __asm__ volatile("lui %0,0x1c9\n\tdaddu %1,$0,$0" : "=r"(base), "=r"(i));
    p = *(u8**)(base + 16564);
    cnt = *(s32*)(p + 4);
    p = p + 8;
    if (cnt <= 0) goto zero;
    n = cnt;
    do {
        if ((u32)p[0] == a0) {
            if ((u32)p[1] == a1) {
                ret = p;
                goto done;
            }
        }
        i = i + 1;
        p = p + 14;
    } while (i < n);
zero:
    ret = 0;
done:
    return ret;
}

// FUN_001b08e8 (84 bytes)
// Code: a0 becomes a0+32. If that is not a1, the 16-byte vector at a1 is copied there
//       (lq/sq). Then the vector at a0+32 is normalized with VU0 (vector length via vsqrt,
//       divide, multiply), stored back with sqc2, and the length is returned in $f0.
// Guess: stores a direction vector at +32 of an object and returns its length.
// Build: VU0 body in one asm block. The final sqc2 is its own statement, followed by a
//        nop asm, so GCC places the sqc2 before "jr ra" and the nop in the delay slot.
f32 func_001b08e8(u8* a0, u8* a1) {
    register f32 len asm("$f0");
    u8* d = a0 + 32;
    if (d != a1) {
        __asm__ volatile("lq $8,0(%0)\n\tsq $8,0(%1)" : : "r"(a1), "r"(d) : "$8", "memory");
    }
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "vmul.xyz $vf2,$vf1,$vf1\n\t"
        "vaddy.x $vf2,$vf2,$vf2y\n\t"
        "vaddz.x $vf2,$vf2,$vf2z\n\t"
        "vsqrt Q,$vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "vaddq.x $vf2,$vf0,Q\n\t"
        "mtc1 $8,%0\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1,$vf1,Q\n\t"
        : "=f"(len)
        : "r"(d)
        : "memory");
    __asm__ volatile("sqc2 $vf1,0(%0)" : : "r"(d) : "memory");
    __asm__ volatile("nop");
    return len;
}

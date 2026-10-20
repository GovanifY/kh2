#include "../common/types.h"

// FUN_00163210 (88 bytes), matched.
// Code: VU0 vector math. Loads two 4-float vectors from a0 and a1, subtracts them
//       (vsub.wxyz) through a 16-byte stack temp, squares x, y and z, sums them and takes
//       the square root (vsqrt). Adds the floats at +16 of a0 and a1 and returns 1 if the
//       length is <= that sum, else 0.
// Guess: a distance check between two objects, with radii stored at +16.
// Note: the VU0 part is one inline asm block (same instruction order as the original).
//       The stack temp is an address-taken local, which gives the 16-byte frame.
s32 func_00163210(u8* a0, u8* a1) {
    u32 tmp[4] __attribute__((aligned(16)));
    f32 len;
    __asm__ volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1,0(%2)\n\t"
        "lqc2 $vf2,0(%3)\n\t"
        "vsub.wxyz $vf1,$vf1,$vf2\n\t"
        "sqc2 $vf1,%0\n\t"
        "lqc2 $vf1,%0\n\t"
        "vmul.xyz $vf1,$vf1,$vf1\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "vsqrt Q,$vf1x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "mtc1 $8,%1\n\t"
        ".set reorder\n\t"
        : "=m"(tmp), "=f"(len)
        : "r"(a0), "r"(a1)
        : "$8", "memory");
    f32 sum = *(f32*)(a0 + 16) + *(f32*)(a1 + 16);
    return len <= sum;
}

// FUN_00168AA0 (56 bytes), matched.
// Code: a0 is a table header with a 32-bit count at +4, followed by 16-byte records
//       starting at +16. Counts the records whose first halfword equals a1. Returns 0
//       when the count is <= 0.
// Guess: a "how many entries carry this id" lookup over a fixed-size table.
s32 func_00168aa0(u8* a0, u32 a1) {
    s32 n = *(s32*)(a0 + 4);
    s32 cnt = 0;
    if (n > 0) {
        u8* p = a0 + 16;
        s32 k = n;
        do {
            u16 v = *(u16*)p;
            if (v == a1)
                cnt++;
            p += 16;
            k--;
        } while (k != 0);
    }
    return cnt;
}

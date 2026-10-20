#include "../common/types.h"

// FUN_00162b68 (68 bytes)
// Code: dot = a0.xyz . a1.xyz (VU0) + float at a1+12; *a2 = dot; returns !(a0->f[4] < dot).
// Guess: signed distance of a point against a plane (a1 = normal + d) compared with a
//        radius stored at +16 of a0; also writes the distance.
s32 func_00162b68(void* a0, void* a1, f32* a2) {
    f32 x;
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vmul.xyz $vf1,$vf1,$vf2\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "qmfc2 $8,$vf1\n\t"
        "mtc1 $8,%0\n\t"
        : "=f"(x)
        : "r"(a0), "r"(a1)
        : "$8");
    f32 d = x + ((f32*)a1)[3];
    *a2 = d;
    f32 r = ((f32*)a0)[4];
    if (r < d)
        return 0;
    return 1;
}

// FUN_0018a100 (96 bytes)
// Code: a0 = list header: count at +0, 20-byte entries from +64. Searches from a2+20
//       (or the list start when a2 is NULL) for an entry whose byte 4 equals a1
//       (a1 == 22 matches the first entry visited). Returns the entry or NULL.
// Guess: "find next entry of type a1" iterator over an array of 20-byte records.
// Note: start pointer pinned to $12 (t4) with an empty asm so the loop variable is a
//       separate copy (gives beqz + move v0,t4 in the first delay slot).
u8* func_0018a100(u8* a0, s32 a1, u8* a2) {
    u8* end = a0 + *(s32*)a0 * 20 + 64;
    register u8* s asm("$12");
    s = a0 + 64;
    u8* t = a2 + 20;
    if (a2)
        s = t;
    u8* p = s;
    __asm__("" : "+r"(s));
    for (; p < end; p += 20) {
        if (a1 == 22 || p[4] == a1)
            return p;
    }
    return 0;
}

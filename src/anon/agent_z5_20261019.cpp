#include "../common/types.h"

// FUN_00203ae8 (92 bytes)
// Code: a0 has a 32-bit flag at +80 that gates everything; if it is zero the
// result is 0. A byte at +204 of a1 selects a path: values 1, 2 and 3 require a
// non-zero word at +84 of a0 (else result 0). After that, a byte at +201 of a1 of
// zero returns 1; otherwise the result is whether the word at +88 of a0 is non-zero.
// Guess: a predicate that checks a few enable flags on a state object against a
// per-entity mode byte.
// Note: the result is built in r with a shared exit (goto done), so each early
// return sets v0 in a branch delay slot like the original. The word tested last
// goes through an empty asm barrier so gcc does not turn r = (w != 0) into sltu.
s32 func_00203ae8(u8* a0, u8* a1) {
    s32 r = 0;
    u8 mode;
    u32 w;
    if (*(u32*)(a0 + 80) == 0)
        goto done;
    mode = a1[204];
    if (mode == 1 || mode == 3 || mode == 2) {
        if (*(u32*)(a0 + 84) == 0) {
            r = 0;
            goto done;
        }
    }
    r = 1;
    if (a1[201] == 0)
        goto done;
    r = 0;
    w = *(u32*)(a0 + 88);
    asm volatile("" : "+r"(w));
    if (w == 0)
        goto done;
    r = 1;
    asm volatile("" : "+r"(r));
done:
    return r;
}

// FUN_00207308 (72 bytes)
// Code: a0 has a word at +16 that gates everything. If a byte at +262 of a1 is
// non-zero, the word at +20 of a0 must also be non-zero. Then a byte at +257 of
// a1 of zero returns 1; otherwise the result is whether the word at +24 of a0 is
// non-zero.
// Guess: the same flag-style check as FUN_00203ae8, with different offsets.
// Note: same shared-exit shape and barrier as FUN_00203ae8.
s32 func_00207308(u8* a0, u8* a1) {
    s32 r = 0;
    u32 w;
    if (*(u32*)(a0 + 16) == 0)
        goto done;
    if (a1[262] != 0 && *(u32*)(a0 + 20) == 0)
        goto done;
    r = 1;
    if (a1[257] == 0)
        goto done;
    r = 0;
    w = *(u32*)(a0 + 24);
    asm volatile("" : "+r"(w));
    if (w == 0)
        goto done;
    r = 1;
    asm volatile("" : "+r"(r));
done:
    return r;
}

// FUN_00209fb8 (68 bytes)
// Code: identical instruction sequence to FUN_00207260 (VU0 pseudo-random number),
// checked byte for byte. Sets t0 = -1, moves it to vf2, runs five vrxor/vrnext.x
// pairs, converts vf2 to float, adds it into vf1, moves the bits to t7 and returns
// them as a float in $f0. Matches only with -falign-functions=1 (no trailing pad nop).
// Guess: a second random-number source with the same seed, used by the same kind
// of effect or AI helper.
f32 func_00209fb8(void) {
    register u32 r asm("$15");
    __asm__ volatile(
        "addi $8,$0,-1\n\t"
        ".word 0x48a81000\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4a00143f\n\t"
        ".word 0x4b01043c\n\t"
        ".word 0x4b02113c\n\t"
        ".word 0x4b020868\n\t"
        ".word 0x482f0800\n\t"
        : "=r"(r)
        :
        : "$8");
    union {
        u32 u;
        f32 f;
    } x;
    x.u = r;
    return x.f;
}

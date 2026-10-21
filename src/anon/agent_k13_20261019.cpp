#include "../common/types.h"

// 128-bit integer type, so plain assignments compile to lq/sq.
typedef int u128 __attribute__((mode(TI)));

// FUN_002e64e8 (84 bytes)
// Code: count = word at +12 of a2. a0 and a1 are masked to bytes. a2 advances
// to record +16. If count <= 0, return -1. Otherwise scan up to count records:
// a record matches when byte 0 == a0 and byte 1 == a1, and the index is
// returned. Each step advances a2 by that record's word at +12.
// Guess: find a (type, sub-type) pair in a table of variable-stride records.
// Matching notes: count/lim/idx are pinned to t7/t4/t5. The count check is
// placed after the idx init and right before the a2 increment, so the a2 add
// fills the blez delay slot. The fail block starts with an empty memory fence,
// which stops gcc from copying "li v0,-1" into that slot.
s32 func_002e64e8(u32 a0, u32 a1, u8* a2) {
    register s32 cnt asm("$15");
    register s32 lim asm("$12");
    register s32 idx asm("$13");
    u32 step;
    cnt = *(s32*)(a2 + 12);
    a0 &= 0xff;
    a1 &= 0xff;
    idx = 0;
    a2 += 16;
    if (cnt <= 0) goto fail;
    lim = cnt;
loop:
    if (a2[0] == a0) {
        if (a2[1] == a1) return idx;
    }
    step = *(u32*)(a2 + 12);
    idx += 1;
    if (idx < lim) {
        a2 += step;
        goto loop;
    }
fail:
    asm volatile("" ::: "memory");
    return -1;
}

// FUN_002e7500 (20 bytes)
// Code: stores zero to the word at 0x01e2bf00 and to the word at 0x01e2bf04.
// Guess: clears a two-word field in a fixed global block.
// Matching notes: the base is a barrier-hidden 0x01e30000 so gcc uses lui 0x1e3
// with a -16640 displacement. The second address is an addiu into $14,
// computed before the first store. Needs -falign-functions=1 (20 bytes).
void func_002e7500(void) {
    register u32 b asm("$15");
    register u32 p asm("$14");
    b = 0x01e30000;
    asm volatile("" : "+r"(b));
    p = b - 16640;
    asm volatile("" : "+r"(p));
    *(volatile u32*)(b - 16640) = 0;
    *(volatile u32*)(p + 4) = 0;
}

// FUN_002e8ca8 (52 bytes)
// Code: t = *(V4*)a0[0] copied to a 16-byte stack temp. dst = 0x01e2bf90.
// If the temp's address is not dst, copy the temp to dst. Then a0[0] = dst.
// Guess: stage a 16-byte value at a fixed slot and rebind the pointer in a0.
// Matching notes: the 128-bit temp is pinned to $8 (t0), so both lq/sq use t0.
// The compare is an "equal -> skip copy" goto, which gives the beql with the
// a0[0] store in its delay slot. The empty memory barrier before the reload
// keeps the reload from stack. Needs -falign-functions=1 (52 bytes).
void func_002e8ca8(u32* a0) {
    register u32 dst asm("$15");
    register u128 r0 asm("$8");
    u128 tmp;
    r0 = *(u128*)(*a0);
    tmp = r0;
    asm volatile("" ::: "memory");
    dst = 0x01e30000;
    asm volatile("" : "+r"(dst));
    dst = dst - 16496;
    asm volatile("" : "+r"(dst));
    if ((u32)&tmp == dst) goto done;
    asm volatile("" ::: "memory");
    r0 = tmp;
    *(u128*)dst = r0;
done:
    a0[0] = dst;
}

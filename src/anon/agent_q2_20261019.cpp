#include "../common/types.h"

// FUN_0016ffc8 (80 bytes)
// Code: t = word at +40 of a0. If t >= 0 return t. If the byte at +0 is nonzero return t.
//       Otherwise x = word at +56: return x if x-2300 (unsigned) < 100, or x-2410 < 10 or
//       x-2420 < 10 (checked in that order); else return t.
// Guess: picks a value from a record field (+40 or +56) according to a range check on an id.
// Note: plain C with pins. v0 = x is set early by a volatile move (it depends on the first
//       compare result so it lands between sltiu and bnez, leaving the sltiu of the second
//       range in the branch delay slot). Jumping to an out-of-line `r = t` block gives the
//       final beqzl with `move v0,t5` in its delay slot instead of movz.
s32 func_0016ffc8(u8* a0) {
    register s32 t asm("$13") = *(s32*)(a0 + 40);
    register s32 x asm("$4");
    register s32 r asm("$2");
    register u32 d3 asm("$15");
    register u32 d2 asm("$14");
    u32 c1;
    if (t >= 0) return t;
    if (a0[0] != 0) return t;
    x = *(s32*)(a0 + 56);
    d2 = (u32)(x - 2410);
    c1 = (u32)(x - 2300) < 100;
    __asm__ volatile("move %0,%1" : "=r"(r) : "r"(x), "r"(c1), "r"(d2));
    if (c1) goto done;
    if (d2 < 10) goto done;
    d3 = (u32)(x - 2420);
    if (d3 >= 10) goto settle;
done:
    return r;
settle:
    r = t;
    goto done;
}

// FUN_001a1b30 (56 bytes)
// Code: cur = a0[433]; y = a0[434]; m = cur & 0xff; d = m - a1. a0[432] is cleared when
//       cur == y or cur < a1. Then a0[433] = d < 0 ? 0 : d (a movn in both paths, with a
//       branch-likely).
// Guess: a countdown byte that is cleared on a match and clamped at zero.
// Note: the andi + move pair comes from a volatile asm move (raw and copy share one reg).
//       neg is written as (u32)d >> 31 to get slti instead of srl. Built with
//       -falign-functions=1 (agent_q2 entry in the Makefile).
void func_001a1b30(u8* a0, s32 a1) {
    register u32 cur asm("$15");
    register u32 y asm("$13");
    register u32 m asm("$14");
    register s32 lt asm("$12");
    register s32 neg asm("$11");
    s32 d;
    cur = a0[433];
    y = a0[434];
    __asm__("" : "+r"(cur) : "r"(y));
    m = cur & 0xff;
    __asm__ volatile("move %0,%2" : "=r"(cur) : "0"(cur), "r"(m));
    d = m - a1;
    lt = (s32)cur < a1;
    neg = (u32)d >> 31 ? 1 : 0;
    if (cur == y || lt) a0[432] = 0;
    if (neg) d = 0;
    a0[433] = d;
}

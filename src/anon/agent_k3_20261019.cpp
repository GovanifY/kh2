#include "../common/types.h"

// Agent K3: three leaf functions from SLPM_666.75.
// The other two (FUN_00196618, FUN_0019b380) moved to agent_q1 as plain C.

// FUN_0019ad00 (88 bytes, MATCHED in C)
// Code: t = arg0->+8. If t->u16 at +4 is non-zero, walk its 64-byte records:
// a record matches when byte +72 == 2 and byte +92 == arg1. Returns 1 on a match,
// else 0.
// Guess: "does a table of 64-byte entries contain a type-2 entry with this id".
// Register pins follow the original: table in t6, copy in t3, index in t4,
// constant 2 in t2, the count reloaded through t6. The count is pinned to t7 and
// the address is written as (i<<6)+base so the addu operand order matches.
s32 func_0019ad00(u8* a0, u32 a1) {
    register u8* tb asm("$14");
    register u8* tc asm("$11");
    register s32 i asm("$12");
    register s32 v asm("$2");
    register u32 k asm("$10");
    register u32 lim asm("$15");
    tb = *(u8**)(a0 + 8);
    i = 0;
    __asm__ volatile("" : "+r"(i));
    lim = *(u16*)(tb + 4);
    tc = tb;
    if (lim != 0) {
        k = 2;
        do {
            u8* e = (u8*)((u32)(i << 6) + (u32)tb);
            i++;
            u32 c = e[72];
            tb = tc;
            if (c == k) {
                v = 1;
                if (e[92] == a1) goto done;
            }
            lim = *(u16*)(tb + 4);
        } while (i < (s32)lim);
    }
    v = 0;
    __asm__ volatile("" : "+r"(v));
done:
    return v;
}


#include "../common/types.h"

extern u8 D_01c60000[];
#define TB (*(u8**)&D_01c60000[6920])

// FUN_00196618 (88 bytes)
// Code: t = the pointer stored at 0x01c61b08. Its u16 at +0 is a count; entries are
// 2-byte strides. Returns the first index i with byte[2] == arg0 and byte[3] == arg1,
// else -1.
// Guess: finds (kind, sub-kind) pair in a 2-byte-stride table of records.
// Note: the table pointer is reloaded at the loop tail (gcc copies that load into the bne
//       delay slot); the loop-tail reload plus pins on t/i/n/r give the original shape.
s32 func_00196618(u32 a0, u32 a1) {
    register u8* t asm("$14");
    register s32 i asm("$13");
    register u32 n asm("$15");
    register s32 r asm("$2");
    t = TB;
    i = 0;
    n = *(u16*)t;
    if (n != 0) {
        do {
            u8* e = (u8*)((u32)(i << 1) + (u32)t);
            if (e[2] == a0) {
                r = i;
                if (e[3] == a1) goto done;
            }
            i++;
            t = TB;
            n = *(u16*)t;
        } while (i < (s32)n);
    }
    r = -1;
done:
    return r;
}

// FUN_0019b380 (80 bytes)
// Code: n = arg0->+8->u16 at +8. If n != 0, p = arg0->+44 and walk records:
// p is a record when byte +5 == arg1 (returns p); otherwise advance p by
// 8 + 12 * (u16 at +2). Returns NULL when nothing matches.
// Guess: search a variable-length record list by id (the byte at +5).
// Note: q (pinned t7, shared with the lhu temp) is made live past the loop with an empty
//       asm use on the exit path; that forces addu into t7 and addiu into t5 (p), and
//       lets the addiu fill the bnez delay slot. m is a volatile move copy of n.
u8* func_0019b380(u8* a0, u32 a1) {
    register u8* p asm("$13");
    register s32 i asm("$12");
    register u32 n asm("$15");
    register u32 m asm("$11");
    register u8* h asm("$15");
    register u32 s asm("$15");
    register u8* q asm("$15");
    register u8* r asm("$2");
    h = *(u8**)(a0 + 8);
    i = 0;
    n = *(u16*)(h + 8);
    p = *(u8**)(a0 + 44);
    if (n != 0) {
        __asm__ volatile("move %0,%1" : "=r"(m) : "r"(n));
        do {
            r = p;
            if (p[5] == a1) goto done;
            s = *(u16*)(p + 2);
            i++;
            q = p + s * 12;
            p = q + 8;
        } while (i < (s32)m);
    }
    r = 0;
    __asm__ volatile("" :: "r"(q));
done:
    return r;
}

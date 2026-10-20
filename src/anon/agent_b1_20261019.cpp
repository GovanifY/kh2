#include "../common/types.h"

// FUN_00124c48 (92 bytes)
// Code: p = a0->[+4]; table = p->[+12] ? p + p->[+8] : 0. Table of variable-size records
//   (id at +0, count at +4, record size 16+count*16), terminated by id == -1.
//   Returns the record with id == a1, else 0.
// The original computes the table offset in t7 (lw t7,8(t6); addu v0,t6,t7). Plain C
// puts the load in v0, so the addu is written as inline asm to fix the registers.
struct R { s32 id; s32 n; };
R* func_00124c48(u8* a0, s32 a1) {
    u8* p = *(u8**)(a0 + 4);
    register R* v asm("$2") = 0;
    register s32 off asm("$15");
    if (*(s32*)(p + 12) != 0) { off = *(s32*)(p + 8); __asm__("addu %0,%1,%2" : "=r"(v) : "r"(p), "r"(off)); }
    if (v == 0) goto fail;
    {
        register s32 id asm("$12") = v->id;
        if (id == -1) goto fail;
        for (;;) {
            if (id == a1) goto done;
            register u8* q asm("$13") = (u8*)v + 16;
            v = (R*)(q + (v->n << 4));
            __asm__("" :: "r"(q));
            register s32 nx asm("$14") = v->id;
            if (nx == -1) goto fail;
            id = nx;
        }
    }
fail:
    v = 0;
done:
    return v;
}

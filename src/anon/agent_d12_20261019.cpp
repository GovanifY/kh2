#include "../common/types.h"

// Agent D12 (2026-10-20): three leaf functions. Each matches byte-for-byte in
// the quick single-file harness; see the Makefile and functions.tsv changes.
//
// Shared technique in func_00282c68 and func_00285d18: the first load uses a
// `lui %hi(...)` asm block that writes the base into a pinned register ($14 =
// t6), so gcc cannot fold the address. The matching `%lo` is an asm pair
// (addiu / lb), so the relocations pair up. `register ... asm("$N")` pins the
// registers to the same numbers the original uses. Empty "+r" asm barriers
// stop gcc from merging or moving values across the shape we need.

// FUN_002811f8 (60 bytes). Searches a table of 20-byte records. Count is the
// first word at arg0, and the first s16 of each record is compared with arg1
// (records start at +4). Returns the index of the first match, or -1 if none.
// Shape: loop with a bnezl and a delayed lh in the branch slot, and a shared
// exit whose flag is an explicit slt pinned to $15 (t7), so movn picks the
// index. The asm barrier on i stops gcc from reusing the loop-condition slt.
u32 func_002811f8(u32 a0, s32 a1) {
    register s32 n asm("$14") = *(s32*)a0;
    register s32 i asm("$13") = 0;
    register s32 lt asm("$15");
    if (n > 0) {
        a0 += 4u;
        do {
            if (*(s16*)a0 == a1) goto done;
            a0 += 20u;
            i += 1;
        } while (i < n);
    }
done:
    asm volatile("" : "+r"(i));
    asm volatile("slt %0,%1,%2" : "=r"(lt) : "r"(i), "r"(n));
    return (u32)(lt ? i : -1);
}

extern u8 D_00370000[];

// FUN_00282c68 (80 bytes). Scans a table of 4-byte s16 pairs at D_00370000 +
// 16880, ended by a negative key. For each pair whose key equals arg0, it
// stores the value; the last match wins. Returns that value, or -1.
// The bltz delay slot is `t4 = 0` (placed before the branch so gcc fills the
// slot), and the base lives in t3 via asm addiu from the lui in t6. The loop
// keeps the byte offset in t5 and the index in t4, and reloads the base at the
// loop top, as the original does. No padding flags are needed for this one.
u32 func_00282c68(s32 a0) {
    register s32 v0 asm("$2");
    register u8* t6 asm("$14");
    register u8* t3 asm("$11");
    register s32 t4 asm("$12");
    register s32 t5 asm("$13");
    register s32 t7 asm("$15");
    asm volatile("lui %0,%%hi(D_00370000+16880)\n\tli %1,-1" : "=r"(t6), "=r"(v0));
    t7 = *(s16*)((u8*)t6 + 16880);
    t4 = 0;
    if (t7 < 0) goto out;
    asm("addiu %0,%1,%%lo(D_00370000+16880)" : "=r"(t3) : "r"(t6));
    t5 = 0;
    do {
        t6 = (u8*)((u32)t5 + (u32)t3);
        t7 = *(s16*)t6;
        if (t7 == a0) v0 = ((s16*)t6)[1];
        t4 += 1;
        t7 = t4 << 2;
        t5 = t7;
        t6 = (u8*)((u32)t7 + (u32)t3);
        t7 = *(s16*)t6;
    } while (t7 >= 0);
out:
    return (u32)v0;
}

// FUN_00285d18 (60 bytes). Searches a NUL-free byte list at D_00370000 + 17344
// for the byte arg0. The list ends at the first negative (signed) byte. Returns
// 1 if arg0 is found, 0 otherwise. Signed bytes come from `lb` asm loads
// (gcc's own loads came out as lbu plus sign extension). The increment sits
// in the delay slot of the bne that exits the match test, as in the original.
// Built with -falign-functions=1 -falign-jumps=1 (see Makefile) to drop the
// alignment padding.

static inline s32 lb_(const s8* p) {
    s32 r;
    __asm__("lb %0,0(%1)" : "=r"(r) : "r"(p));
    return r;
}

u32 func_00285d18(s32 a0) {
    register s32 v0 asm("$2");
    register s8* t6 asm("$14");
    register s8* t5 asm("$13");
    register s32 t7 asm("$15");
    asm volatile("lui %0,%%hi(D_00370000+17344)" : "=r"(t6));
    asm volatile("lb %0,%%lo(D_00370000+17344)(%1)" : "=r"(t7) : "r"(t6));
    v0 = 0;
    if (t7 < 0) goto out;
    asm volatile("addiu %0,%0,%%lo(D_00370000+17344)" : "+r"(t6));
    for (;;) {
        t7 = lb_(t6);
        t5 = t6 + 1;
        if (t7 == a0) { v0 = 1; goto out; }
        t6 = t5;
        t7 = lb_(t6);
        if (t7 < 0) break;
    }
out:
    return (u32)v0;
}

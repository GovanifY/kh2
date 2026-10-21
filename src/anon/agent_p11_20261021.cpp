#include "../common/types.h"

// Callees and data used by the three functions below.
extern "C" void func_00135d88(void);            // registered as func_00135d88, no arguments
extern "C" u32 func_0019ba60(void*);            // callee at 0x0019ba60, one pointer argument, returns a word
extern u32 D_00341708[];                        // table of object pointers at 0x00341708 (word 0 is skipped)

typedef void (*vfn_t)(u32);

// FUN_00112388 (100 bytes)
// Code: calls FUN_00135d88(), then runs two passes (s1 = 1, then 0). Each pass walks the
// table D_00341708 starting at word 1. For each non-zero entry it reads the object pointer at
// entry+2912 and calls virtual slot 9 (offset 36 of the vtable) on it.
// Matching: `base` is a pinned temporary (t7) and `p` is pinned to s0. The "+r" barrier keeps the
// table address as its own lui/addiu pair, and the asm "addiu" writes s0 straight from t7 so the
// +4 does not go through an extra move. The pass counter is pinned to s1.
void func_00112388(void) {
    register u32* base asm("$15");      // t7
    register u32* p asm("$16");         // s0
    register s32 n asm("$17") = 1;      // s1
    func_00135d88();
    base = D_00341708;
    asm("" : "+r"(base));
    asm("addiu %0,%1,4" : "=r"(p) : "r"(base));
    do {
        u32 obj = *p;
        p++;
        if (obj != 0) {
            u32 o = *(u32*)(obj + 2912);
            u32* vt = *(u32**)o;
            ((vfn_t)vt[9])(o);
        }
        n--;
    } while (n >= 0);
}

// FUN_00112d28 (104 bytes)
// Code: r = 0 if a0 is null or func_0019ba60(a0) is zero. Otherwise r = 0 when word +1416 has
// bit 0x10 clear, or when word +2040 has bit 0x4 set. Otherwise r = 1 if word +264 has bit
// 0x8000 clear, else 0. Returns r.
// Matching: r (t6) is re-zeroed after the call because t6 is caller-saved. The call result goes
// into a local before the zeroing, which gives the original's `move t6,zero` in the delay slot of
// `beqz v0`. The final compare is one `sltiu` asm writing t6 directly, which avoids a copy at the join.
u32 func_00112d28(u8* a0) {
    register u8* s asm("$16");          // s0: saved argument
    register u32 r asm("$14");          // t6: result
    register u32 t asm("$15");          // t7: scratch
    r = 0;
    if (a0 == 0) goto done;
    s = a0;
    {
        u32 ok = func_0019ba60(a0);
        r = 0;                          // t6 does not survive the call
        if (ok == 0) goto done;
    }
    t = *(u32*)(s + 1416) & 0x10;
    if (t == 0) goto done;
    t = *(u32*)(s + 2040) & 4;
    if (t != 0) goto done;
    t = *(u32*)(s + 264) & 0x8000;
    asm("sltiu %0,%1,1" : "=r"(r) : "r"(t));   // r = (t == 0), written straight into t6
done:
    return r;
}

// FUN_001144e8 (104 bytes)
// Code: the argument a0 is a table header: count at +12, base pointer at +16. The table has
// 36-byte records, and a1 is a 64-bit key whose low word is compared with record+4 and whose high
// word with record+8. Walks up to `count` records. Returns the first record where the low word
// matches and either the high word matches or the key low word is zero. Returns 0 otherwise.
// Matching: the 64-bit key is kept in a stack slot (sd a1 at 0(sp)) and its halves are loaded
// into t4 and t3. A volatile memory barrier keeps the spill ahead of the table load. Loop counter
// is t5, the entry pointer is v0 (also the return value), and the record word is t6.
void* func_001144e8(u8* a0, u64 key) {
    u64 kk = key;
    asm volatile("" ::: "memory");     // keep the key spill ahead of the table load
    u32* kw = (u32*)&kk;
    register u8* v asm("$2");           // v0: entry pointer and return value
    register u8* base asm("$15");       // t7
    register s32 cnt asm("$4");         // a0 (count, reusing the argument register)
    register s32 i asm("$13");          // t5
    register u32 klo asm("$12");        // t4
    register u32 khi asm("$11");        // t3
    register u32 w asm("$14");          // t6
    v = 0;
    base = *(u8**)(a0 + 16);
    asm("" : "+r"(base));
    if (base == 0) goto ret;
    cnt = *(s32*)(a0 + 12);
    i = 0;
    if (cnt <= 0) goto ret;
    klo = kw[0];
    khi = kw[1];
    v = base;
    do {
        w = *(u32*)((u8*)v + 4);
        if (w == klo) {
            if (*(u32*)((u8*)v + 8) == khi) goto ret;
            if (w == 0) goto ret;           // w == klo here, and t6 is the register the original tests
        }
        i++;
        v += 36;
    } while (i < cnt);
    v = 0;
ret:
    return v;
}

#include "../common/types.h"

// Agent D11 leaf batch. Each function reads the global pointer that lives at
// 0x0035F230 (written as 0x360000 - 3536). That pointer is set up with a
// literal `lui 0x36` (inline asm, pinned to $11) and the load uses the
// literal -3536 offset, so no relocation or D_ registry row is needed.
// Each `register` pin and empty `asm volatile("" : "+r"(x))` barrier below
// exists only to reproduce the original register choice and instruction order.

// FUN_002799b0 (96 bytes)
// Code: zeroes the halfword at +4 of the object at 0x35F230, then walks an
// array of 8-byte records (count is the signed byte at +7). For each record
// whose signed byte at +14 is non-zero, adds the signed byte at +17 to the
// halfword at +4. Global is reloaded after the stores, as in the original.
// Guess: recomputes a running total over a table of entries with an enable
// byte, and clears it first.
void func_002799b0(void) {
    register u32 b asm("$11");
    register s32 i asm("$12");
    register u8* p asm("$13");
    register u8* q asm("$14");
    register s32 n asm("$15");
    register u32 v asm("$15");
    register s32 w asm("$14");
    s32 c;
    __asm__("lui %0, 0x36" : "=r"(b));
    *(u16*)(*(u8**)(b - 3536u) + 4) = 0;
    __asm__ volatile("" ::: "memory");
    q = *(u8**)(b - 3536u);
    n = (s8)q[7];
    i = 0;
    if (n > 0) {
        do {
            __asm__ volatile("" ::: "memory");
            p = *(u8**)(b - 3536u);
            q = (u8*)((u32)(i << 3) + (u32)p);
            i++;
            if (*(s8*)(q + 14) != 0) {
                v = *(u16*)(p + 4);
                __asm__ volatile("" ::: "memory");
                w = (s8)q[17];
                v += w;
                *(u16*)(p + 4) = (u16)v;
                __asm__ volatile("" ::: "memory");
                p = *(u8**)(b - 3536u);
            }
            n = (s8)p[7];
            c = (i < n);
            __asm__ volatile("lui %0, 0x36" : "=r"(b));
        } while (c);
    }
}

// FUN_0027ae20 (88 bytes)
// Code: counts the set bits among bits 0..5 of the signed halfword at offset
// 0 of the object at 0x35F230 (loop index 0..6, index 6 skipped). Then returns
// that count plus one if bit 7 of the unsigned halfword is set, else the count.
// Guess: a popcount over a 6-bit flag field with a special high bit that adds
// one more slot.
u32 func_0027ae20(void) {
    register u32 b asm("$15");
    register u8* g asm("$12");
    register s32 i asm("$13");
    register u32 v asm("$2");
    register u32 t asm("$14");
    register u32 b2 asm("$14");
    register s32 x asm("$15");
    register s32 six asm("$11");
    register u32 t4 asm("$12");
    register u8* g2 asm("$13");
    register u32 m asm("$15");
    s32 c;
    v = 0;
    __asm__("lui %0, 0x36" : "=r"(b));
    g = *(u8**)(b - 3536u);
    i = 0;
    six = 6;
    __asm__ volatile("" : "+r"(v));
    do {
        if (i == six) goto cont;
        t = v + 1;
        x = ((s32)*(s16*)g >> i) ^ 1;
        __asm__ volatile("" : "+r"(x));
        if ((x & 1) == 0) v = t;
    cont:
        i++;
        c = (i < 7);
        __asm__ volatile("lui %0, 0x36" : "=r"(b2));
    } while (c);
    t4 = v + 1;
    __asm__ volatile("" ::: "memory");
    g2 = *(u8**)(b2 - 3536u);
    m = *(u16*)g2 & 0x80;
    if (m) v = t4;
    return v;
}

// FUN_0027bf20 (68 bytes)
// Code: takes an index a0 and selects the 8-byte record at 0x35F230 + a0*8.
// Returns 1 if the signed byte at +14 of that record is non-zero. Otherwise
// computes d = max(0, h[+2] - h[+4]) on the object's halfwords and returns
// 1 when d >= the signed byte at +17 of the record, else 0.
// Guess: a "can this slot take more" check comparing a used count with a
// capacity held in the record.
// Needs -falign-functions=1 for this object (the trailing nop after jr ra
// would otherwise be padded to 8 bytes; see the Makefile line for this file).
u32 func_0027bf20(u32 a0) {
    register u32 b asm("$15");
    register u8* base asm("$14");
    register u8* e asm("$4");
    register s32 t4 asm("$12");
    register s32 t5 asm("$13");
    register s32 t3 asm("$11");
    register s32 neg asm("$15");
    register s32 w asm("$15");
    register u32 v asm("$2");
    __asm__("lui %0, 0x36" : "=r"(b));
    a0 = a0 << 3;
    __asm__ volatile("" : "+r"(a0));
    base = *(u8**)(b - 3536u);
    v = 1;
    t4 = *(s16*)(base + 2);
    __asm__ volatile("" : "+r"(t4));
    e = (u8*)(a0 + (u32)base);
    t5 = *(s16*)(base + 4);
    t3 = *(s8*)(e + 14);
    __asm__ volatile("" : "+r"(t3));
    __asm__("subu %0, %0, %1" : "+r"(t4) : "r"(t5));
    __asm__("slti %0, %1, 0" : "=r"(neg) : "r"(t4));
    if (neg) t4 = 0;
    if (t3 != 0) goto ret;
    w = (s8)e[17];
    __asm__("slt %0, %1, %2" : "=r"(w) : "r"(t4), "r"(w));
    __asm__("xori %0, %1, 1" : "=r"(v) : "r"(w));
ret:
    return v;
}

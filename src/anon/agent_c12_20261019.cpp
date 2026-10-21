#include "../common/types.h"

// FUN_00253330 (76 bytes): scans 16-byte records from 0x3726D0 comparing the s16 key at +0
// with a0; the scan stops after the first record whose successor has a negative key. It
// returns the address of the last matching record, or 0 if none matches. Plain C, pins:
// v0=$2, t7=$15, base/t6=$14, t4=$12, t5=$13. The memory barrier after v0 = 0 keeps the
// move before the first load; the movz is tied to the second load so it lands in the
// back-edge delay slot; operand order of the two addu follows the original (t3+t1, t6+t1).
u32 func_00253330(s32 a0) {
    register u32 v0 asm("$2");
    register s32 t7 asm("$15");
    register u8* base asm("$14");
    u8* t1;
    u32 t2;
    u32 t3;
    register u8* t4 asm("$12");
    register u32 t6 asm("$14");
    register u8* t5 asm("$13");
    s16 n;
    base = (u8*)0x370000;
    asm volatile("" : "+r"(base));
    v0 = 0;
    asm volatile("" : "+r"(v0) : : "memory");
    t7 = *(s16*)(base + 9936);
    t2 = 0;
    if (t7 < 0) {
        goto done;
    }
    t1 = base + 9936;
    t3 = 0;
    do {
        t4 = (u8*)((u32)t3 + (u32)t1);
        asm volatile("" : "+r"(t4));
        t2 += 1;
        t6 = t2 << 4;
        asm volatile("" : "+r"(t6) : : "memory");
        t7 = *(s16*)t4;
        t3 = t6;
        t5 = (u8*)((u32)t6 + (u32)t1);
        t7 = (s32)t7 ^ a0;
        n = *(s16*)t5;
        asm volatile("" : "+r"(v0) : "r"(n));
        if (t7 == 0) {
            v0 = (u32)t4;
        }
    } while (n >= 0);
done:
    return v0;
}

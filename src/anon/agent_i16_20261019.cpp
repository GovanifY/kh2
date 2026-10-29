#include "../common/types.h"

// Float constant at 0x374fe0. Its registry entry is func_00374fe0 (a data address).
extern u8 func_00374fe0[];

// FUN_002bc9d8 (52 bytes)
// Code: walks 12-byte records from a0+132 up to a0+300. Returns the word at +0 of the
// first record whose word at +4 equals a1, or -1 if none matches. The loop is a
// do-while, since the first record is always in range.
// Guess: lookup of a record by its key in a fixed table inside an object.
s32 func_002bc9d8(s32 a0, u32 a1) {
    s32 p = a0 + 132;
    s32 end = a0 + 300;
    do {
        if (*(u32*)(p + 4) == a1) {
            return *(s32*)p;
        }
        p += 12;
    } while (p < end);
    return -1;
}

// FUN_002bca10 (56 bytes)
// Code: walks 12-byte records from a0 up to a0+132. Returns a2 if a record has
// word +4 == a1 and word +0 == a2, otherwise -1.
// Guess: match a (key, value) pair in the same fixed table.
s32 func_002bca10(s32 a0, u32 a1, s32 a2) {
    s32 p = a0;
    s32 end = a0 + 132;
    do {
        if (*(u32*)(p + 4) == a1 && *(s32*)p == a2) {
            return a2;
        }
        p += 12;
    } while (p < end);
    return -1;
}

// FUN_002be2d8 (60 bytes)
// Code: obj = *(u8**)(a0 + a1*4 + 44). Copies the three floats at a2[0..2] to
// obj+544, obj+548 and obj+552, then writes the float at 0x374fe0 to obj+556.
// The register pins ($5 sum, $f1/$f2/$f3 for the vector, $14 object, $15 subobject)
// and the memory barriers keep the original load/store order.
// The lui/addiu of the constant are split around the third store to match the schedule.
// Guess: store a 3-float position and a constant scale into an entry of a table at +44.
void func_002be2d8(u32 a0, u32 a1, f32* a2) {
    register u32 q asm("$5") = a1 << 2;
    q = q + a0;
    __asm__("" : "+r"(q));
    register f32 x asm("$f1") = a2[0];
    register f32 z asm("$f3") = a2[2];
    register u8* obj asm("$14") = *(u8**)(q + 44);
    __asm__ volatile("" ::: "memory");
    register f32 y asm("$f2") = a2[1];
    *(f32*)(obj + 544) = x;
    register u8* d asm("$15");
    __asm__ volatile("addiu %0,%1,544" : "=r"(d) : "r"(obj) : "memory");
    *(f32*)(d + 4) = y;
    f32* g;
    __asm__ volatile("lui %0,%%hi(func_00374fe0)" : "=r"(g) :: "memory");
    *(f32*)(d + 8) = z;
    __asm__ volatile("addiu %0,%0,%%lo(func_00374fe0)" : "+r"(g) :: "memory");
    *(f32*)(d + 12) = *g;
}

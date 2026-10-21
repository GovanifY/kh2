#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

// FUN_0023e738 (40 bytes)
// Code: a1 indexes a table of 2-byte entries at a0. The two halfword arguments are sign-extended
//       (sll/sra by 16) and stored at a0 + 2*a1 + 2928 and at +8 past that. The second store goes
//       through a pointer computed before the first store, as in the original.
// Guess: writes an (x, y) pair of 16-bit values into one entry of a halfword table.
// Note: the sign-extension steps are asm volatile so their order (sll a2, sll a3, sra a2, sra a3)
//       matches the original; plain C reorders the shifts and stores.
void func_0023e738(u8* a0, u32 a1, s32 a2, s32 a3) {
    a1 = a1 << 1;
    __asm__ volatile("sll %0,%0,16" : "+r"(a2));
    a1 += (u32)a0;
    register u8* p asm("$5") = (u8*)a1;
    __asm__ volatile("sll %0,%0,16" : "+r"(a3));
    __asm__ volatile("sra %0,%0,16" : "+r"(a2));
    __asm__ volatile("sra %0,%0,16" : "+r"(a3));
    u8* q = p + 2928;
    __asm__("" : "+r"(q));
    *(s16*)(p + 2928) = (s16)a2;
    __asm__ volatile("" ::: "memory");
    *(s16*)(q + 8) = (s16)a3;
}

// FUN_0023e788 (40 bytes)
// Code: the byte at a1 + a2 + 2916 selects one of several 320-byte records that start at a1.
//       The 16-byte value at that record plus 1632 is copied to a0 with one lq/sq pair.
//       Returns a0.
// Guess: copies a 16-byte element (a vector or matrix row) from a selected table entry into the
//       caller's buffer.
// Note: the load goes through t0 ($8) by pinning the 128-bit temporary, and the empty asm on a0
//       keeps the move to v0 in the jr delay slot.
u8* func_0023e788(u8* a0, u8* a1, u32 a2) {
    u32 q = a2 + (u32)a1;
    u32 n = *(u8*)(q + 2916);
    u8* src = a1 + n * 320;
    __asm__("" : "+r"(src));
    src += 1632;
    __asm__("" : "+r"(src));
    register u128 v asm("$8") = *(u128*)src;
    *(u128*)a0 = v;
    __asm__("" : "+r"(a0));
    return a0;
}

// FUN_0023e918 (64 bytes)
// Code: the byte at a0 + a1 + 2916 selects a 320-byte record; the destination is that record + 1664.
//       The function builds {x, y, z, 0} in a 16-byte stack slot and copies it to the destination,
//       unless the destination is that stack slot (a self-copy check, as an inlined vector
//       assignment would produce). The z store sits in the beq delay slot.
// Guess: stores a float4 (x, y, z, w = 0) into one slot of a record in a table.
// Note: the empty memory barrier before the z store puts it after the addiu and gives the beq
//       delay slot the original's filler.
typedef struct { f32 x, y, z; s32 w; } B15Vec4;

void func_0023e918(u8* a0, u32 a1, f32 x, f32 y, f32 z) {
    u32 b = a1 + (u32)a0;
    u32 n = *(u8*)(b + 2916);
    B15Vec4 v;
    v.x = x;
    v.y = y;
    v.w = 0;
    a0 = a0 + n * 320;
    __asm__("" : "+r"(a0));
    a0 += 1664;
    __asm__ volatile("" ::: "memory");
    v.z = z;
    if (a0 != (u8*)&v) {
        register u128 w asm("$8") = *(u128*)&v;
        *(u128*)a0 = w;
    }
}

#include "../common/types.h"

// FUN_00100468 (84 bytes)
// Code: decodes a signed variable-length integer (7 data bits per byte, bit 7 = "more",
//       bit 6 of the last byte = sign) from a0 into a 64-bit value stored at *a1.
//       Sign extension is applied only while the shift count is below 64.
// Guess: a 64-bit varint (LEB128-style) reader for a packed stream.
// Note: the shift count and bit accumulator are pinned to t4/t3, and the byte pointer to v0,
//       so GCC keeps the original register layout. The 32-bit sllv result is OR'ed in as
//       a sign-extended value, and the empty asm stops the "sh += 7" from being hoisted
//       above the shift.
void func_00100468(const u8* a0, u64* a1) {
    register const u8* p asm("$2") = a0;
    register s32 sh asm("$12") = 0;
    register u64 acc asm("$11") = 0;
    register s32 m asm("$10") = -128;
    register u32 b asm("$13");
    register u32 t7 asm("$15");
    do {
        b = *p++;
        acc |= (u64)(s32)((u32)(b & 0x7f) << sh);
        __asm__("" : "+r"(sh));
        sh += 7;
    } while (b & m);
    if ((u32)sh < 64) {
        t7 = b & 0x40;
        if (t7)
            acc |= (u64)-1 << sh;
    }
    *a1 = acc;
}

// FUN_00108930 (84 bytes)
// Code: a0 holds a pointer at +44 to a null-terminated array of 8-byte records (u32 mask,
//       u32 payload). For a bit index a1 in 0..31, the first record whose mask has that bit
//       set gives a pointer to its payload (record + 4). Otherwise, or when a1 is out of
//       range or the list is empty, returns a0 + 4.
// Guess: a bit-flag lookup in a chain of flag/value records (a per-object flag list).
// Note: the first load and the record pointer are pinned to t6/t5. The loop tail, from the
//       beqz of the first word through the back-branch, is one asm block with .set noreorder,
//       so the shift lands in the branch delay slot the way the original does. The asm is
//       needed because GCC never put the shift in that slot. The C epilogue supplies the
//       shared jr ra.
u8* func_00108930(u8* a0, s32 a1) {
    register u8* v0 asm("$2");
    register u8* a0r asm("$4") = a0;
    register u32* p0 asm("$14");
    register u32 one asm("$15");
    register u32* q asm("$13");
    register u32 w asm("$14");
    register u32 bit asm("$5") = a1;
    v0 = a0 + 4;
    p0 = *(u32**)(a0 + 44);
    if (!p0)
        goto ret;
    if (a1 < 0)
        goto ret;
    if (a1 >= 32)
        goto ret;
    one = 1;
    __asm__("" : "+r"(one));
    __asm__ volatile("move %0,%1" : "=r"(q) : "r"(p0));
    w = *p0;
    __asm__ volatile(
        ".set noreorder\n\t"
        "beqz %[w],2f\n\t"
        "sllv %[bit],%[one],%[bit]\n\t"
        "1:\n\t"
        "addiu %[v0],%[q],4\n\t"
        "and %[one],%[w],%[bit]\n\t"
        "bnez %[one],2f\n\t"
        "addiu %[q],%[q],8\n\t"
        "lw %[one],0(%[q])\n\t"
        "bnez %[one],1b\n\t"
        "move %[w],%[one]\n\t"
        "addiu %[v0],%[a0],4\n\t"
        "2:\n\t"
        ".set reorder\n\t"
        : [v0] "+r"(v0), [q] "+r"(q), [w] "+r"(w), [one] "+r"(one), [bit] "+r"(bit)
        : [a0] "r"(a0r)
        : "memory");
ret:
    return v0;
}

// FUN_001142e0 (72 bytes)
// Code: a0+8 holds a base pointer. Returns the float at base + (a1 << 3) + off, where
//       off is 0 when a2 == 0, 64 when a2 != 0 and a3 == 0, and 32 when a2 != 0 and a3 != 0.
//       a2 and a3 are tested as bytes. The float comes back in $f0.
// Guess: a table of 8-byte float pairs indexed by a1, with a two-flag choice of which
//        member to read.
// Note: the index is pinned to t6 and each arm's shift is fenced with an empty asm, so the
//       original layout and the base load in the branch delay slot are reproduced. The two
//       "addu" steps are explicit asm, because GCC put the sum in the base register and used
//       the other operand order.
f32 func_001142e0(u8* a0, s32 a1, u8 a2, u8 a3) {
    register u32 idx asm("$14") = a1 << 3;
    if (a2 != 0) {
        register u8* base asm("$14") = *(u8**)(a0 + 8);
        if (a3 != 0) {
            __asm__("" : "+r"(a1));
            register u32 off asm("$15") = a1 << 3;
            __asm__("addu %0,%0,%1" : "+r"(off) : "r"(base));
            return *(f32*)((u8*)off + 32);
        }
        __asm__("" : "+r"(a1));
        register u32 off2 asm("$15") = a1 << 3;
        __asm__("addu %0,%0,%1" : "+r"(off2) : "r"(base));
        return *(f32*)((u8*)off2 + 64);
    }
    register u8* b asm("$15") = *(u8**)(a0 + 8);
    __asm__("addu %0,%1,%0" : "+r"(b) : "r"(idx));
    return *(f32*)b;
}

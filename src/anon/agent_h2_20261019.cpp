#include "../common/types.h"

// 128-bit quadword type: plain assignments compile to lq/sq.
typedef int u128 __attribute__((mode(TI)));

extern u8 D_0034a9c0;
extern u8 D_0034a9d0;
extern u8 D_0034a9e0;

// FUN_00144570 (92 bytes)
// Code: copies the 16 bytes at arg1 to a stack temporary (skipped when the temporary is arg1
//       itself), s = arg1 float at +16. Then out[0..2] = temp[0..2] - s and out[3..5] = temp[0..2] + s.
// Guess: builds a six-float pair of (value - offset, value + offset) from a vector and a scalar.
// Note: the copy is plain C with the quadword pinned to $8. The six add/sub/store instructions
//       are one asm block, because GCC kept picking different FP registers and store order.
//       Pins: out pointer in $4, adds in $f4..$f6, the vector in $f1..$f3, the scalar in $f0.
void func_00144570(f32* a0, u8* a1) {
    f32 tmp[4];
    f32* t = tmp;
    if ((u8*)t != a1) {
        register u128 q asm("$8");
        q = *(u128*)a1;
        *(u128*)t = q;
    }
    register f32* p asm("$4") = a0;
    register f32 s asm("$f0") = *(f32*)(a1 + 16);
    register f32 x asm("$f1") = t[0];
    register f32 y asm("$f2") = t[1];
    register f32 z asm("$f3") = t[2];
    __asm__ volatile(
        "add.s $f4,$f1,$f0\n\t"
        "add.s $f5,$f2,$f0\n\t"
        "add.s $f6,$f3,$f0\n\t"
        "sub.s $f1,$f1,$f0\n\t"
        "sub.s $f2,$f2,$f0\n\t"
        "sub.s $f3,$f3,$f0\n\t"
        "swc1 $f4,12($4)\n\t"
        "swc1 $f5,16($4)\n\t"
        "swc1 $f6,20($4)\n\t"
        "swc1 $f1,0($4)\n\t"
        "swc1 $f2,4($4)\n\t"
        "swc1 $f3,8($4)"
        : "+f"(x), "+f"(y), "+f"(z), "+f"(s)
        : "r"(p)
        : "$f4", "$f5", "$f6", "memory");
}

// FUN_0014b950 (88 bytes)
// Code: r = arg2 + (arg4 & 0xffff) - 1 and s = arg1 + (arg3 & 0xffff) - 1, both on sign-extended
//       halfwords. Packs a 64-bit word at arg0+16: bits 0..15 = arg1 (sign-extended), 48..63 = r,
//       32..47 = arg2 (sign-extended), 16..31 = s.
// Guess: packs four 16-bit fields (two signed coordinates and two adjusted extents) into a
//        64-bit record.
// Note: the expression is grouped so the shifts are scheduled as in the original. The
//       "+r" barrier on the sign-extended arg1 keeps its dsra32 after the other shifts.
void func_0014b950(u8* a0, s16 x, s16 y, u16 z, u16 w) {
    s32 r = (s16)y + w - 1;
    s32 s = (s16)x + z - 1;
    u64 Ra = (u64)(s64)r << 48;
    u64 Pa = (u64)(s64)(s16)y << 32;
    u64 Sa = (u64)(s64)s << 16;
    u64 b = Pa | Sa;
    u64 Qa = (u64)(s64)(s16)x;
    __asm__("" : "+r"(Qa));
    u64 a = Qa | Ra;
    *(u64*)(a0 + 16) = a | b;
}

// FUN_00158ac8 (84 bytes)
// Code: if arg0+144 is not the global at 0x34a9c0, copy 16 bytes from arg0+144 to it. If arg0+112
//       is not the global at 0x34a9d0, copy 16 bytes from arg0+112 to it. Then the global float
//       at 0x34a9e0 = arg0 float at +72, and the global float at 0x34a9e4 = arg0 float at +80.
// Guess: the save half of a pair of default-value copies. It stores the two 16-byte blocks and
//        two float fields of an object into the globals (the mirror of FUN_00158b20).
// Note: the copies and the first float store are one noreorder asm block (the address pins
//       and the beql delay slots need exact placement). The last store is written with an
//       explicit `lui` ($15 = 0x350000) and a constant offset, so it stays in C and GCC fills
//       the return's delay slot with it.
void func_00158ac8(u8* a0) {
    register u8* a asm("$4") = a0;
    register f32 v asm("$f1");
    register u8* e asm("$15");
    __asm__ volatile(
        ".set noreorder\n"
        "lui    $15, %%hi(D_0034a9c0)\n"
        "addiu  $14, $4, 144\n"
        "addiu  $15, $15, %%lo(D_0034a9c0)\n"
        "beql   $14, $15, 1f\n"
        "lui    $15, %%hi(D_0034a9c0)\n"
        "lq     $8, 0($14)\n"
        "sq     $8, 0($15)\n"
        "lui    $15, %%hi(D_0034a9c0)\n"
        "1:\n"
        "addiu  $14, $4, 112\n"
        "addiu  $15, $15, %%lo(D_0034a9d0)\n"
        "beql   $14, $15, 2f\n"
        "lwc1   $f0, 72($4)\n"
        "lq     $8, 0($14)\n"
        "sq     $8, 0($15)\n"
        "lwc1   $f0, 72($4)\n"
        "2:\n"
        "lui    $15, %%hi(D_0034a9e0)\n"
        "swc1   $f0, %%lo(D_0034a9e0)($15)\n"
        "lwc1   $f1, 80($4)\n"
        ".set reorder\n"
        : "+r"(a), "=f"(v) : : "$8", "$14", "$15", "$f0", "memory");
    __asm__("lui %0, 0x35" : "=r"(e));
    *(f32*)(e - 22044) = v;
}

#include "../common/types.h"

extern u8 D_00350000[];

// FUN_0015c228 (84 bytes)
// Code: if a0 is NULL, zeroes the words at 0x350000-20700 and 0x350000-20704.
//       Otherwise stores a0 + a0[0] at 0x350000-20704, the unsigned quotient
//       a0[1] / 104 at 0x350000-20700, and zeroes the 8 bytes at 0x350000-20688.
// Guess: a header {base offset, byte count} where the count is divided by a 104-byte
//        record size. The pointer and count land in two globals, and the 8-byte zero
//        clears a third.
// Note: the store bases are literal 0x350000 values in volatile-asm lui/li/lw pieces
//       so gcc keeps the original order and register picks. The divide keeps gcc's
//       zero check (beqzl + break 7). The final lui + mflo is one asm block.
void func_0015c228(u32* a0) {
    if (a0 == 0) {
        register u8* p1 asm("$15") = (u8*)0x350000;
        __asm__("" : "+r"(p1));
        *(u32*)(p1 - 20700) = 0;
        register u8* p2 asm("$14") = (u8*)0x350000;
        __asm__("" : "+r"(p2));
        *(u32*)(p2 - 20704) = 0;
        return;
    }
    register u32 w asm("$15") = a0[0];
    register u8* p asm("$14");
    __asm__ volatile("lui %0,0x35" : "=r"(p));
    register u32 d asm("$12");
    __asm__ volatile("li %0,104" : "=r"(d));
    *(u32*)(p - 20704) = (u32)a0 + w;
    register u32 n asm("$13");
    __asm__ volatile("lw %0,4(%1)" : "=r"(n) : "r"(a0) : "memory");
    register u8* p3 asm("$15");
    __asm__ volatile("lui %0,0x35" : "=r"(p3));
    __asm__ volatile(".set noreorder\n\tbeqzl %1,1f\n\tbreak 7\n1:\n\tdivu $0,%2,%1\n\t.set reorder"
                     :
                     : "r"(d), "r"(d), "r"(n)
                     : "memory");
    *(u64*)(p3 - 20688) = 0;
    register u32 q asm("$13");
    register u8* p4 asm("$14");
    __asm__ volatile("lui %1,0x35\n\tmflo %0" : "=r"(q), "=r"(p4) : : "memory");
    *(u32*)(p4 - 20700) = q;
}

// FUN_00162b18 (80 bytes)
// Code: dot = a0.xyz . a1.xyz (VU0); dot += a1[3]; *a2 = dot. Returns 0 when a0[4] < dot,
//       otherwise 1 when dot >= 0 and 0 when dot < 0.
// Guess: the same distance test as FUN_00162b68 (plane distance against the radius at +16),
//        with a sign check on the distance.
// Note: the VU0 dot product is one asm block (matches FUN_00162b68). The return shape is
//       written as a v = 0 / guarded v = 1 pair so gcc uses a branch-likely with li in the
//       delay slot.
s32 func_00162b18(void* a0, void* a1, f32* a2) {
    f32 x;
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vmul.xyz $vf1,$vf1,$vf2\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "qmfc2 $8,$vf1\n\t"
        "mtc1 $8,%0\n\t"
        : "=f"(x)
        : "r"(a0), "r"(a1)
        : "$8");
    f32 d = x + ((f32*)a1)[3];
    *a2 = d;
    f32 r = ((f32*)a0)[4];
    s32 v = 0;
    if (!(r < d)) {
        if (!(d < 0.0f))
            v = 1;
    }
    return v;
}

// FUN_00166c80 (36 bytes)
// Code: sign-extends the low halfword of each argument and stores the two halfwords at
//       0x350000-14220 (0x34c874) and 0x350000-14218 (0x34c876).
// Guess: a pair of signed 16-bit state values written by a setter.
// Note: the parameters are s16, so gcc emits no sll/sra pairs (an s32 version did).
void func_00166c80(s16 a0, s16 a1) {
    *(s16*)(&D_00350000[-14220]) = a0;
    *(s16*)(&D_00350000[-14218]) = a1;
}

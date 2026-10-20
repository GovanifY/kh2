#include "../common/types.h"

extern s16 D_00369d98[];
extern f32 D_00340eb4;
extern f32 D_00340eb8;
extern f32 D_00340ebc;
extern f32 D_00340ec0;
extern f32 D_0036a3dc;
extern f32 D_0036a3e0;

// FUN_00103428 (88 bytes)
// Code: scans the s16 list at 0x369d98 (terminated by a negative entry) for a0;
//       returns 1 if found, else 0.
// Guess: membership test in a negative-terminated id list.
// Note: result pinned to $2 gives the original early `move v0,zero` and the inline
//       `jr ra; li v0,1` found-return with a branch-likely.
u32 func_00103428(s32 a0) {
    register u32 r asm("$2") = 0;
    s32 i = 0;
    if (D_00369d98[0] >= 0) {
        do {
            if (a0 == D_00369d98[i]) { r = 1; break; }
            i++;
        } while (D_00369d98[i] >= 0);
    }
    return r;
}

// FUN_0010a828 (92 bytes)
// Code: stores near (a0=$f12) / far (a1=$f13) at 0x340eb4 / 0x340eb8 and derives
//       0x340ec0 = D_0036a3dc * far / (far - near), 0x340ebc = D_0036a3e0 / (far - near).
// Guess: sets up depth/fog range parameters (the two constants are float literals in the
//        original, hence the lui+addiu+lwc1 loads).
// Note: asm lui/addiu pieces and memory barriers reproduce the original instruction order
//       (ebc's lui hoisted into t6 at the top, sub.s after both stores).
void func_0010a828(f32 a, f32 b) {
    u32 h, p;
    f32* q;
    __asm__ volatile("lui %0,%%hi(D_0036a3dc)" : "=r"(p));
    __asm__ volatile("lui %0,%%hi(D_00340ebc)" : "=r"(h));
    __asm__ volatile("addiu %0,%1,%%lo(D_0036a3dc)" : "=r"(q) : "r"(p));
    f32 c = b * *q;
    D_00340eb8 = b;
    __asm__ volatile("" ::: "memory");
    D_00340eb4 = a;
    __asm__ volatile("" ::: "memory");
    f32 d = b - a;
    q = &D_0036a3e0;
    __asm__("" : "+r"(q));
    f32 e = *q;
    D_00340ec0 = c / d;
    f32 g = e / d;
    __asm__ volatile("swc1 %1,%%lo(D_00340ebc)(%0)" :: "r"(h), "f"(g) : "memory");
}

struct T114328 { u8 pad[8]; u8* tbl; };
// FUN_00114328 (72 bytes)
// Code: reads an f32 from the table at +8 of a0, entry a1 (8-byte stride): at +4 when
//       (u8)a2 == 0, else at +0x24 when (u8)a3 != 0, else at +0x44.
// Guess: getter for one of three float arrays of an entry, selected by two flags.
f32 func_00114328(T114328* a0, s32 a1, u32 a2, u32 a3) {
    if ((u8)a2) {
        if ((u8)a3) {
            return *(f32*)(a0->tbl + a1 * 8 + 0x24);
        }
        return *(f32*)(a0->tbl + a1 * 8 + 0x44);
    }
    return *(f32*)(a1 * 8 + a0->tbl + 4);
}

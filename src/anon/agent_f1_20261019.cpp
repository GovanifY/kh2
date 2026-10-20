#include "../common/types.h"

extern u32 D_00330000[];
extern u32 D_003a0000[];
extern u8 D_00370000[];

// FUN_001056e8 (40 bytes)
// Code: the word at 0x32bb28 is a counter. It is decremented, and a0 is stored
// in the table at 0x3a7b60 at the new index (count * 4).
// Guess: pop-style push onto a stack of ids, where the count is the top index.
// Layout: &D_00330000[-4406] is the counter, folded as a -17624 load/store offset.
void func_001056e8(u32 a0) {
    u32* cnt = &D_00330000[-4406];
    u32 n = *cnt - 1;
    *cnt = n;
    u32* tab = D_003a0000 + 7896;
    tab[n] = a0;
}

// FUN_00111278 (44 bytes)
// Code: x = word at +2924 of a0. Returns 1 if x is 16, 12 or 15, else 0.
// Guess: a predicate over a state code stored in the object.
// Layout: the goto chain keeps the constant loads in delay slots and puts the
// "r = 0" in the last branch's delay slot, as the original does.
s32 func_00111278(u8* a0) {
    register s32 x asm("$14") = *(s32*)(a0 + 2924);
    register s32 k asm("$15");
    register s32 r asm("$2");
    k = 16;
    if (x == k) goto T;
    k = 12;
    if (x == k) goto T;
    k = 15;
    if (x != k) {
        r = 0;
        goto F;
    }
T:
    r = 1;
F:
    return r;
}

// FUN_00134d10 (60 bytes)
// Code: zeroes words 0 and 8 of the object, then stores two float constants
// from 0x36ac48 (value f0) and 0x36ac4c (value f1) into words 4, 12, 16, 20,
// 24 and 28 (f1 goes to +4, the others get f0).
// Guess: reset a 2D or 3D parameter block to default values.
// Layout: each address is a lui/addiu pair written in asm so GCC keeps the two
// separate and uses the same $15 for both. Memory barriers pin the store order.
struct S134 {
    u32 a;
    f32 b;
    u32 c;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
    f32 h;
};

void func_00134d10(struct S134* p) {
    register f32* q0 asm("$15");
    register f32* q1 asm("$15");
    f32 f0;
    f32 f1;
    __asm__ volatile("lui %0,%%hi(D_00370000-21432)" : "=r"(q0));
    p->a = 0;
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000-21432)" : "+r"(q0));
    p->c = 0;
    f0 = *q0;
    __asm__ volatile("lui %0,%%hi(D_00370000-21428)" : "=r"(q1));
    p->h = f0;
    __asm__ volatile("" ::: "memory");
    __asm__ volatile("addiu %0,%0,%%lo(D_00370000-21428)" : "+r"(q1));
    p->d = f0;
    __asm__ volatile("" ::: "memory");
    f1 = *q1;
    p->e = f0;
    __asm__ volatile("" ::: "memory");
    p->b = f1;
    __asm__ volatile("" ::: "memory");
    p->f = f0;
    __asm__ volatile("" ::: "memory");
    p->g = f0;
}

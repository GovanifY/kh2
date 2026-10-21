#include "../common/types.h"


// FUN_002cd260 (48 bytes)
// Code: if byte +135 of arg0 is zero, return. Otherwise store zero at +24, load a
//       float from 0x370000 + 0x58ec, store zero at +136, store zero at +4, store
//       the float at +28, store zero at +8. The stores are in this exact order.
// Guess: reset a timer/position record and seed its +28 field from a constant.
// Technique: each store is separated by an empty asm with a memory clobber so GCC
//       keeps the original order, and the address is built as lui then addiu
//       with a barrier, so the float load uses offset 0 as in the original.
void func_002cd260(u32 a0) {
    if (*(u8*)(a0 + 135) == 0)
        return;
    *(u32*)(a0 + 24) = 0;
    u8* q = (u8*)0x00370000;
    __asm__ volatile("" : "+r"(q));
    q = q + 22764;
    __asm__ volatile("" : "+r"(q));
    *(u32*)(a0 + 136) = 0;
    f32 c = *(f32*)q;
    *(u32*)(a0 + 4) = 0;
    __asm__ volatile("" ::: "memory");
    *(f32*)(a0 + 28) = c;
    __asm__ volatile("" ::: "memory");
    *(u32*)(a0 + 8) = 0;
}

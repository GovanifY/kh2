#include "../common/types.h"

// Table/global symbols used by the three functions below.
// D_0032bae0: 4-byte source block read after the call (also has a registry line).
// D_0032bb30: 16-byte destination block, bytes +12..+14 are written (existing registry line).
// D_0032bb1c: word global written by FUN_00105370 (registry line added with these functions).
extern u8 D_0032bae0[];
extern u8 D_0032bb30[];
extern u32 D_0032bb1c[];

// Callees. func_00104d30 is a byte-copy helper (dst = a0, src = a1, 4-byte steps).
// func_00170b30 is an allocator-style call that takes two arguments.
// func_00106178 creates a memory allocator on a block; func_001091c8 takes three arguments.
extern "C" void func_00104d30(u8* a0, u8* a1);
extern "C" u32 func_00170b30(u32 a0, u32 a1);
extern "C" u32 func_00106178(u32 a0, u32 a1);
extern "C" u32 func_001091c8(u32 a0, u32 a1, u32 a2);

// FUN_001052a8 (88 bytes)
// Code: calls func_00104d30(&D_0032bae0, a0), then copies bytes 0, 1 and 2 of D_0032bae0 to
// bytes 12, 13 and 14 of D_0032bb30. The move a1,a0 is the second argument of the call.
// Guess: loads a 3-byte header from a source block into a small state record after a copy.
void func_001052a8(u32 a0) {
    func_00104d30(D_0032bae0, (u8*)a0);
    D_0032bb30[12] = D_0032bae0[0];
    D_0032bb30[13] = D_0032bae0[1];
    D_0032bb30[14] = D_0032bae0[2];
}

// FUN_00105370 (80 bytes)
// Code: r = func_00170b30(a0, a1); w = func_00106178(r, a0); stores w in D_0032bb1c, then
// tail-calls func_001091c8(w, 256, a1).
// Guess: creates a block allocator from a fresh allocation and records it in a global slot.
u32 func_00105370(u32 a0, u32 a1) {
    u32 v = func_00170b30(a0, a1);
    u32 w = func_00106178(v, a0);
    D_0032bb1c[0] = w;
    return func_001091c8(w, 256, a1);
}

// FUN_00105550 (104 bytes)
// Code: saves gp, sp, s8, ra, s0..s7 as 16-byte quadwords and f20..f31 as words at a0+0..+236,
// then returns 0. Written as one asm block (sq and swc1 in original order); the return
// value is C so gcc produces the jr ra and the move v0,zero pair.
// Guess: saves the callee-saved register set into a context block (setjmp-like).
u32 func_00105550(void* a0) {
    __asm__ volatile(
        "sq $28,0(%0)\n\t"
        "sq $29,16(%0)\n\t"
        "sq $30,32(%0)\n\t"
        "sq $31,48(%0)\n\t"
        "sq $16,64(%0)\n\t"
        "sq $17,80(%0)\n\t"
        "sq $18,96(%0)\n\t"
        "sq $19,112(%0)\n\t"
        "sq $20,128(%0)\n\t"
        "sq $21,144(%0)\n\t"
        "sq $22,160(%0)\n\t"
        "sq $23,176(%0)\n\t"
        "swc1 $f20,192(%0)\n\t"
        "swc1 $f21,196(%0)\n\t"
        "swc1 $f22,200(%0)\n\t"
        "swc1 $f23,204(%0)\n\t"
        "swc1 $f24,208(%0)\n\t"
        "swc1 $f25,212(%0)\n\t"
        "swc1 $f26,216(%0)\n\t"
        "swc1 $f27,220(%0)\n\t"
        "swc1 $f28,224(%0)\n\t"
        "swc1 $f29,228(%0)\n\t"
        "swc1 $f30,232(%0)\n\t"
        "swc1 $f31,236(%0)\n\t"
        : : "r"(a0) : "memory");
    return 0;
}

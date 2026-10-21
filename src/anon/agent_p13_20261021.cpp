#include "../common/types.h"

// Callees. func_0011c798 and func_0011ca20 are still asm; func_00132350 is the
// kn::AnimationWork::getNext step (registered as _ZNK2kn13AnimationWork7getNextEv).
void func_0011c798(u32, u32);
void func_0011ca20(u32, u32, u32, u32, u32);
u32 func_00132350(u32 a0);

typedef u32 (*vfn3_t)(u32, u32, u32);
typedef void (*vfnf_t)(u32, float);

// FUN_0011c7f8 (48 bytes)
// Code: obj = self->+20; calls obj's vtable slot 16 (offset 64) with
// (obj, self->+260, a1) and returns that result. The frame holds ra only.
// The register variables pin obj/vtable/fn to t5/t6/t7, which is what the
// original uses. Without the pins gcc picks t6/t7/v0 and the bytes differ.
u32 func_0011c7f8(u32 a0, u32 a1) {
    register u32 obj asm("$13");
    register u32 vt asm("$14");
    register u32 fn asm("$15");
    obj = *(u32*)(a0 + 20);
    vt = *(u32*)obj;
    fn = *(u32*)(vt + 64);
    return ((vfn3_t)fn)(obj, *(u32*)(a0 + 260), a1);
}

// FUN_0011cd80 (108 bytes)
// Code: saves a0..a3, t0, t1 in s-registers. Calls func_0011c798(a0, a4) (a4
// is the 5th argument, in t0), then tail-jumps to func_0011ca20(a0, a1, a2, a3,
// a5), where a5 is the 6th argument (in t1). The 5th argument is not passed on.
void func_0011cd80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    func_0011c798(a0, a4);
    func_0011ca20(a0, a1, a2, a3, a5);
}

// FUN_0011ea40 (84 bytes)
// Code: p = self->+56. While p is non-null, calls p's vtable slot 5 (offset 20)
// with (p, f) and sets p = func_00132350(p). The float argument stays in f20
// across the loop. That is why the original saves f20 in the frame.
// The loop body is a plain while loop; the shape and register use match.
void func_0011ea40(u32 a0, float f) {
    u32 p = *(u32*)(a0 + 56);
    while (p) {
        vfnf_t fn = (vfnf_t)*(u32*)(*(u32*)p + 20);
        fn(p, f);
        p = func_00132350(p);
    }
}

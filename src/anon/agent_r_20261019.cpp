#include "../common/types.h"

extern u8 D_00350000;
extern u8 D_00360000;

void func_0018d420(u32);
void func_00105110(u32);
void func_002e95a0(u32, float, float);
void func_00139d78(u32);
void func_002bd7d8(void);
u32* func_00103580(void);
void func_001a4e30(u32);

// FUN_0031f238 (52 bytes)
// Code: set vtable (0x350778) in a0, call base dtor func_0018d420(a0), then free a0.
// Guess: deleting-style destructor.
void func_0031f238(u32 a0) {
    *(u32*)a0 = (u32)(&D_00350000 + 1912);
    func_0018d420(a0);
    func_00105110(a0);
}

// FUN_002e8c58 (36 bytes)
// Code: tail-call func_002e95a0(a0[0], a0[1], a0[2]) with the last two as floats.
// Guess: unpack a struct { id, float x, float y } into call args.
void func_002e8c58(u32* a0) {
    func_002e95a0(a0[0], ((float*)a0)[1], ((float*)a0)[2]);
}

// FUN_0023f740 (52 bytes)
// Code: call func_00139d78(a0), then store a1 at a0+68.
// Guess: init base then set a field.
void func_0023f740(u32* a0, u32 a1) {
    func_00139d78((u32)a0);
    a0[17] = a1;
}

// FUN_00284ea8 (68 bytes)
// Code: call func_002bd7d8(); o = func_00103580(); o->vtbl[1](o, global); clear global.
// Guess: notify a singleton with a pending value, then reset it.
struct R_Obj {
    virtual void v0(u32);
    virtual void v1(u32);
};
void func_00284ea8(void) {
    func_002bd7d8();
    R_Obj* o = (R_Obj*)func_00103580();
    o->v1(*(u32*)(&D_00360000 - 3392));
    *(u32*)(&D_00360000 - 3392) = 0;
}

// FUN_001d74f8 (60 bytes)
// Code: set vtable (0x3527f0), clear a global word at 0x3527e4, call func_001a4e30(a0), free a0.
// Guess: deleting-style destructor.
void func_001d74f8(u32 a0) {
    *(u32*)a0 = (u32)(&D_00350000 + 10224);
    *(u32*)(&D_00350000 + 10212) = 0;
    func_001a4e30(a0);
    func_00105110(a0);
}

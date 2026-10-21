#include "../common/types.h"

// Global block at D_00348D68 (= D_00350000 - 29336), used by two of the functions below.
extern u8 D_00348d68[];

// Callees. Names with a func_ registry line are declared extern "C" (they resolve to the
// registry alias). FUN_001492c8 is registered under its C++ mangled name (misc_1.cpp), so it
// keeps C++ linkage here.
extern "C" void func_00149448(u8* a0);
s32 func_001492c8(void* self);
extern "C" void func_0015c228(u32 a0);
extern "C" u32 func_001050c8(void);
extern "C" u32 func_0015eba8(u8* a0, u32 a1, u32 a2, u32 a3);
extern "C" void func_0015a850(u8* a0);
extern "C" void func_00153c80(void);
extern "C" void func_0014f148(void);
extern "C" void func_0014f220(void);
extern "C" void func_0014f1e0(void);
extern "C" void func_0014f288(void);
extern "C" void func_0015edb8(void);
extern "C" void func_00165968(void);
extern "C" void func_00149bd0(u8* a0);
extern "C" void func_00149de0(u8* a0);
extern "C" u32 func_0014a9a0(u8* a0, u32 a1, u32 a2, u32 a3);

// FUN_00149c40 (96 bytes)
// Code: calls FUN_00149448(X), r = FUN_001492c8(X), FUN_0015c228(r), r2 = FUN_001050c8(),
//       then tail-calls FUN_0015eba8(X, r2, 1, a0), where X = D_00348D68.
// Matching: the straight-line calls keep the original order. gcc emits the same frame
//       (s0 = X, s1 = a0, ra saved) and the same delay-slot moves without any pins.
u32 func_00149c40(u8* a0) {
    u8* x = D_00348d68;
    func_00149448(x);
    u32 r = (u32)func_001492c8(x);
    func_0015c228(r);
    u32 r2 = func_001050c8();
    return func_0015eba8(x, r2, 1, (u32)a0);
}

// FUN_00149ec0 (108 bytes)
// Code: calls FUN_0015a850(a0), then seven no-argument calls (FUN_00153c80, FUN_0014f148,
//       FUN_0014f220, FUN_0014f1e0, FUN_0014f288, FUN_0015edb8, FUN_00165968), then
//       FUN_00149bd0(D_00348D68), then tail-calls FUN_00149de0(a0).
// Matching: the object needs -falign-functions=1 (Makefile), because the 108-byte body does not
//       end on an 8-byte boundary and gcc would otherwise pad it with a trailing nop.
void func_00149ec0(u8* a0) {
    func_0015a850(a0);
    func_00153c80();
    func_0014f148();
    func_0014f220();
    func_0014f1e0();
    func_0014f288();
    func_0015edb8();
    func_00165968();
    func_00149bd0(D_00348d68);
    func_00149de0(a0);
}

// FUN_0014aa80 (40 bytes)
// Code: word at +248 = 1; byte at +244 = a2 & 0xff; word at +252 = 1; then tail-calls
//       FUN_0014a9a0(a0, a1, a2 & 0xff, a3).
// Matching: the byte is masked in place (a2 &= 0xff, so andi writes a2 directly), and the
//       stores are kept in the original order with empty memory barriers. A pinned register $14
//       (t6) holds the constant 1, so gcc emits li t6,1 before sd ra, as the original does.
u32 func_0014aa80(u8* a0, u32 a1, u32 a2, u32 a3) {
    register u32 one asm("$14") = 1;
    a2 &= 0xff;
    *(u32*)(a0 + 248) = one;
    asm volatile("" ::: "memory");
    *(u8*)(a0 + 244) = (u8)a2;
    asm volatile("" ::: "memory");
    *(u32*)(a0 + 252) = one;
    return func_0014a9a0(a0, a1, a2, a3);
}

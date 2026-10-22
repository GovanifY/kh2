#include "../common/types.h"

// Agent V04 (2026-10-22): FUN_0015de98, FUN_0015edb8, FUN_00160430 (SLPM_666.75).
// Each comment says what the code does, then the matching notes.

// Callees.
extern "C" void func_0031dd50(u32);            // takes the new object in a0; result unused
extern "C" u32 func_001de568(u32);             // C++ static PAX::ThisIsValid (registered as mangled name); returns nonzero when valid
extern "C" void func_001dde40(u32);            // called with the same object when the check passes
extern "C" void func_00142f50(void);           // tail target, no arguments
extern "C" void func_00161598(u32);            // takes a pointer (this + 272) in a0
extern "C" void func_00161668(u32, f32);       // takes a pointer in a0 and a float in $f12
extern "C" void func_0011ea40(f32, u32);       // tail target, float in $f12, pointer in a0

extern u8 D_00350000[];   // base for the globals below (lui 0x35 + signed low offsets)
extern u8 D_0034C6F0[];   // object address used by FUN_0015edb8 (lui/addiu pair)

typedef u32 (*VfnA)(u32, u32, u32);   // virtual slot 0: allocate-like call with (this, size, ra)
typedef void (*VfnB)(u32);            // virtual slot 0 of the new object, called with itself

// FUN_0015de98 (92 bytes).
// Code: obj = *(D_00350000 - 19848). v = obj->vtable[0](obj, 4928, ra). Then calls
// func_0031dd50(v), stores v to D_00350000 - 19904, and calls v->vtable[0](v).
// Matching: the ra value is passed as the third argument through __builtin_return_address,
// which gives "move a2,ra". The vtable chains are pinned to $15 (t7) and $14 (t6) so
// the register names match the original. The first chain is plain C, and the second
// chain's pins gave the same bytes in this order (variant "va").
void func_0015de98(void) {
    u32 obj = *(u32*)(D_00350000 - 19848);
    register u32 vt asm("$15") = *(u32*)obj;
    u32 s0 = ((VfnA)(*(u32*)vt))(obj, 4928, (u32)__builtin_return_address(0));
    func_0031dd50(s0);
    *(u32*)(D_00350000 - 19904) = s0;
    register u32 vt2 asm("$15") = *(u32*)s0;
    register u32 fp asm("$14") = *(u32*)vt2;
    ((VfnB)fp)(s0);
}

// FUN_0015edb8 (88 bytes).
// Code: if the byte at D_00350000 - 14580 is 1, calls func_001de568(&D_0034C6F0). If that
// returns nonzero, calls func_001dde40 on the same object. Then clears the byte and
// tail-calls func_00142f50.
// Matching: the object address is a symbol (D_0034C6F0), so gcc emits lui s0 and an addiu
// that the link fills with -14608. A constant address gave a different register layout.
void func_0015edb8(void) {
    if (*(u8*)(D_00350000 - 14580) == 1) {
        u32 obj = (u32)D_0034C6F0;
        if (func_001de568(obj)) func_001dde40(obj);
    }
    *(u8*)(D_00350000 - 14580) = 0;
    func_00142f50();
}

// FUN_00160430 (84 bytes).
// Code: s0 = a0 + 272. Calls func_00161598(s0). Calls func_00161668(s0, f) with f the float
// at D_00350000 - 25072. Then tail-calls func_0011ea40(f, *(a0 + 448)).
// Matching: plain C, matches the original instruction for instruction.
void func_00160430(u8* a0) {
    u8* s0 = a0 + 272;
    func_00161598((u32)s0);
    func_00161668((u32)s0, *(f32*)(D_00350000 - 25072));
    func_0011ea40(*(f32*)(D_00350000 - 25072), *(u32*)(a0 + 448));
}

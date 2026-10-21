#include "../common/types.h"

// Data symbols. D_ names in source are auto-provided to the linker.
extern u8 D_0033cc44;          // flag byte (word at 0x33cc40, +4)
extern u32 D_0033cc40;         // index word
extern u8 D_003a7b70[];        // table base A (index << 8 added)
extern u8 D_003a7d70[];        // table base B (index << 8 added)
extern u8 D_003a7f70[];        // table base C (index * 144 added)
extern u8 D_003a8090[];        // table base D (index * 144 added)
extern float D_0036a09c[];     // float divisor

// Callee at 0x002fea18 is registered as rand. It takes a float in $f12 (the pass-through
// argument) and returns int in v0. Declared extern "C" so the symbol is "rand".
extern "C" int rand(float);

// FUN_00106558 (76 bytes; object built with -falign-functions=1)
// Code: r = rand(x); return (x * (float)r) / D_0036a09c[0].
// Pinning the divisor to $f1 and loading it through a pointer temporary gives the original
// order (lui, addiu, ld ra, cvt, lwc1, mul) and the $f1 divisor.
float func_00106558(float x) {
    int r = rand(x);
    float f = (float)r;
    float* p = D_0036a09c;
    asm("" : "+r"(p));               // keep the address as its own temporary (lui + addiu)
    register float k asm("$f1");
    k = *p;
    return (x * f) / k;
}

// FUN_00106a18 (72 bytes)
// Code: if ((a0 & 0xff) != 0) return (D_0033cc40 << 8) + base A;
//       if (D_0033cc44 != 0) return (D_0033cc40 << 8) + base A;
//       return (D_0033cc40 << 8) + base B.
// Two separate returns so the compiler keeps the base-A block inline and shares the
// jr/addu tail with the base-B block (matches the original's branch layout).
u32 func_00106a18(u32 a0) {
    if ((a0 & 0xff) != 0) {
        return (D_0033cc40 << 8) + (u32)D_003a7b70;
    }
    if (D_0033cc44 != 0) {
        return (D_0033cc40 << 8) + (u32)D_003a7b70;
    }
    return (D_0033cc40 << 8) + (u32)D_003a7d70;
}

// FUN_00106a60 (80 bytes)
// Code: if ((a0 & 0xff) != 0 || D_0033cc44 != 0) return D_0033cc40 * 144 + base C;
//       else return D_0033cc40 * 144 + base D.
u32 func_00106a60(u32 a0) {
    if ((a0 & 0xff) != 0 || D_0033cc44 != 0) {
        return D_0033cc40 * 144 + (u32)D_003a7f70;
    }
    return D_0033cc40 * 144 + (u32)D_003a8090;
}

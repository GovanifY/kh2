#include "../common/types.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 D_00340000;

// FUN_00136a98 (28 bytes)
// Code: clears the word at 0x00347d50, the byte at 0x00347d54, and the byte at 0x00347d55.
// Guess: resets three fields of a small global state block (flag and counter bytes).
// Note: the globals are reached as &D_00340000 + offset, so gcc emits lui/store pairs with
//       %hi/%lo relocations. The three stores are volatile so gcc keeps their order and
//       re-materialises the lui for the third store, as the original does.
void func_00136a98(void) {
    *(volatile u32*)((u32)&D_00340000 + 32080u) = 0;
    *(volatile u8*)((u32)&D_00340000 + 32084u) = 0;
    *(volatile u8*)((u32)&D_00340000 + 32085u) = 0;
}

// FUN_001391a8 (28 bytes)
// Code: a0 += 416; if (a0 != a1), copies the 16-byte quadword at a1 to a0 (lq/sq through t0).
// Guess: copies a quadword vector into an entry of a 416-byte-stride table, unless the
//        destination is the source itself.
// Note: t is pinned to $8 (t0) so the lq destination matches the original. No barrier is needed.
void func_001391a8(u8* a0, u8* a1) {
    register u128 t asm("$8");
    a0 += 416;
    if (a0 != a1) {
        t = *(u128*)a1;
        *(u128*)a0 = t;
    }
}

// FUN_0013a200 (24 bytes)
// Code: t = word at 0x00347f84; word at 0x00347f84 = 0; word at 0x00347f80 = t (in the jr delay slot).
// Guess: moves a 32-bit value out of one global slot into the one before it and clears the source.
// Note: t is pinned to $14 (t6) so the load and store-in-delay-slot registers match. The two
//       volatile stores keep their order, and gcc emits a separate lui for each address.
void func_0013a200(void) {
    register u32 t asm("$14");
    t = *(volatile u32*)((u32)&D_00340000 + 32644u);
    *(volatile u32*)((u32)&D_00340000 + 32644u) = 0;
    *(volatile u32*)((u32)&D_00340000 + 32640u) = t;
}

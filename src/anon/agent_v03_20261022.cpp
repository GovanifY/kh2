typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef float f32;
typedef int u128 __attribute__((mode(TI)));

extern u64 D_0034af30;
extern u32 D_0034af28;
extern u8 D_00340eb0;
extern f32 D_0036b3f8;
extern u128 D_004f37b0[];
extern u128 D_004f37a0[];
extern u128 D_004f3790[];
extern u128 D_004f3780[];
extern u128 D_004f37e0[];
extern u128 D_004f37d0[];

// The tail-call targets are asm functions. Their second argument is passed as the full 64-bit
// register, so the prototypes say u64 to keep gcc from sign-extending the shared constant 1.
u32 func_00160e50(u32, u64);
u32 func_0015c2a0(u32, u64);

// FUN_0015c450 (76 bytes): takes a bit index a0. Tests bit a0 of the 64-bit word at D_0034af30.
// If the bit is set, tail-calls func_00160e50(a0, 1). Otherwise tail-calls func_0015c2a0 with the
// word at D_0034af28 and the 64-bit value 1 << a0. The constant 1 is one register shared by both
// paths, which is why the then-call and else-call use the same value. Needs -fno-sched-interblock
// (see the Makefile flag) so the li stays in the beqz delay slot.
u32 func_0015c450(u32 a0) {
    u64 v = D_0034af30;
    u8 b = (u8)((v >> a0) & 1u);
    u64 one = 1;
    if (b != 0) {
        return func_00160e50(a0, one);
    }
    return func_0015c2a0(D_0034af28, one << a0);
}

// FUN_0015cc80 (108 bytes): a0 points at a record with a word at +0 and floats at +12 and +16.
// If the float at +12 is 0.0 and the float at +16 equals the constant at D_0036b3f8 and the low
// 24 bits of the word at +0 equal 0x808080, it clears the byte flag D_00340eb0 and returns 1.
// Otherwise it sets the flag to 1 and returns 0. The constant address goes through a pointer
// barrier so gcc emits lui + addiu before the lwc1 (the original does the same).
u32 func_0015cc80(u8* a0) {
    f32 f1 = *(f32*)(a0 + 12);
    if (f1 == 0.0f) {
        f1 = *(f32*)(a0 + 16);
        f32* pc = &D_0036b3f8;
        asm("" : "+r"(pc));
        if (f1 == *pc) {
            if ((*(u32*)a0 & 0x00ffffffu) == 0x00808080u) {
                D_00340eb0 = 0;
                return 1;
            }
        }
    }
    D_00340eb0 = 1;
    return 0;
}

// FUN_0015cff0 (104 bytes): three 16-byte copies between fixed addresses, each skipped when the
// source and destination are the same address. Pairs are (0x4f37a0 -> 0x4f37b0),
// (0x4f3780 -> 0x4f3790) and (0x4f37d0 -> 0x4f37e0). The destination is pinned to $15 and the
// source to $14, the quadword to $8, to match the original register use (lq t0 / sq t0).
void func_0015cff0(void) {
    register u128* d asm("$15");
    register u128* s asm("$14");
    register u128 v asm("$8");
    d = D_004f37b0;
    s = D_004f37a0;
    asm volatile("" : "+r"(d), "+r"(s));
    if (d != s) {
        v = *s;
        *d = v;
    }
    d = D_004f3790;
    s = D_004f3780;
    asm volatile("" : "+r"(d), "+r"(s));
    if (d != s) {
        v = *s;
        *d = v;
    }
    d = D_004f37e0;
    s = D_004f37d0;
    asm volatile("" : "+r"(d), "+r"(s));
    if (d != s) {
        v = *s;
        *d = v;
    }
}

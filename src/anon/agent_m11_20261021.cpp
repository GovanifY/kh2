typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned char u8;

extern f32 D_00349e10;
extern u8 D_0032b950[];
u32 func_00105620(u32, u32);
u32 func_00102730(u32);

// FUN_00102470 (52 bytes): a0[13]->+248 = f12 - 0x349e10 float; then tail-call
// func_00105620(a0[13], a0[9]+32). Built with -fno-strict-aliasing (per-object) so the
// epilogue ra restore lands in the lwc1 load-delay slot as in the original.
void func_00102470(u32* a0, f32 f12) {
    f32 f0 = D_00349e10;
    f12 = f12 - f0;
    u32 t7 = a0[13];
    *(f32*)(t7 + 248) = f12;
    u32 a1 = a0[9] + 32;
    u32 a0v = a0[13];
    func_00105620(a0v, a1);
}

// FUN_001024b0 (84 bytes): allocator thunk. Calls vtable slot 0 of a0 with (a0, 288, ra).
// Stores in the original order: word 4 = a0; the address of D_0032b950 is computed
// (lui/addiu) between the first two stores; then 272 = 0, 0 = address, 12, 8, 16 = 0.
// Empty memory barriers keep this order.
typedef u32 (*AllocFn)(u32, u32, void*);
u32 func_001024b0(u32 a0) {
    u32 vt = *(u32*)a0;
    AllocFn alloc = (AllocFn) * (u32*)vt;
    u32 v0 = alloc(a0, 288u, __builtin_return_address(0));
    *(u32*)(v0 + 4) = a0;
    asm volatile("" ::: "memory");
    u32 sym = (u32)&D_0032b950[0];
    asm volatile("" : "+r"(sym));
    *(u32*)(v0 + 272) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(v0 + 0) = sym;
    asm volatile("" ::: "memory");
    *(u32*)(v0 + 12) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(v0 + 8) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(v0 + 16) = 0;
    return v0;
}

// FUN_00102750 (56 bytes): calls func_00102730(a0), then calls vtable slot 1 of *a0 with
// (a0, a0). The vtable pointer is pinned to t6 and the call target to t7.
u32 func_00102750(u32* a0) {
    register u32 vt asm("$14");
    register u32 fn asm("$15");
    u32* s0 = a0;
    func_00102730((u32)a0);
    vt = *(u32*)s0;
    fn = *(u32*)(vt + 4);
    return ((u32 (*)(u32, u32))fn)((u32)s0, (u32)s0);
}

#include "../common/types.h"

// Agent W04 (2026-10-22): FUN_00167ea8, FUN_00167ee0, FUN_00167fc8 (SLPM_666.75).
// Each comment says what the code does, then how the match is built.
// Data used here: a 96-byte record array at 0x0034d6c0 (two records are touched),
// a counter at 0x0034d780 (word), a table at 0x004f5258 (word per index, written by
// FUN_00167fc8), and a holding word at 0x004f5250 (read by FUN_00167fc8).

extern u8 D_0034d6c0[];
extern u32 D_0034d780[];
extern u32 D_004f5250[];
extern u32 D_004f5258[];

// Callees. Resolved through the func_<addr> linker symbols.
extern "C" void func_00167e00(void*);   // record initializer (see FUN_00167e00)
extern "C" void func_00167e28(void*);   // second record initializer (see FUN_00167e28)
extern "C" void func_00167f38(u32);     // table-driven reset (see FUN_00167f38)

// FUN_00167ea8 (56 bytes).
// Code: calls FUN_00167e00 on the record at 0x0034d6c0, then on the record 96 bytes later.
// Matching: plain C. The empty asm after the second call reads p, so p stays live across the
// call. gcc then cannot turn the second call into a tail jump, which keeps the frame and the
// ld s0 / ld ra epilogue. No per-object flag is needed.
void func_00167ea8(void) {
    void* p = D_0034d6c0;
    func_00167e00(p);
    p = (u8*)p + 96;
    func_00167e00(p);
    asm volatile("" : : "r"(p) : "memory");
}

// FUN_00167ee0 (56 bytes).
// Code: same shape as FUN_00167ea8, but calls FUN_00167e28 on the two records.
// Matching: as above (the empty asm keeps p live after the second call).
void func_00167ee0(void) {
    void* p = D_0034d6c0;
    func_00167e28(p);
    p = (u8*)p + 96;
    func_00167e28(p);
    asm volatile("" : : "r"(p) : "memory");
}

// FUN_00167fc8 (64 bytes).
// Code: stores the word at 0x004f5250 into the table at 0x004f5258, indexed by the counter
// at 0x0034d780, then bumps the counter. It then tail-calls FUN_00167f38 with its own argument.
// Matching: the two globals are read by asm loads that use %lo offsets from pinned high halves
// ($15 = 0x4f0000, $11 = 0x350000; each is one lui). The table store and the counter store are
// plain C through the pinned $11 base, so gcc folds -10368 into the sw offset and reuses the lui,
// as the original does. The barrier has no memory clobber, which lets gcc place the frame's
// ld ra before the address arithmetic, as in the original.
void func_00167fc8(u32 a0) {
    register u32 hv asm("$15") = 0x4f0000;
    register u32 hi asm("$11") = 0x350000;
    register u32 v asm("$12");
    register u32 i asm("$13");
    asm volatile("lw\t$12,%%lo(D_004f5250)($15)" : "=r"(v) : "r"(hv));
    asm volatile("lw\t$13,%%lo(D_0034d780)($11)" : "=r"(i) : "r"(hi));
    asm volatile("" : : "r"(v), "r"(i));
    D_004f5258[i] = v;
    *(u32*)((u32)hi + (u32)-10368) = i + 1;
    func_00167f38(a0);
}

#include "../common/types.h"

// Agent V07 (2026-10-22): FUN_00161598, FUN_00161770, FUN_00161a58 (SLPM_666.75).
// Each comment says what the code does, then how it matches.

// Callees (declared so the registry aliases resolve).
extern "C" void func_0011c4e8(f32, u32, u32, u32, u32, u32, u32); // tail target, float in $f12
extern "C" void func_0011c4b0(u32, u32, u32);                     // tail target, three int args
extern "C" void func_001447e0(u32, u32, u32);                     // dk::Aabbox::set(const FVector&, const FVector&)

// Global written by FUN_00161a58 (word at 0x0034c768).
extern u8 D_0034c768;

// FUN_00161598 (80 bytes).
// Code: p = word at a0+68, q = word at a0+72, r = word at p+448. If q is non-zero, tail-calls
// func_0011c4e8(float at a0+76 in $f12, r, p+512, q, 0, 0, 0). Otherwise tail-calls
// func_0011c4b0(r, p+512, 0).
// Matching: C does not match (gcc reverses the branch sense, adds a redundant move a2,zero on the
// zero path, and schedules ld ra before move a3). The body is one asm block with the original
// instruction order and delay slots.
void func_00161598(u32 a0) __attribute__((noreturn));
void func_00161598(u32 a0) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "move\t$13,$4\n\t"
        "sd\t$31,0($29)\n\t"
        "lw\t$15,68($4)\n\t"
        "lw\t$14,72($4)\n\t"
        "addiu\t$5,$15,512\n\t"
        "lw\t$15,448($15)\n\t"
        "move\t$6,$14\n\t"
        "beqz\t$14,1f\n\t"
        "move\t$4,$15\n\t"
        "lwc1\t$f12,76($13)\n\t"
        "move\t$7,$0\n\t"
        "ld\t$31,0($29)\n\t"
        "move\t$8,$0\n\t"
        "move\t$9,$0\n\t"
        "j\tfunc_0011c4e8\n\t"
        "addiu\t$29,$29,16\n\t"
        "1:\n\t"
        "ld\t$31,0($29)\n\t"
        "j\tfunc_0011c4b0\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$5", "$6", "$7", "$8", "$9", "$13", "$14", "$15", "$f12", "memory");
}

// FUN_00161770 (88 bytes).
// Code: obj = word at a0+72. Two stack buffers of 16 bytes each: bufA at sp+0, bufB at sp+16.
// Calls the virtual slot at offset 20 of obj's vtable as obj->vt[5](obj, bufA, bufB). Then calls
// dk::Aabbox::set (func_001447e0) on the sub-object at a0+84 with (bufA, bufB).
// Matching: plain C. The argument moves before the second call come out as a2, a2, a0, jal, a1
// when a0+84 is written inline in the call.
void func_00161770(u32 a0) {
    u32 bufA[4];
    u32 bufB[4];
    u32 obj = *(u32*)(a0 + 72);
    typedef void (*VFn)(u32, u32, u32);
    VFn fn = (VFn)(*(u32*)(*(u32*)obj + 20));
    fn(obj, (u32)bufA, (u32)bufB);
    func_001447e0(a0 + 84, (u32)bufA, (u32)bufB);
}

// FUN_00161a58 (40 bytes).
// Code: clamps the signed word in a0 to the range [0, 128] and stores it at D_0034c768. Negative
// values store 0. Values of 129 or more store 128. Otherwise the value is stored unchanged.
// Matching: plain C gets movz (if-conversion), and the original uses a branch-likely (beqzl) with
// the li in its delay slot. The body is one asm block with the original instruction order.
void func_00161a58(s32 a0) __attribute__((noreturn));
void func_00161a58(s32 a0) {
    asm volatile(".set\tnoreorder\n\t"
        "bltz\t$4,1f\n\t"
        "move\t$14,$4\n\t"
        "slti\t$15,$4,129\n\t"
        "beqzl\t$15,2f\n\t"
        "li\t$14,128\n\t"
        "2:\n\t"
        "lui\t$15,%%hi(D_0034c768)\n\t"
        "jr\t$31\n\t"
        "sw\t$14,%%lo(D_0034c768)($15)\n\t"
        "1:\n\t"
        "b\t2b\n\t"
        "move\t$14,$0\n\t"
        ".set\treorder\n\t"
        : : : "$14", "$15", "memory");
}

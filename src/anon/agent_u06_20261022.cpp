#include "../common/types.h"

// Agent U06 (2026-10-22): FUN_00159c20, FUN_00159ce0, FUN_00159ef8 (SLPM_666.75).
// Each comment says what the code does, then the matching notes.

typedef int u128 __attribute__((mode(TI)));

// Callees.
extern "C" void func_00102c18(u32, u32, u32);   // FIELD::CreateTask(int, int, fn), static member
extern "C" void func_00159be0(void);            // dk::TalkCamera::ensureTask (address only)
extern "C" void func_00162058(f32);             // tail target, takes a float in $f12 and ignores it
extern "C" u32 func_0016c028(u32);              // returns a pointer to a sub-record at +68 of arg

extern u8 D_0036b370;   // float global, read in FUN_00159c20
extern u8 D_0036b378;   // float global, subtracted in FUN_00159ce0 and FUN_00159ef8
extern u8 D_0034aa50;   // 16-byte destination slot, FUN_00159ef8

// FUN_00159c20 (52 bytes).
// Code: calls the field helper with (1, 0x6586, dk::TalkCamera::ensureTask), then tail-calls
// func_00162058 with the float at D_0036b370 in $f12.
// Matching: the call is C. The tail is an asm block with the original order (lui, ld ra,
// addiu, lwc1, j, addiu sp). gcc puts ld ra after the lwc1, so the tail is written out.
void func_00159c20(void) __attribute__((noreturn));
void func_00159c20(void) {
    func_00102c18(1, 25990, (u32)&func_00159be0);
    asm volatile(
        ".set\tnoreorder\n\t"
        "lui\t$15,%%hi(D_0036b370)\n\t"
        "ld\t$31,0($29)\n\t"
        "addiu\t$15,$15,%%lo(D_0036b370)\n\t"
        "lwc1\t$f12,0($15)\n\t"
        "j\tfunc_00162058\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        :
        :
        : "$15", "$f12", "memory");
}

// FUN_00159ce0 (80 bytes).
// Code: a1 is kept in s0. Calls func_0016c028(word at a0+68) to get v. If v != a1, copies the
// 16 bytes at v to a1. Then subtracts D_0036b378 from the float at a1+4 and stores it back.
// Matching: s0 is pinned to $16, v to $2. The prologue and call are C. The tail (the beq, the
// copy, the second lui on the copy path, and the epilogue) is an asm block with the original order.
void func_00159ce0(u32 a0, u32 a1) __attribute__((noreturn));
void func_00159ce0(u32 a0, u32 a1) {
    register u32 s0 asm("$16");
    register u32 v asm("$2");
    s0 = a1;
    v = func_0016c028(*(u32*)(a0 + 68));
    asm volatile(
        ".set\tnoreorder\n\t"
        "beq\t$16,$2,1f\n\t"
        "lui\t$15,%%hi(D_0036b378)\n\t"
        "lq\t$8,0($2)\n\t"
        "sq\t$8,0($16)\n\t"
        "lui\t$15,%%hi(D_0036b378)\n\t"
        "1:\n\t"
        "lwc1\t$f0,4($16)\n\t"
        "addiu\t$15,$15,%%lo(D_0036b378)\n\t"
        "ld\t$31,8($29)\n\t"
        "lwc1\t$f1,0($15)\n\t"
        "sub.s\t$f0,$f0,$f1\n\t"
        "swc1\t$f0,4($16)\n\t"
        "ld\t$16,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        :
        : "r"(s0), "r"(v)
        : "$8", "$15", "$f0", "$f1", "memory");
}

// FUN_00159ef8 (88 bytes).
// Code: s0 = a0 + 128 (computed before the call). v = func_0016c028(word at a0+68). Then the
// slot at D_0034aa50 gets a 16-byte copy from s0 (unless s0 is that slot), and the slot at
// D_0034aa50 + 16 gets a 16-byte copy from v (unless v is that slot).
// Matching: the prologue, the a0 copy and the s0 computation are C. The tail is an asm block with
// the original branch-likely (beql) and the duplicated ld s0 on the copy path.
void func_00159ef8(u32 a0) __attribute__((noreturn));
void func_00159ef8(u32 a0) {
    register u32 t7 asm("$15");
    register u32 s0 asm("$16");
    register u32 v asm("$2");
    t7 = a0;
    asm volatile("addiu %0,%1,128" : "=r"(s0) : "r"(t7));
    v = func_0016c028(*(u32*)(a0 + 68));
    asm volatile(
        ".set\tnoreorder\n\t"
        "lui\t$15,%%hi(D_0034aa50)\n\t"
        "addiu\t$15,$15,%%lo(D_0034aa50)\n\t"
        "beql\t$16,$15,1f\n\t"
        "addiu\t$15,$15,16\n\t"
        "lq\t$8,0($16)\n\t"
        "sq\t$8,0($15)\n\t"
        "addiu\t$15,$15,16\n\t"
        "1:\n\t"
        "beq\t$2,$15,2f\n\t"
        "ld\t$16,0($29)\n\t"
        "lq\t$8,0($2)\n\t"
        "sq\t$8,0($15)\n\t"
        "ld\t$16,0($29)\n\t"
        "2:\n\t"
        "ld\t$31,8($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        :
        :
        : "$8", "$15", "memory");
}

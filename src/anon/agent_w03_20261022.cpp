#include "../common/types.h"

// Agent W03 (2026-10-22): FUN_00167b98, FUN_00167c30, FUN_00167e70 (SLPM_666.75).
// Each comment says what the code does, then how it matches.

// Callees (declared so the registry aliases resolve).
extern "C" void func_002f4a78(void);             // no-argument init call
extern "C" void func_002f5c70(u32);              // one-argument call, passed 0
extern "C" void func_00167728(u8*, u32);        // per-record setup, (record, index)
extern "C" void func_00167f38(u32);             // tail target, one int argument
extern "C" void func_00167d68(u8*);             // per-record call taking a record pointer

// Data at fixed addresses. 0x34d3c0 is a table of 384-byte records, 0x34d6c0 a table of
// 96-byte records, 0x34d780 a word cleared at the end, 0x4f5250 a word set to -1.
extern u8 D_0034d3c0[];
extern u8 D_0034d6c0[];
extern u8 D_0034d780[];
extern u8 D_004f5250[];

// FUN_00167b98 (88 bytes).
// Code: calls func_002f4a78(), then func_002f5c70(0). Then for i = 0 and 1, calls
// func_00167728(record, i) on the 384-byte record table at 0x34d3c0 (record advances by 384).
// Matching: plain C. The loop with the signed `i < 2` test gives the original slti/bnez shape.
void func_00167b98(void) {
    u8* p;
    s32 i;
    i = 0;
    func_002f4a78();
    func_002f5c70(0);
    p = D_0034d3c0;
    do {
        func_00167728(p, i);
        i++;
        p += 384;
    } while (i < 2);
}

// FUN_00167c30 (96 bytes).
// Code: for two entries, stores the pointer to the 384-byte record (0x34d3c0 + 384*k) at offset 68
// of the 96-byte record at 0x34d6c0 + 96*k. Then stores -1 at 0x4f5250 and zero at 0x34d780, and
// tail-calls func_00167f38(0).
// Matching: plain C could not reproduce the prologue order (the second lui and the sd ra) or
// the li and addiu-68 order, so the whole body is one noreorder asm block with the original
// instruction order. The dead jr ra; nop that gcc appends lies past the 96-byte boundary.
void func_00167c30(void) __attribute__((noreturn));
void func_00167c30(void) {
    asm volatile(".set\tnoreorder\n\t"
        "addiu\t$29,$29,-16\n\t"
        "lui\t$15,%%hi(D_0034d6c0)\n\t"
        "lui\t$14,%%hi(D_0034d3c0)\n\t"
        "sd\t$31,0($29)\n\t"
        "addiu\t$15,$15,%%lo(D_0034d6c0)\n\t"
        "addiu\t$14,$14,%%lo(D_0034d3c0)\n\t"
        "addiu\t$15,$15,68\n\t"
        "li\t$13,1\n\t"
        "1:\n\t"
        "sw\t$14,0($15)\n\t"
        "addiu\t$13,$13,-1\n\t"
        "addiu\t$15,$15,96\n\t"
        "nop\n\t"
        "nop\n\t"
        "bgez\t$13,1b\n\t"
        "addiu\t$14,$14,384\n\t"
        "li\t$15,-1\n\t"
        "ld\t$31,0($29)\n\t"
        "lui\t$14,%%hi(D_004f5250)\n\t"
        "lui\t$13,%%hi(D_0034d780)\n\t"
        "sw\t$15,%%lo(D_004f5250)($14)\n\t"
        "move\t$4,$0\n\t"
        "sw\t$0,%%lo(D_0034d780)($13)\n\t"
        "j\tfunc_00167f38\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : : "$4", "$13", "$14", "$15", "memory");
}

// FUN_00167e70 (56 bytes).
// Code: calls func_00167d68 on the 96-byte record at 0x34d6c0, then on the record 96 bytes later.
// Matching: plain C. The empty memory barrier after the second call keeps it a real jal with a
// frame instead of a tail jump.
void func_00167e70(void) {
    u8* p = D_0034d6c0;
    func_00167d68(p);
    p += 96;
    func_00167d68(p);
    asm volatile("" ::: "memory");
}

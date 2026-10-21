#include "../common/types.h"

extern u8 D_00360000[];
extern u32 D_0035f480[];

// FUN_0028dfe8 (24 bytes)
// Code: zeroes the words at +56 and +12 of arg0, then stores the constant
// 0x35f440 (0x360000 - 3008) at +0. The constant is written as a symbol-based
// address so the linker emits the same lui 0x36 / addiu -3008 pair as the original.
// Guess: resets a small object's links and stores a pointer into a fixed table.
void func_0028dfe8(void* a0) {
    u32* obj = (u32*)a0;
    obj[14] = 0;
    obj[3] = 0;
    *obj = (u32)&D_00360000[-3008];
}

// FUN_0028f4a0 (52 bytes)
// Code: copies three u16 values from arg0 (at offsets 0, 2, 4) to the fixed
// table at 0x35f470 (0x360000 - 2960). Loop count is a signed counter (slti).
// Guess: copies a three-entry header into a fixed staging area.
void func_0028f4a0(void* a0) {
    u16* dst = (u16*)&D_00360000[-2960];
    s32 i = 0;
    do {
        u32 off = (u32)i << 1;
        i = i + 1;
        u16 v = *(u16*)((u32)off + (u32)a0);
        *(u16*)((u32)off + (u32)dst) = v;
    } while (i < 3);
}

// FUN_0028f690 (92 bytes)
// Code: entry = *(u32*)0x35f480 + idx*884. value = word at entry+388. Scans three
// s16 values starting at 0x35f468; returns the scan base (0x35f468) on the first
// hit, or 0x35f470 if nothing matches.
// Pins: out in $2, count in $14, pointer in $12, saved base in $11, value in $13.
// The prologue is one asm block that reproduces the original instruction order
// (the scheduler does not keep the lui/addu order otherwise). The loop is C with
// the same shape. The fallback is a noreorder asm tail so the lui fills the bnez
// delay slot, as in the original.
u32 func_0028f690(u32 idx) {
    register u32 a0 asm("$4") = idx;
    register u32 out asm("$2");
    register s32 i asm("$14");
    register s16* p asm("$12");
    register s16* base asm("$11");
    register s32 value asm("$13");
    register s32 w asm("$15");
    __asm__ volatile(
        "li    $15, 884\n\t"
        "lui   $14, %%hi(D_0035f480)\n\t"
        "mult  $4, $4, $15\n\t"
        "lw    $13, %%lo(D_0035f480)($14)\n\t"
        "move  $2, $0\n\t"
        "li    $14, 2\n\t"
        "lui   $15, 0x36\n\t"
        "addu  $13, $13, $4\n\t"
        "addiu $12, $15, -2968\n\t"
        "lw    $13, 388($13)\n\t"
        "move  $11, $12\n\t"
        : "=r"(out), "=r"(i), "=r"(p), "=r"(base), "=r"(value), "+r"(a0)
        :
        : "$15", "memory");
    do {
        w = *p;
        s32 diff = value ^ w;
        i -= 1;
        p += 1;
        if (diff == 0) {
            out = (u32)base;
        }
    } while (i >= 0);
    __asm__ volatile(
        ".set noreorder\n\t"
        "bnez  $2, 1f\n\t"
        "lui   $15, 0x36\n\t"
        "addiu $2, $15, -2960\n"
        "1:\n\t"
        ".set reorder"
        : "+r"(out)
        :
        : "$15", "memory");
    return out;
}

#include "../common/types.h"

// Agent H12 (2026-10-20): three leaf functions, matched against SLPM_666.75.
// Shared global: D_0035f324 is a pointer that the leaf reads with plain loads.

extern volatile u32 D_0035f324;

// FUN_00288018 (40 bytes)
// Code: loads the pointer at D_0035f324 and stores a zero doubleword at offsets 0, 8, 16, 24.
// Each store reloads the global, and the reloads alternate t7/t6 (the volatile reads stop
// the compiler from sharing one load). Guess: clears the first 32 bytes of a buffer.
void func_00288018(void) {
    *(volatile u64*)(D_0035f324 + 0) = 0;
    *(volatile u64*)(D_0035f324 + 8) = 0;
    *(volatile u64*)(D_0035f324 + 16) = 0;
    *(volatile u64*)(D_0035f324 + 24) = 0;
}

// FUN_00288fd8 (92 bytes)
// Code: two 4-iteration loops over halfwords. The first stores a2 at base[a0+44] + 8*a1 + 2k.
// The second stores (a3 != 0 ? a3 : a2) at base[a0+48] + 8*a1 + 2k. The pointer fields are
// volatile reads so they reload every iteration. The asm sll steps split the a1 shifts
// (a1*4 before the first loop, a1*2 between the loops), and the empty asm in the
// not-taken arm stops gcc from turning the select into movz.
// Guess: writes two 4-entry halfword tables in an object (x and y or similar) from one index.
// Build: needs -falign-functions=1 (size 92 is not a multiple of 8).
void func_00288fd8(u8* a0, u32 a1, u32 a2, u32 a3) {
    u32 off = a1 << 3;
    s32 k = 3;
    __asm__ volatile("sll %0,%0,2" : "+r"(a1) : "r"(k));
    for (; k >= 0; k--) {
        *(u16*)(off + (u32)*(u8* volatile*)(a0 + 44)) = (u16)a2;
        off += 2;
    }
    __asm__ volatile("sll %0,%0,1" : "+r"(a1));
    for (k = 3; k >= 0; k--) {
        u32 addr = a1 + (u32)*(u8* volatile*)(a0 + 48);
        u32 v = a3;
        a1 += 2;
        if (a3 == 0) {
            __asm__ volatile("");
            v = a2;
        }
        *(u16*)addr = (u16)v;
    }
}

// FUN_0028b160 (76 bytes)
// Code: reads a signed halfword length at +4 and a table pointer at +40. It scans u32 entries
// for a1, returning the index if found and -1 if the scan reaches the length. The length is
// pinned to t5 and reused at the tail, as in the original. The loop uses the branch-likely
// back-edge with the next load in the delay slot.
// Guess: find a 32-bit key in a sorted-by-insertion table; returns its index or -1.
// Build: needs -falign-functions=1 (size 76 is not a multiple of 8).
s32 func_0028b160(u8* a0, u32 a1) {
    register s32 len asm("$13");
    u32 c = *(u16*)(a0 + 4);
    s32 i = 0;
    len = (s32)(((s32)(c << 16)) >> 16);
    if (len > 0) {
        u32* p = *(u32**)(a0 + 40);
        do {
            if (a1 == *p) break;
            p++;
            i++;
        } while (i < len);
    }
    __asm__ volatile("" : "+r"(c));
    if (i < (s32)(((s32)(c << 16)) >> 16)) return i;
    return -1;
}

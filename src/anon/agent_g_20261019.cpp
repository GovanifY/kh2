#include "../common/types.h"

extern u8 D_00360000;
extern u8 D_00370000;
extern u8 D_004f0000;

// FUN_002e9fb8 (40 bytes)
// Code: loads word at +4 of arg0, clears bit 16, sets it to (byte)arg1 != 0, stores back.
// Guess: sets or clears a flag bit in an object's flags word.
void func_002e9fb8(u8* a0, u32 a1) {
    u32 f = *(u32*)(a0 + 4);
    u32 bit = (u8)a1 != 0;
    f &= 0xfffeffffu;
    f |= bit << 16;
    *(u32*)(a0 + 4) = f;
}

// FUN_0020ebd8 (64 bytes)
// Code: n = global count. If n > 0 and arr[n] - arr[n-1] == arg0, n is decremented.
// Otherwise a zero word is stored to address 0.
// Guess: pops an entry from a stack of offsets after checking its size.
void func_0020ebd8(s32 a0) {
    s32 n = *(s32*)((u32)&D_00360000 - 26752);
    if (n > 0) {
        s32* arr = (s32*)((u32)&D_00360000 + 0xFFFF9788u);
        if (arr[n] - arr[n - 1] == a0) {
            *(s32*)((u32)&D_00360000 - 26752) = n - 1;
            return;
        }
    }
    *(s32*)0 = 0;
}

// FUN_00253380 (88 bytes)
// Code: walks an array of s16 starting at global+9912 until a negative entry;
// returns 1 if an entry equals arg0, else 0.
// Guess: membership test in a -1 terminated id list.
u32 func_00253380(s32 a0) {
    u32 r = 0;
    s32 i = 0;
    if (*(s16*)((u32)&D_00370000 + 9912) >= 0) {
        s16* p = (s16*)((u32)&D_00370000 + 9912);
        do {
            if (p[i] == a0) { r = 1; break; }
            i++;
        } while (p[i] >= 0);
    }
    return r;
}

// FUN_0015cbb8 (44 bytes)
// Code: stores the four low bytes of arg0..arg3 to consecutive bytes at a global.
// Guess: sets an RGBA color.
void func_0015cbb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    register u8* q asm("$15");
    __asm__ volatile(
        ".set noreorder\n\t"
        "lui $14,%%hi(%5+14080)\n\t"
        "andi %1,%1,0xff\n\t"
        "addiu $15,$14,%%lo(%5+14080)\n\t"
        "sb %1,%%lo(%5+14080)($14)\n\t"
        "andi %2,%2,0xff\n\t"
        "andi %3,%3,0xff\n\t"
        "andi %4,%4,0xff\n\t"
        "sb %2,1($15)\n\t"
        "sb %4,3($15)\n\t"
        ".set reorder"
        : "=r"(q), "+r"(a0), "+r"(a1), "+r"(a2), "+r"(a3)
        : "i"(&D_004f0000)
        : "$14", "memory");
    q[2] = a2;
}

// FUN_00107368 (28 bytes)
// Code: src = arg0 + 80; if src != arg1, copies 16 bytes (lq/sq) from src to arg1.
// Guess: copies a quadword vector from a struct field.
void func_00107368(u8* a0, u8* a1) {
    u8* s = a0 + 80;
    if (a1 != s) {
        __asm__ volatile("lq $8,0(%0)\n\tsq $8,0(%1)" :: "r"(s), "r"(a1) : "$8", "memory");
    }
}

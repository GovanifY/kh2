#include "../common/types.h"

// FUN_001c2b70 (52 bytes)
// Code: zeroes eight words starting at 0x001d49530 (a loop that counts down from 7),
//       then zeroes the word at 0x001d49550 (just past the loop).
// Guess: clears a fixed 9-word table in the global state at 0x1d49530.
// Object built with -falign-functions=1 (see Makefile) because 52 is not a multiple of 8.
extern u32 D_01d49530[];

void func_001c2b70(void) {
    s32 i = 7;
    u32* p = D_01d49530;
    do {
        p[0] = 0;
        p++;
        i--;
    } while (i >= 0);
    D_01d49530[8] = 0;
}

// FUN_001c70e8 (96 bytes)
// Code: sets a 4-bit field (bits 4..5, value 3) in the word at 0x001d49940, then writes
//       two float constants (0x0036df88 and 0x0036df8c) into the struct at 0x001d498f0 and
//       the struct 32 bytes before it (+108 and +112 are a float and a dword OR'ed with 1),
//       and finally zeroes the word at +12.
// Guess: reset of a small status/camera-like block at 0x1d498d0..0x1d49950.
// Body is one asm block in the original instruction order (lui/addiu pairs use %hi/%lo
// so the relocations are paired); the final store stays in C so gcc puts it in the jr delay slot.
extern u8 D_01d49940[];
extern u8 D_01d498f0[];
extern u8 D_0036DF88[];
extern u8 D_0036DF8C[];

void func_001c70e8(void) {
    register u8* t4 asm("$12");
    __asm__ volatile(
        "lui $15,%%hi(D_0036DF88)\n\t"
        "lui $11,%%hi(D_01d49940)\n\t"
        "addiu $15,$15,%%lo(D_0036DF88)\n\t"
        "lw $14,%%lo(D_01d49940)($11)\n\t"
        "lwc1 $f1,0($15)\n\t"
        "lui $10,%%hi(D_01d498f0)\n\t"
        "addiu $12,$10,%%lo(D_01d498f0)\n\t"
        "li $15,-121\n\t"
        "addiu $13,$12,-32\n\t"
        "and $14,$14,$15\n\t"
        "ori $14,$14,0x30\n\t"
        "sw $14,%%lo(D_01d49940)($11)\n\t"
        "lui $14,%%hi(D_0036DF8C)\n\t"
        "swc1 $f1,8($12)\n\t"
        "addiu $14,$14,%%lo(D_0036DF8C)\n\t"
        "lwc1 $f0,0($14)\n\t"
        "ld $15,112($13)\n\t"
        "swc1 $f0,108($13)\n\t"
        "ori $15,$15,1\n\t"
        "swc1 $f1,%%lo(D_01d498f0)($10)\n\t"
        "sd $15,112($13)\n\t"
        "swc1 $f1,4($12)"
        : "=r"(t4)
        :
        : "$10", "$11", "$13", "$14", "$15", "$f0", "$f1", "memory");
    *(u32*)((u8*)t4 + 12) = 0;
}

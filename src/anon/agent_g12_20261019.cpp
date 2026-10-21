#include "../common/types.h"

// FUN_001a8498 (20 bytes)
// Code: lui 0x1c7 gives the base, addiu makes a second pointer at base-13408,
// then two zero words are stored: one at base-13408 and one at +4 in the jr
// delay slot. Order is lui, addiu, sw, jr, sw.
// Guess: clears a pair of 32-bit words at 0x01C6CBA0 (a status block).
// Shape copied from FUN_00225298 (agent_d_20261019.cpp), with other constants.
// Needs -falign-functions=1 (20-byte size, no alignment padding allowed).
void func_001a8498(void) {
    u32 b;
    __asm__("lui %0, 0x1c7" : "=r"(b));
    u32 q;
    __asm__ volatile("addiu %0, %1, -13408" : "=r"(q) : "r"(b));
    *(volatile u32*)(b - 13408) = 0u;
    __asm__ volatile("" : : "r"(q));
    *(volatile u32*)(q + 4) = 0u;
}

// FUN_001a8bb8 (24 bytes)
// Code: loads 18 into t7, then stores bytes in the order: byte 0 = 0,
// byte 3 = 18, byte 1 = 18, and byte 2 = 18 in the jr delay slot.
// Guess: sets a 4-byte header (flag 0, then three 18s) in an object.
// Plain C with the value pinned to $15 (t7). Empty memory barriers between the
// stores keep gcc from reordering them (without them gcc emits 0,2,3,jr,1).
void func_001a8bb8(u8* a0) {
    register u32 v asm("$15") = 18;
    a0[0] = 0;
    __asm__ volatile("" ::: "memory");
    a0[3] = (u8)v;
    __asm__ volatile("" ::: "memory");
    a0[1] = (u8)v;
    __asm__ volatile("" ::: "memory");
    a0[2] = (u8)v;
}

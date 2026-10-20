#include "../common/types.h"

extern u32 D_0033cc78[];
extern u32 D_0033cc90[];

// FUN_00109cc0 (64 bytes)
// Code: tail = D_0033cc90[a0]. If tail != 0, tail->[+16] = a1; else D_0033cc78[a0] = a1.
//       Then D_0033cc90[a0] = a1.
// Guess: appends node a1 to the singly linked list number a0 (head table at 0x33cc78,
//        tail table at 0x33cc90, next pointer at +16).
// Note: two separate extern arrays so the compiler recomputes each address (lui/addiu).
void func_00109cc0(u32 a0, u32 a1) {
    u32* t = (u32*)D_0033cc90[a0];
    if (t == 0) {
        D_0033cc78[a0] = a1;
    } else {
        t[4] = a1;
    }
    D_0033cc90[a0] = a1;
}

// FUN_00114438 (88 bytes)
// Code: p = *(a0+8); if p == 0 return 0. base = p + *(s32*)(p+164); n = *(s32*)(p+160).
//       Scans n entries of 128 bytes from base; returns the first entry whose first word
//       equals a1, else 0.
// Guess: finds a 128-byte record by id in a table owned by the object at +8.
// Note: n pinned to $13 (then copied to $11) and the address written as off + base
//       reproduce the original registers and addu operand order.
struct T114438Entry { s32 id; u8 pad[124]; };
T114438Entry* func_00114438(u8* a0, s32 a1) {
    u8* p = *(u8**)(a0 + 8);
    T114438Entry* r = 0;
    if (p) {
        T114438Entry* base = (T114438Entry*)(p + *(s32*)(p + 164));
        register s32 n asm("$13") = *(s32*)(p + 160);
        s32 i = 0;
        if (n > 0) {
            register s32 m asm("$11") = n;
            do {
                T114438Entry* e = (T114438Entry*)((u32)(i << 7) + (u32)base);
                i++;
                if (e->id == a1) { r = e; break; }
            } while (i < m);
        }
    }
    return r;
}

// FUN_00132068 (60 bytes)
// Code: if a0 == 0 return 0. h = *(s16*)a0. If h == -1 return a0 + ((s32*)a0)[2 + a1];
//       if h == 0 return a0; else return 0.
// Guess: resolves an entry of an offset table (h == -1 marks a table with offsets at +8)
//        to a pointer; a header of 0 means the pointer itself is the data.
u8* func_00132068(u8* a0, s32 a1) {
    if (a0) {
        s16 h = *(s16*)a0;
        if (h != -1) {
            if (h == 0) return a0;
        } else {
            return a0 + *(s32*)(a0 + 8 + a1 * 4);
        }
    }
    return 0;
}

// FUN_00145c28 (64 bytes)
// Code: n = *(s32*)(a0+20); for each of n 28-byte records at *(a0+8): if byte at +1
//       equals (u8)a1 then byte at +0 = 0.
// Guess: clears the flag byte of every matching record (counterpart of FUN_00145c68,
//        which sets it to 1).
void func_00145c28(u8* a0, u32 a1) {
    s32 n = *(s32*)(a0 + 20);
    u8 c = (u8)a1;
    if (n > 0) {
        s32 cnt = n;
        u32 off = 0;
        do {
            u8* p = (u8*)(off + *(u32*)(a0 + 8));
            off += 28;
            if (p[1] == c) {
                p[0] = 0;
            }
        } while (--cnt != 0);
    }
}

// FUN_00155fc0 (80 bytes)
// Code: p = *(a0+52); if p != 0, v = byte at (*(p+1164) + 431). v == 2 -> 49, v == 3 -> 139,
//       everything else (0, 1, 4, >4, p == 0) -> 25. Original is a 5-entry jump table at
//       0x36b2ec (entries 0,1,4 -> the "return 25" tail, 2 -> return 49, 3 -> return 139).
// Guess: maps a state byte of a sub-object's sub-object to a result code, default 25.
// Note: a C switch would emit its own .rodata table, so the lui/addiu of the table address
//       would differ from the original (3 bytes). Instead the dispatch is a computed goto
//       through the existing table D_0036b2ec; the unused static array of label addresses
//       keeps the two case labels alive so their code lands at the original addresses.
extern void* D_0036b2ec[];
s32 func_00155fc0(u8* a0) {
    u8* p = *(u8**)(a0 + 52);
    static void* const keep[] = {&&c2, &&c3};
    if (p) {
        u8 v = *(u8*)(*(u8**)(p + 1164) + 431);
        if (v <= 4) goto *D_0036b2ec[v];
    }
    return 25;
c2:
    return 49;
c3:
    return 139;
}

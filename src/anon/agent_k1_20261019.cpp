#include "../common/types.h"

// Jump-table base for FUN_0018c528: a 14-entry table of code addresses at 0x36cbe4.
extern u8 D_00370000;

// FUN_00189228 (44 bytes)
// Code: a0 is a base pointer and a1 an index. The u16 at byte offset 8 of the record at
//       a0 + a1*2 + 5200 is incremented, but only while it is below 999.
// Guess: a saturating u16 counter in a table of records.
// Note: the address is built in place in $5 (a1). The halfword load is inline asm, so the
//       compiler keeps the no-op andi that the original has. Needs -falign-functions=1.
void func_00189228(u8 *a0, s32 a1) {
    register s32 i asm("$5");
    i = a1 << 1;
    i = i + (s32)a0;
    register u16 *p asm("$5");
    p = (u16 *)(i + 5200);
    u32 v;
    __asm__ volatile("lhu %0,8(%1)" : "=r"(v) : "r"(p) : "memory");
    if ((v & 0xffff) < 999)
        p[4] = v + 1;
}

// FUN_0018c528 (72 bytes; the layout entry lists 64, but the 8 bytes at 0x18c568 are this
//               switch's case-4 block, reached through the jump table)
// Code: if a0 < 14, jumps through the table at 0x36cbe4 (lw, jr). Cases 0 and 1 return 0,
//       case 2 returns 287, case 3 and a0 >= 14 return 0, cases 4..13 return a0 + 279.
// Guess: a small index-to-value dispatch.
// Note: computed goto through the existing table (&D_00370000 - 13340). The labels are kept
//       by empty asm "X" operands. r is pinned to v0 and forced live on the default path by
//       an empty asm, so the move lands in the beqz delay slot. Needs -fno-reorder-blocks.
s32 func_0018c528(u32 a0) {
    register s32 r asm("$2");
    __asm__ volatile("" : : "X"(&&L_two), "X"(&&L_zero), "X"(&&L_four));
    r = 0;
    if (a0 >= 14)
        goto L_default;
    goto *((void **)(&D_00370000 - 13340))[a0];
L_two:
    return 287;
L_zero:
    return 0;
L_default:
    __asm__ volatile("" : "+r"(r));
    return r;
L_four:
    return (s32)a0 + 279;
}

// FUN_0018e0d8 (48 bytes)
// Code: a1 is stored as a byte at a0[44], with the value 3 replaced by 4. The byte at a0[45]
//       is ~((1 << (v & 0xff)) | 1).
// Guess: a level byte and a bit-mask byte in a small struct.
// Note: the branch (not movn) is forced by an empty asm after the 4; the masked shift amount
//       is pinned to $14 so the andi stays.
void func_0018e0d8(u8 *a0, s32 a1) {
    register s32 v asm("$13");
    register s32 sh asm("$14");
    v = a1;
    if (a1 == 3) {
        v = 4;
        __asm__ volatile("" : "+r"(v));
    }
    sh = v & 0xff;
    a0[44] = (u8)v;
    a0[45] = (u8)~((1 << sh) | 1);
}

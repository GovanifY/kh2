#include "../common/types.h"

// FUN_002344c0 (92 bytes, matched by hand in a quick harness)
// Code: pushes one 32-byte record into a 64-entry ring buffer. Counter A (word at 0x0035e360)
//       is the ring index and wraps at 64. Counter B (word at 0x0035e368) is a running count,
//       which is returned. Record at 0x01dadc00 + idx*32: word 0 = 9, word 1 = count,
//       words 2..6 = a0..a4.
// Guess: an event or log ring that stores up to five words per entry.
// Note: address math and the store sequence are one inline asm block with explicit t-registers
//       (the original order is kept exactly). The return value is pinned to $2.
u32 func_002344c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    register u32 hA asm("$10");
    register u32 hB asm("$9");
    register u32 cnt asm("$11");
    register u32 nidx asm("$13");
    register u32 ncnt asm("$12");
    register u8* rbase asm("$15");
    register u32 retv asm("$2");
    hA = 0x00360000;
    asm volatile("" : "+r"(hA));
    hB = 0x00360000;
    asm volatile("" : "+r"(hB));
    u32* pA = (u32*)hA;
    u32* pB = (u32*)hB;
    u32 idx = pA[-1832];
    cnt = pB[-1830];
    u32 rb = 0x01db0000;
    asm volatile("" : "+r"(rb));
    rbase = (u8*)rb - 9216;
    asm volatile("" : "+r"(rbase));
    asm volatile("addiu %0,%1,1" : "=r"(nidx) : "r"(idx));
    u32 sh = idx;
    asm volatile("sll %0,%0,5" : "+r"(sh));
    asm volatile("andi %0,%0,0x3f" : "+r"(nidx));
    asm volatile("addu %0,%0,%1" : "+r"(sh) : "r"(rbase));
    u8* rec = (u8*)sh;
    asm volatile("addiu %0,%1,1" : "=r"(ncnt) : "r"(cnt));
    asm volatile(
        "sw %[a4],24(%[rec])\n\t"
        "li $15,9\n\t"
        "move %[ret],%[cnt]\n\t"
        "sw %[nidx],-7328(%[hA])\n\t"
        "sw %[ncnt],-7320(%[hB])\n\t"
        "sw $15,0(%[rec])\n\t"
        "sw %[a0],8(%[rec])\n\t"
        "sw %[a1],12(%[rec])\n\t"
        "sw %[a2],16(%[rec])\n\t"
        "sw %[a3],20(%[rec])\n\t"
        : [ret] "=r"(retv)
        : [a4] "r"(a4), [rec] "r"(rec), [cnt] "r"(cnt), [nidx] "r"(nidx),
          [ncnt] "r"(ncnt), [hA] "r"(hA), [hB] "r"(hB),
          [a0] "r"(a0), [a1] "r"(a1), [a2] "r"(a2), [a3] "r"(a3)
        : "$15", "memory");
    *(u32*)(rec + 4) = cnt;
    return retv;
}

// FUN_00237458 (64 bytes)
// Code: a1 indexes a table of 4-byte entries at +12 of a0 (an entry holds a u16 id). The id
//       plus a2 times 20 gives a 20-byte record offset into the block at +8. The function stores
//       a3 at the record's first word and at its +8 word stores a3 + old(+8) - old(+0).
// Guess: updates a record in a table, keeping a running difference.
// Note: the index is pinned to $5 so the table address goes straight into a1, as in the original.
void func_00237458(u8* a0, u32 a1, s32 a2, u32 a3) {
    register u32 i asm("$5") = a1 << 2;
    u32 tb = (u32)*(u8**)(a0 + 12);
    i += tb;
    u16 v = *(u16*)i;
    u8* rec = *(u8**)(a0 + 8) + 20 * ((s32)v + a2);
    u32 old0 = *(u32*)rec;
    u32 old8 = *(u32*)(rec + 8);
    *(u32*)rec = a3;
    *(u32*)(rec + 8) = a3 + old8 - old0;
}

// FUN_00237508 (52 bytes)
// Code: same record lookup as FUN_00237458, then returns (word at +8) - (word at +0).
// Guess: reads a difference of two fields of a looked-up record.
// Note: needs -falign-functions=1 for this object (52 bytes is not a multiple of 8).
u32 func_00237508(u8* a0, u32 a1, s32 a2) {
    register u32 i asm("$5") = a1 << 2;
    u32 tb = (u32)*(u8**)(a0 + 12);
    i += tb;
    u16 v = *(u16*)i;
    u8* rec = *(u8**)(a0 + 8) + 20 * ((s32)v + a2);
    return *(u32*)(rec + 8) - *(u32*)rec;
}

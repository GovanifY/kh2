#include "../common/types.h"

// Ring-buffer writers. Each records one 32-byte slot of D_01dadc00 (64 slots).
// A slot holds a state word, a serial, and six argument words. The write index
// and the serial counter live in D_0035e360 and D_0035e368. Each call writes
// its six args into the next slot, stores state, advances the index (mod 64),
// bumps the serial, and returns the serial it recorded.
//
// The three functions have the same body and differ only in the state value
// (8, 10, 11). Each body is written out in full: an always_inline helper
// schedules differently, so the bodies are kept separate to match the original.
//
// Register pins give the original registers: idx in $14 (later the slot pointer),
// serial in $11, next idx in $13, next serial in $12. Empty asm barriers keep the
// original store order: the a5 store, the two global stores, the state store,
// the a0..a4 stores, then the serial store in the jr delay slot.

extern s32 D_0035e360;   // ring write index (0..63)
extern s32 D_0035e368;   // ring serial counter

struct RingSlot {
    s32 state;
    s32 serial;
    u32 a0;
    u32 a1;
    u32 a2;
    u32 a3;
    u32 a4;
    u32 a5;
};

extern RingSlot D_01dadc00[0x40];

// Records state 8.
u32 func_00234348(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    register s32 idx;
    register s32 serial asm("$11");
    register s32 nidx asm("$13");
    register s32 nser asm("$12");
    register RingSlot* slot asm("$14");
    u32 state;
    u32 out;

    idx = D_0035e360;
    serial = D_0035e368;
    slot = D_01dadc00 + idx;
    nidx = (idx + 1) & 0x3f;
    nser = serial + 1;
    asm volatile("" : "+r"(nidx), "+r"(nser), "+r"(slot), "+r"(serial));
    slot->a5 = a5;
    asm volatile("" ::: "memory");
    state = 8;
    out = serial;
    asm volatile("" : "+r"(state), "+r"(out) : : "memory");
    D_0035e360 = nidx;
    D_0035e368 = nser;
    asm volatile("" ::: "memory");
    slot->state = state;
    slot->a0 = a0;
    slot->a1 = a1;
    slot->a2 = a2;
    slot->a3 = a3;
    slot->a4 = a4;
    asm volatile("" ::: "memory");
    slot->serial = serial;
    return out;
}

// Records state 10.
u32 func_00234400(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    register s32 idx;
    register s32 serial asm("$11");
    register s32 nidx asm("$13");
    register s32 nser asm("$12");
    register RingSlot* slot asm("$14");
    u32 state;
    u32 out;

    idx = D_0035e360;
    serial = D_0035e368;
    slot = D_01dadc00 + idx;
    nidx = (idx + 1) & 0x3f;
    nser = serial + 1;
    asm volatile("" : "+r"(nidx), "+r"(nser), "+r"(slot), "+r"(serial));
    slot->a5 = a5;
    asm volatile("" ::: "memory");
    state = 10;
    out = serial;
    asm volatile("" : "+r"(state), "+r"(out) : : "memory");
    D_0035e360 = nidx;
    D_0035e368 = nser;
    asm volatile("" ::: "memory");
    slot->state = state;
    slot->a0 = a0;
    slot->a1 = a1;
    slot->a2 = a2;
    slot->a3 = a3;
    slot->a4 = a4;
    asm volatile("" ::: "memory");
    slot->serial = serial;
    return out;
}

// Records state 11.
u32 func_00234460(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    register s32 idx;
    register s32 serial asm("$11");
    register s32 nidx asm("$13");
    register s32 nser asm("$12");
    register RingSlot* slot asm("$14");
    u32 state;
    u32 out;

    idx = D_0035e360;
    serial = D_0035e368;
    slot = D_01dadc00 + idx;
    nidx = (idx + 1) & 0x3f;
    nser = serial + 1;
    asm volatile("" : "+r"(nidx), "+r"(nser), "+r"(slot), "+r"(serial));
    slot->a5 = a5;
    asm volatile("" ::: "memory");
    state = 11;
    out = serial;
    asm volatile("" : "+r"(state), "+r"(out) : : "memory");
    D_0035e360 = nidx;
    D_0035e368 = nser;
    asm volatile("" ::: "memory");
    slot->state = state;
    slot->a0 = a0;
    slot->a1 = a1;
    slot->a2 = a2;
    slot->a3 = a3;
    slot->a4 = a4;
    asm volatile("" ::: "memory");
    slot->serial = serial;
    return out;
}

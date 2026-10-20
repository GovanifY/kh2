#include "../common/types.h"

// 128-bit integer (lq/sq) type
typedef int u128 __attribute__((mode(TI)));

struct EntryList {
    u8 pad0[8];
    u8* ents;          // 0x08: array of 20-byte entries
    u8 pad1[0x18];
    s32 count;         // 0x24
};

struct QuadPair {
    u8 pad[0x50];
    u128 a;            // 0x50
    u128 b;            // 0x60
    u8 pad2[0x10];
    f32 f;             // 0x80
};

struct Slot28 { s32 id; u8 pad[0x24]; };

extern u32 D_0035f28c;
extern u8 D_0035f299;
extern Slot28* D_0035dcfc;
extern s32 D_0035eb34;
extern s32 D_0035eb28;
extern s32 D_01dae680;

// FUN_00141928 (68 bytes)
// Code: for each of count 20-byte entries, if byte 17 equals the low byte of arg1, byte 16 is set to 1.
// Guess: marks every entry with a given id as flagged.
void func_00141928(u32 a0, u32 a1) {
    EntryList* l = (EntryList*)a0;
    u8 id = (u8)a1;
    s32 n = l->count;
    for (s32 i = 0; i < n; i++) {
        u8* e = (u8*)(i * 20 + (u32)l->ents);
        if (e[17] == id) e[16] = 1;
    }
}

// FUN_00281e70 (20 bytes)
// Code: stores arg0 to a global word and clears a global byte.
// Guess: sets a current value and resets its flag.
void func_00281e70(u32 a0) {
    D_0035f28c = a0;
    D_0035f299 = 0;
}

// FUN_0022f4f0 (56 bytes)
// Code: scans 96 40-byte records from a global table for first word == arg0; returns record+23 or 0.
// Guess: finds a table slot by id and returns a pointer into it.
u8* func_0022f4f0(s32 a0) {
    for (s32 i = 0; i < 96; i++) {
        Slot28* e = D_0035dcfc + i;
        if (e->id == a0) return (u8*)e + 23;
    }
    return 0;
}

// FUN_00107300 (48 bytes)
// Code: copies 16 bytes from a1 to obj+0x50 and from a2 to obj+0x60 (skipping self-copies), stores float arg3 at +0x80.
// Guess: sets two vectors and a scalar on an object.
// Inline asm used: empty asm per pointer only, to stop address folding so sq uses a register base like the original.
void func_00107300(QuadPair* q, u128* a, u128* b, f32 f) {
    u128* d = &q->a;
    __asm__("" : "+r"(d));
    if (d != a) { register u128 t asm("$8") = *a; *d = t; }
    d = &q->b;
    __asm__("" : "+r"(d));
    if (d != b) { register u128 t asm("$8") = *b; *d = t; }
    q->f = f;
}

// FUN_0023cdb8 (32 bytes)
// Code: sets one global word to 1, and clears two other global words.
// Guess: resets a state block.
void func_0023cdb8() {
    D_0035eb34 = 1;
    D_0035eb28 = 0;
    D_01dae680 = 0;
}

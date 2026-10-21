#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_001e0958 (64 bytes, leaf)
// Code: nested fill over 9 rows x 3 columns. For each entry, writes the row
//       number to byte +24 and the column (1..3) to byte +25 of the record
//       at arg0, then advances arg0 by 64 bytes.
// Guess: builds a 27-entry table of (row, col) tags in a 64-byte-stride array.
// Matching tricks: the row update is copied into the loop head (do/while
// with `row = nxt` first), which gives the bnezl with the row copy in its
// delay slot. Row and column are pinned to $13 and $15 so the slot layout
// matches.
void func_001e0958(u32 a0) {
    register s32 row asm("$13");
    register s32 nxt asm("$14");
    register s32 col asm("$15");
    nxt = 0;
    do {
        row = nxt;
        col = 0;
        do {
            col = col + 1;
            *(u8 *)(a0 + 24) = row;
            *(u8 *)(a0 + 25) = col;
            a0 += 64;
        } while (col < 3);
        nxt = row + 1;
    } while (nxt < 9);
}

// ---------------------------------------------------------------------------
// FUN_001e0d08 (92 bytes, leaf)
// Code: stores the three floats of the vector at arg1 (x, y, z) into the
//       32-byte-stride entry selected by a0+32 inside the table pointed to by
//       the global at 0x352bd0. Entry base is *(*(0x352bd0) + 3524) + (a0[32] << 6).
//       Field offsets: x at +48, y at +52, z at +56.
// Guess: writes a vector (position) into a per-object record.
// Matching tricks: the global base is a literal (lui 0x350000 kept in $12,
// offset folded into the lw). Each store is followed by an empty "memory"
// asm so the global and a0[32] are reloaded as in the original. The shift
// result is kept live past each store with an empty asm use so the add
// writes into $14 (t6) as in the original.
void func_001e0d08(u32 a0, u32 a1) {
    register u32 t4 asm("$12");
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    f32 f0, f1, f2;
    t4 = 0x00350000u;
    t7 = *(u32 *)(a0 + 32);
    t5 = *(u32 *)(t4 + 11216);
    asm volatile("" ::: "memory");
    t7 = t7 << 6;
    f0 = *(f32 *)(a1 + 0);
    asm volatile("" ::: "memory");
    t6 = *(u32 *)(t5 + 3524);
    asm volatile("" ::: "memory");
    f1 = *(f32 *)(a1 + 4);
    asm volatile("" : "+r"(t6) :: "memory");
    t6 = t6 + t7;
    asm volatile("" ::: "memory");
    f2 = *(f32 *)(a1 + 8);
    *(f32 *)(t6 + 48) = f0;
    asm volatile("" : "+r"(t4), "+r"(a0) : "r"(t7) : "memory");
    t5 = *(u32 *)(t4 + 11216);
    t7 = *(u32 *)(a0 + 32);
    t6 = *(u32 *)(t5 + 3524);
    t7 = t7 << 6;
    t6 = t6 + t7;
    *(f32 *)(t6 + 52) = f1;
    asm volatile("" : "+r"(t4), "+r"(a0) : "r"(t7) : "memory");
    t5 = *(u32 *)(t4 + 11216);
    t7 = *(u32 *)(a0 + 32);
    t6 = *(u32 *)(t5 + 3524);
    t7 = t7 << 6;
    t6 = t6 + t7;
    *(f32 *)(t6 + 56) = f2;
    asm volatile("" :: "r"(t7));
}

// ---------------------------------------------------------------------------
// FUN_001e0d68 (92 bytes, leaf)
// Code: same as FUN_001e0d08 but the three floats go to offsets +32, +36, +40
//       of the selected entry (the first entry field group rather than +48).
// Guess: writes a second vector (for example a velocity or a second position)
//        into the same per-object table.
// Matching tricks: identical shape to FUN_001e0d08; only the store offsets
// differ.
void func_001e0d68(u32 a0, u32 a1) {
    register u32 t4 asm("$12");
    register u32 t5 asm("$13");
    register u32 t6 asm("$14");
    register u32 t7 asm("$15");
    f32 f0, f1, f2;
    t4 = 0x00350000u;
    t7 = *(u32 *)(a0 + 32);
    t5 = *(u32 *)(t4 + 11216);
    asm volatile("" ::: "memory");
    t7 = t7 << 6;
    f0 = *(f32 *)(a1 + 0);
    asm volatile("" ::: "memory");
    t6 = *(u32 *)(t5 + 3524);
    asm volatile("" ::: "memory");
    f1 = *(f32 *)(a1 + 4);
    asm volatile("" : "+r"(t6) :: "memory");
    t6 = t6 + t7;
    asm volatile("" ::: "memory");
    f2 = *(f32 *)(a1 + 8);
    *(f32 *)(t6 + 32) = f0;
    asm volatile("" : "+r"(t4), "+r"(a0) : "r"(t7) : "memory");
    t5 = *(u32 *)(t4 + 11216);
    t7 = *(u32 *)(a0 + 32);
    t6 = *(u32 *)(t5 + 3524);
    t7 = t7 << 6;
    t6 = t6 + t7;
    *(f32 *)(t6 + 36) = f1;
    asm volatile("" : "+r"(t4), "+r"(a0) : "r"(t7) : "memory");
    t5 = *(u32 *)(t4 + 11216);
    t7 = *(u32 *)(a0 + 32);
    t6 = *(u32 *)(t5 + 3524);
    t7 = t7 << 6;
    t6 = t6 + t7;
    *(f32 *)(t6 + 40) = f2;
    asm volatile("" :: "r"(t7));
}

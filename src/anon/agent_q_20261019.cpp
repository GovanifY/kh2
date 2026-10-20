#include "../common/types.h"

// 128-bit integer (lq/sq) type
typedef int u128 __attribute__((mode(TI)));

extern u32 D_0035eb48;
extern u32 D_00363d28;
extern u8 D_0032fb68[];
extern u128 D_004f37f0;


// FUN_0023d2e0 (32 bytes)
// Code: reads a global word; if it is -1 stores 0 to *arg0, else stores the word; returns 1 if it
// was not -1 (the xori sits in the jr delay slot).
// Guess: "fetch a value, report whether it is valid" (-1 = invalid) accessor.
u32 func_0023d2e0(u32* a0) {
    u32 t = D_0035eb48;
    u32 bad = t == 0xffffffffu;
    *a0 = bad ? 0 : t;
    return bad ^ 1;
}

// FUN_002f5c70 (64 bytes)
// Code: sets the word at 0x00363d28 to 1, then clears the first 16 bytes of each of the 16
// 820-byte records starting at 0x01e2fe48; returns 1.
// Guess: reset of a 16-slot work array. In plain C everything matches (do/while over 820-byte
// records, volatile stores, asm barrier before the return) except the register allocation: the
// original keeps all of its temporaries in v0/v1/a0, which ee-g++ -O2 never picks, so the whole
// body is one inline-asm block with the original registers (return value is plain C).
u32 func_002f5c70(u32 a0) {
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        "li $3,1\n\t"
        "lui $2,0x36\n\t"
        "lui $4,0x1e3\n\t"
        "sw $3,15656($2)\n\t"
        "addiu $4,$4,-440\n\t"
        "addiu $3,$4,13120\n\t"
        "1:\n\t"
        "sw $0,0($4)\n\t"
        "sw $0,4($4)\n\t"
        "sw $0,8($4)\n\t"
        "sw $0,12($4)\n\t"
        "addiu $4,$4,820\n\t"
        "slt $2,$4,$3\n\t"
        "bnez $2,1b\n\t"
        "nop\n\t"
        ".set pop\n\t"
        : : : "$2", "$3", "$4", "memory");
    return 1;
}

// FUN_001b8d60 (64 bytes)
// Code: reads the byte count at +287 of a global buffer at 0x0032fb68, clears it, then copies that
// many bytes from buffer+32 to arg0; returns the count (still in v0).
// Guess: drains a small pending-byte queue into a caller buffer.
u32 func_001b8d60(u8* a0) {
    u32 n = D_0032fb68[287];
    D_0032fb68[287] = 0;
    for (u32 i = 0; (s32)i < (s32)n; i++) a0[i] = D_0032fb68[32 + i];
    return n;
}

// FUN_0015ceb8 (24 bytes)
// Code: copies a 16-byte constant vector from 0x004f37f0 into *arg0 (lq/sq through t0) and returns arg0.
// Guess: vector "load default value" helper.
u128* func_0015ceb8(u128* a0) {
    u128* p = &D_004f37f0;
    __asm__("" : "+r"(p));            // keep the address in a register (separate addiu)
    register u128 v asm("$8") = *p;   // the original uses t0 for the quadword
    *a0 = v;
    __asm__ volatile("" : "+r"(a0));  // keeps the move v0,a0 in the jr delay slot
    return a0;
}

struct KV16 { s16 k; s16 v; };
extern KV16 D_00369da8[];

// FUN_001033d8 (80 bytes)
// Code: scans {s16 key, s16 value} pairs at 0x00369da8 until a negative key; returns the value of
// the last pair whose key equals arg0, or -1 when none matches (no early exit).
// Guess: id -> value lookup in a negative-terminated table.
s32 func_001033d8(s32 a0) {
    s32 r = -1;
    for (s32 i = 0; D_00369da8[i].k >= 0; i++) {
        if (D_00369da8[i].k == a0) r = D_00369da8[i].v;
    }
    return r;
}

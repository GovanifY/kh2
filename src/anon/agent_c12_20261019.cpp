#include "../common/types.h"

// FUN_00243150 (64 bytes): scans 12-byte s16-key records from 0x371840 up to the first
// negative key. Returns the address of the last record whose key equals
// a0 (xor-zero test), or 0 if none matches or the first key is negative.
// Matched as a whole-function noreorder asm body: the bltz delay slot is `move v0,zero`,
// the loop is movz on the xor result with a bgez back-edge carrying the xor in its
// delay slot, and gcc's own epilogue supplies the final `jr ra; nop`. The result is
// pinned to $2 and the parameter to $4 so the epilogue has no stray move.
u32 func_00243150(s32 a0) {
    register s32 x4 asm("$4") = a0;
    register u32 v0 asm("$2");
    asm volatile(
        ".set noreorder\n\t"
        "lui $14, 0x37\n\t"
        "lh $15, 6208($14)\n\t"
        "bltz $15, 1f\n\t"
        "daddu $2, $0, $0\n\t"
        "addiu $14, $14, 6208\n\t"
        "lh $15, 0($14)\n\t"
        "xor $15, $15, $4\n\t"
        "2:\n\t"
        "movz $2, $14, $15\n\t"
        "addiu $14, $14, 12\n\t"
        "lh $15, 0($14)\n\t"
        "nop\n\t"
        "nop\n\t"
        "bgez $15, 2b\n\t"
        "xor $15, $15, $4\n\t"
        "1:\n\t"
        ".set reorder"
        : "=r"(v0) : "r"(x4) : "$14", "$15", "memory");
    return v0;
}

// FUN_00243190 (48 bytes): linear search of 11 u32 words at 0x3718D0 for a0. Returns the
// index of the first match, or 11 if none. Matched as a whole-function noreorder asm body
// so the bnezl loop-back carries the reload `lw` in its (annulled) delay slot. The final
// `jr ra; nop` comes from gcc's epilogue.
u32 func_00243190(u32 a0) {
    register u32 x4 asm("$4") = a0;
    register u32 v0 asm("$2");
    asm volatile(
        ".set noreorder\n\t"
        "lui $15, 0x37\n\t"
        "daddu $2, $0, $0\n\t"
        "addiu $14, $15, 6352\n\t"
        "lw $15, 0($14)\n\t"
        "2:\n\t"
        "beq $15, $4, 3f\n\t"
        "addiu $14, $14, 4\n\t"
        "addiu $2, $2, 1\n\t"
        "sltiu $15, $2, 11\n\t"
        "bnezl $15, 2b\n\t"
        "lw $15, 0($14)\n\t"
        "3:\n\t"
        ".set reorder"
        : "=r"(v0) : "r"(x4) : "$14", "$15", "memory");
    return v0;
}

// FUN_00253330 (76 bytes): scans 16-byte records from 0x3726D0 comparing the s16 key at +0
// with a0; the scan stops after the first record whose successor has a negative key. It
// returns the address of the last matching record, or 0 if none matches. Plain C, pins:
// v0=$2, t7=$15, base/t6=$14, t4=$12, t5=$13. The memory barrier after v0 = 0 keeps the
// move before the first load; the movz is tied to the second load so it lands in the
// back-edge delay slot; operand order of the two addu follows the original (t3+t1, t6+t1).
u32 func_00253330(s32 a0) {
    register u32 v0 asm("$2");
    register s32 t7 asm("$15");
    register u8* base asm("$14");
    u8* t1;
    u32 t2;
    u32 t3;
    register u8* t4 asm("$12");
    register u32 t6 asm("$14");
    register u8* t5 asm("$13");
    s16 n;
    base = (u8*)0x370000;
    asm volatile("" : "+r"(base));
    v0 = 0;
    asm volatile("" : "+r"(v0) : : "memory");
    t7 = *(s16*)(base + 9936);
    t2 = 0;
    if (t7 < 0) {
        goto done;
    }
    t1 = base + 9936;
    t3 = 0;
    do {
        t4 = (u8*)((u32)t3 + (u32)t1);
        asm volatile("" : "+r"(t4));
        t2 += 1;
        t6 = t2 << 4;
        asm volatile("" : "+r"(t6) : : "memory");
        t7 = *(s16*)t4;
        t3 = t6;
        t5 = (u8*)((u32)t6 + (u32)t1);
        t7 = (s32)t7 ^ a0;
        n = *(s16*)t5;
        asm volatile("" : "+r"(v0) : "r"(n));
        if (t7 == 0) {
            v0 = (u32)t4;
        }
    } while (n >= 0);
done:
    return v0;
}

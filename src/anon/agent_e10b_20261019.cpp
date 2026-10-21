#include "../common/types.h"

extern u8 D_00370000[];

// FUN_00243150 (64 bytes): scans 12-byte s16-key records from 0x371840 up to the first
// negative key. Returns the address of the last record whose key equals a0, or 0.
// Object (agent_e10b) needs -fno-schedule-insns2 (gives the plain bgez with the xor in its slot
// instead of bgezl). Pins: v0=$2, k=$15, base=$14; the "+r"/"memory" barrier after the
// first test forces the second lh; the empty asm on v0 keeps movz before the addiu.
u32 func_00243150(s32 a0) {
    register u32 v0 asm("$2");
    register s32 k asm("$15");
    register u8* base asm("$14");
    base = (u8*)0x370000;
    asm volatile("" : "+r"(base));
    v0 = 0;
    k = *(s16*)(base + 6208);
    if (k < 0) goto done;
    base += 6208;
    asm volatile("" : "+r"(base) : : "memory");
    k = *(s16*)base;
    do {
        s32 x = k ^ a0;
        if (x == 0) v0 = (u32)base;
        asm volatile("" : "+r"(v0));
        base += 12;
        k = *(s16*)base;
    } while (k >= 0);
done:
    asm volatile("" : "=r"(k));
    return v0;
}

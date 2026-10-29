#include "../common/types.h"

// Agent R46p_98 (2026-10-29): FUN_00252710 (76 bytes), SLPM_666.75.
// Calls func_00252110() to get an index, reads the byte at index + (D_00370000 + 0x2600). If the byte
// is non-zero, calls YS::MENUFLAG::Check(byte) (mangled symbol) and returns (result != 0); otherwise 0.
// The result lives in s0 across the calls (pinned to $16), zeroed before the first call. The call
// result is read from $2 by an asm sltu so the bool is written straight into s0.
extern "C" s32 func_00252110(void);
extern "C" void ms_menuflag_check(s32 a0) asm("_ZN2YS8MENUFLAG5CheckEi");
extern u8 D_00370000[];

s32 func_00252710(void) {
    register s32 result asm("$16") = 0;
    asm volatile("" : "+r"(result));
    u8 *p = (u8 *)(func_00252110() + (u32)&D_00370000[0x2600]);
    u8 b = *p;
    if (b != 0) {
        ms_menuflag_check(b);
        asm volatile("sltu %0,$0,$2" : "=r"(result) : : "$2");
    }
    return result;
}

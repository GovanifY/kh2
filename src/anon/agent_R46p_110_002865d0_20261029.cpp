#include "../common/types.h"

// FUN_002865d0 (84 bytes). Calls Tz::CmNewFlg::GetSram(a0) (symbol _ZN2Tz8CmNewFlg7GetSramEv),
// then sets bit (a0 & 31) in the word at (result + 204 + (a0 >> 5) * 4) if it was clear.
// The store is conditional: a beqzl skips it when the bit is already set.
u32 CmNewFlg_GetSram(u32 a0) asm("_ZN2Tz8CmNewFlg7GetSramEv");

void r_FUN_002865d0(u32 a0) asm("func_002865d0");

void r_FUN_002865d0(u32 a0) {
    register u8 *base asm("$2") = (u8 *)CmNewFlg_GetSram(a0) + 204;
    register u32 off asm("$15") = (a0 >> 5) << 2;
    u32 sh = a0 & 0x1f;
    asm volatile("" : "+r"(sh));
    register u32 *w asm("$12");
    // addu t4,t7,v0 (operand order matches the original encoding; gcc would emit addu t4,v0,t7)
    asm volatile("addu %0,%1,%2" : "=r"(w) : "r"(off), "r"(base));
    u32 bit = 1u << sh;
    u32 v = *w;
    if ((v & bit) == 0) {
        *w = v | bit;
    }
}

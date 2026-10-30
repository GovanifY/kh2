#include "../common/types.h"

// Agent R46p_141 (2026-10-29): FUN_002dceb0 (100 bytes), SLPM_666.75.
// Calls func_002dc7c8(a0) (returns p). s = a0 + 0x8000 is computed before the call so the
// compiler fills the call's delay slot with it. Then r = s->f104 / p->f160, and the result is
// min(r, K) clamped below at 0, where K is a float constant at 0x375DAC. The K address is built
// with lui then addiu, pinned by inline asm so the compiler keeps the original order.
extern "C" u32 func_002dc7c8(u32);

f32 func_002dceb0(u32 a0) {
    u8* s = (u8*)(a0 + 0x8000);
    u32 p = func_002dc7c8(a0);
    f32 num = *(f32*)(s + 104);
    f32 den = *(f32*)(p + 160);
    u32 kp = 0x00370000u;
    __asm__ __volatile__("addiu %0,%0,23980" : "+r"(kp));
    __asm__("" : "+r"(kp));
    f32 r = num / den;
    f32 k = *(f32*)kp;
    f32 m = r;
    if (k < r) m = k;
    if (m < 0.0f) m = 0.0f;
    return m;
}

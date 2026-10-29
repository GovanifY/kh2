#include "../common/types.h"

// Agent R46p_65 (2026-10-29): FUN_001df9c8 (108 bytes), SLPM_666.75.
// Sets flag 0x20 at +92 unless already set. Then reads the record at +68: if its word at +16
// has bit 0x80, tail-calls ryj::EFFECT::loop_end_kill on the object at +64; else if bit 0x40,
// tail-calls ryj::EFFECT::fadeout_kill with the byte at +5 converted to float.
extern "C" void r_loop_end_kill(void *self) asm("_ZN3ryj6EFFECT13loop_end_killEv");
extern "C" void r_fadeout_kill(void *self, float t) asm("_ZN3ryj6EFFECT12fadeout_killEf");

void func_001df9c8(u8 *a0) {
    u32 flags;
    u8 *rec;
    u32 f;
    flags = *(u32*)(a0 + 92);
    if ((flags & 0x20) != 0) {
        return;
    }
    *(u32*)(a0 + 92) = flags | 0x20;
    rec = *(u8**)(a0 + 68);
    f = *(u32*)(rec + 16);
    if ((f & 0x80) != 0) {
        r_loop_end_kill(*(void**)(a0 + 64));
        return;
    }
    if ((f & 0x40) != 0) {
        r_fadeout_kill(*(void**)(a0 + 64), (float)(u32)rec[5]);
    }
}

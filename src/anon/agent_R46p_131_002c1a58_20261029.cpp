#include "../common/types.h"

// FUN_002c1a58 (68 bytes), SLPM_666.75. Calls func_002be770(arg0). Then sets bit 0 of the word at +1420,
// writes zero to the word at +2788 and the byte at +2792, and stores the vtable 0x361b20 at offset 0.
// Guess: a constructor-style reset of a sub-object that installs its vtable after its base call.
// The asm barriers pin the store order to the original.
extern "C" void func_002be770(u32 p);

void func_002c1a58(u32 a0) {
    func_002be770(a0);
    u32 f = *(u32 *)(a0 + 1420);
    __asm__ volatile("" ::: "memory");
    u32 vt = 0x00360000u;
    __asm__("" : "+r"(vt));
    vt += 6944u;
    __asm__ volatile("" : "+r"(vt) : : "memory");
    *(u32 *)(a0 + 2788) = 0;
    f |= 1;
    __asm__ volatile("" : "+r"(f) : : "memory");
    *(u32 *)a0 = vt;
    __asm__ volatile("" ::: "memory");
    *(u32 *)(a0 + 1420) = f;
    __asm__ volatile("" ::: "memory");
    *(u8 *)(a0 + 2792) = 0;
}

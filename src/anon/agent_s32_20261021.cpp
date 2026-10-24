#include "../common/types.h"

// Callees. func_<addr> names come from the linker script (one symbol per function address).
extern "C" u32 func_00305640(u32 id);
extern "C" u32 func_00305660(u32 id);
extern "C" u32 func_00305690(u32 id, void* out);
extern "C" u32 func_001666a0(u32 a0);
extern "C" u32 func_001666d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

// FUN_0014d478 (108 bytes), MATCHED.
// Waits on the semaphore whose id is at 0x349e40, then walks 88-byte records from 0x349e7c to
// 0x349edc (end = base + 176). For each record it queries the semaphore status into buf; if
// buf[3] is non-zero it signals the record's semaphore (+24).
// Matching: the base address is materialised from a literal and passed through an empty asm
// barrier so GCC emits lui 0x35 plus offsets rather than lui 0x34 + ori. The loop end is
// computed from s0 after a second barrier, and the compare is signed (slt, not sltu).
void func_0014d478(void) {
    u8* base = (u8*)0x00350000;
    __asm__("" : "+r"(base));
    func_00305660(*(u32*)(base - 25024));

    base = (u8*)0x00350000;
    __asm__("" : "+r"(base));
    u8* s0 = base - 24964;
    __asm__("" : "+r"(s0));
    u8* s1 = s0 + 176;
    u32 buf[8];

    do {
        func_00305690(*(u32*)(s0 + 24), buf);
        if (buf[3] != 0) {
            func_00305640(*(u32*)(s0 + 24));
        }
        s0 += 88;
    } while ((s32)s0 < (s32)s1);
}


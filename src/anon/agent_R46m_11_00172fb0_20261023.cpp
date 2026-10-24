#include "../common/types.h"

// Agent R46m_11: FUN_00172fb0 (84 bytes), SLPM_666.75.
// Builds a 16-byte stack block: halfword at +8 = 0xffff, byte +1 = a0[0], byte +2 = a0[4],
// byte +0 = 0xff, halfwords at +4 and +6 = 0xffff. Then calls FUN_00104f58(block, word at a0+8, 0, 0, 0).
// Register pins and empty memory barriers fix the order of the arguments and stores.
extern "C" void func_00104f58(void*, u32, u32, u32, u32);

void func_00172fb0(u8* a0) {
    u8 buf[16];
    register u8* p asm("$14");
    register u32 k asm("$15");
    register u32 b0 asm("$13");
    register u32 b4 asm("$12");
    register u8* bp asm("$4");
    register u32 z2 asm("$6");
    register u32 z3 asm("$7");
    register u32 z4 asm("$8");
    register u32 a1 asm("$5");

    p = a0;
    asm volatile("" : "+r"(p));
    k = 0xffff;
    asm volatile("" : "+r"(k));
    asm volatile("move $6,$0\n\tmove $7,$0" : "=r"(z2), "=r"(z3));
    b0 = a0[0];
    asm volatile("move $8,$0" : "=r"(z4));
    b4 = p[4];
    bp = buf;
    asm volatile("" : "+r"(bp));
    asm volatile("" ::: "memory");
    *(u16*)(buf + 8) = k;
    asm volatile("" ::: "memory");
    buf[1] = b0;
    asm volatile("" ::: "memory");
    buf[2] = b4;
    asm volatile("" ::: "memory");
    buf[0] = k;
    asm volatile("" ::: "memory");
    *(u16*)(buf + 4) = k;
    asm volatile("" ::: "memory");
    *(u16*)(buf + 6) = k;
    asm volatile("" : "+r"(bp));
    a1 = *(u32*)(p + 8);
    func_00104f58(bp, a1, z2, z3, z4);
}

#include "../common/types.h"

// FUN_002c1ae8 (96 bytes): v = Gumi::getCourse(a0); a0->+2788 = 3*v + 0x375515;
// c = YS::COURSE::Get(Gumi::getCourse(a0)); FUN_002c1b60(a0, c); tail-call FUN_00198450(a0).
extern "C" u32 func_002c1b48(u32);
extern "C" u32 func_001c2b58(u32);
extern "C" void func_002c1b60(u32, u32);
extern "C" u32 func_00198450(u32);

u32 func_002c1ae8(u32 a0) {
    u32 v = func_002c1b48(a0);
    u32 k;
    __asm__ __volatile__("lui %0,0x37" : "=r"(k));
    u32 t = v << 1;
    __asm__ __volatile__("" : "+r"(t));
    k += 21784u;
    __asm__ __volatile__("" : "+r"(k));
    t += v;
    __asm__ __volatile__("" : "+r"(t));
    k -= 3;
    __asm__ __volatile__("" : "+r"(k));
    register u32 self asm("$4") = a0;
    __asm__ __volatile__("" : "+r"(self));
    *(u32*)(a0 + 2788) = t + k;
    u32 c = func_001c2b58(func_002c1b48(self));
    func_002c1b60(a0, c);
    return func_00198450(a0);
}

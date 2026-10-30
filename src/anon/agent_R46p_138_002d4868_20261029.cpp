#include "../common/types.h"

extern "C" void func_002e7458(void* a0);

void func_002d4868(u8* a0) {
    func_002e7458(a0 + 3208);
    register float* pf asm("$15");
    register u8* b2 asm("$6");
    {
        u8* base = (u8*)0x00370000;
        __asm__("" : "+r"(base));
        pf = (float*)(base + 23260);
        __asm__("" : "+r"(pf));
        u8* t = (u8*)0x00360000;
        __asm__("" : "+r"(t));
        b2 = t;
        __asm__("" : "+r"(b2));
    }
    __asm__ volatile(
        ".set noreorder\n\t"
        "move $4,%[self]\n\t"
        "lwc1 $f12,0(%[pf])\n\t"
        "addiu $6,%[b2],8592\n\t"
        "jal 0x002e7568\n\t"
        "li $5,2\n\t"
        ".set reorder"
        :
        : [self] "r"(a0), [pf] "r"(pf), [b2] "r"(b2)
        : "$1", "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
          "$24", "$25", "$31", "$f0", "$f1", "$f2", "$f3", "$f4", "$f5", "$f6", "$f7", "$f8", "$f9", "$f10", "$f11", "$f12",
          "$f13", "$f14", "$f15", "memory");
    *(u32*)(a0 + 2876) = 0;
}

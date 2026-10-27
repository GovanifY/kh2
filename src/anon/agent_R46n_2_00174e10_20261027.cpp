#include "../common/types.h"
typedef int u128 __attribute__((mode(TI)));
extern "C" void func_00158920(u128* a0);
// FUN_00174e10 (40 bytes): copies the 16-byte value at *(a0->0) to a stack temp (one lq/sq pair with $8) and passes its address to FUN_00158920.
void func_00174e10(u8** a0) {
    u128 tmp;
    u8* src = *a0;
    __asm__ volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(&tmp), "r"(src) : "$8", "memory");
    func_00158920(&tmp);
}

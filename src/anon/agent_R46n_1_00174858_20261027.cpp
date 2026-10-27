#include "../common/types.h"

extern "C" u32 func_001de168(u32, u32, u32, u32, u32, u32);

extern "C" void func_00174858(u8 *a0);
void func_00174858(u8 *a0) {
    u8 *s = a0;
    u32 r = func_001de168(*(u32 *)s, *(u32 *)(s + 4), *(u32 *)(s + 12), 1,
                          *(u32 *)(s + 16), *(u32 *)(*(u32 *)(s + 8) + 4));
    *(u32 *)s = r;
}

// FUN_00185a68 (44 bytes): saves a0 in a3 (kept with a pinned register), loads object at +2548, calls the vtable slot at +80 on it.
#include "../common/types.h"

void r_FUN_00185a68(u32 a0) asm("func_00185a68");
void r_FUN_00185a68(u32 a0) {
    register u32 keep asm("$7") = a0;
    asm volatile("" : : "r"(keep));
    u32 p = *(u32*)(a0 + 2548);
    u32 vt = *(u32*)p;
    ((void (*)(u32))(*(u32*)(vt + 80)))(p);
}

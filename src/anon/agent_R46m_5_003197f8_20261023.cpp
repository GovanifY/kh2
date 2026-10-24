#include "../common/types.h"

// FUN_003197f8 (40 bytes): p = *(a0 + 4). Calls slot 1 of p's vtable with p as the argument, and
// returns the callee's result. The vtable pointer is pinned to t6 and the slot to t7 so gcc
// emits the same registers as the original.
typedef s32 (*VSlot1)(void*);

s32 func_003197f8(u8* a0) {
    register u8* p asm("$4") = *(u8**)(a0 + 4);
    register void** vt asm("$14") = *(void***)p;
    register VSlot1 f asm("$15") = (VSlot1)vt[1];
    __asm__ volatile("" : "+r"(f));
    return f(p);
}

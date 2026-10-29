#include "../common/types.h"

extern "C" void func_0016a2e0(void*);

// FUN_00185a28 (64 bytes)
// Code: calls virtual slot 17 (offset 68) of arg0's vtable with arg0, then virtual
// slot 10 (offset 40) with arg0, then tail-calls FUN_0016a2e0(arg0).
// Guess: a C++ method that runs two virtual steps, then a shared helper.
void func_00185a28(void* a0) {
    void (*f1)(void*) = (void (*)(void*))((*(void***)a0)[17]);
    f1(a0);
    void (*f2)(void*) = (void (*)(void*))((*(void***)a0)[10]);
    f2(a0);
    return func_0016a2e0(a0);
}

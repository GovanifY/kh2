#include "../common/types.h"

// Callee. func_0031acc0 takes one pointer argument and its result is discarded here.
extern "C" void func_0031acc0(void*);

// FUN_00258158 (56 bytes)
// Calls func_0031acc0 three times on the same object: a0 + 872, a0 + 436, then a0.
void func_00258158(u8* a0) {
    func_0031acc0(a0 + 872);
    func_0031acc0(a0 + 436);
    func_0031acc0(a0);
    // Keeps the last call a real jal (no tail jump), as in the original.
    asm volatile("" ::: "memory");
}

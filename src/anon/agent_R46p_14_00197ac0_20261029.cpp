#include "../common/types.h"

extern "C" void func_001024a8(u32);
extern "C" void func_001d3148(u32);

// FUN_00197ac0 (56 bytes): reads the word at 0x0035037c. A non-zero word gives a tail call to
// FUN_001d3148(word + 64). Otherwise it tail-calls FUN_001024a8(a0) with the incoming a0.
void func_00197ac0(u32 a0) {
    u32* base = (u32*)0x00350000;
    u32 p = base[223];
    if (p != 0) {
        func_001d3148(p + 64);
        return;
    }
    func_001024a8(a0);
}

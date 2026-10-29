#include "../common/types.h"

// FUN_001c1708 (64 bytes)
// Walks a list headed at a0+12 (next at +36), calling FUN_001c1890 on each node.
extern "C" void func_001c1890(void* p);

void func_001c1708(u8* a0) {
    u8* p = *(u8**)(a0 + 12);
    if (p == 0) {
        return;
    }
    do {
        u8* n = *(u8**)(p + 36);
        if (p) {
            func_001c1890(p);
        }
        p = n;
    } while (p);
}

#include "file.hpp"

namespace YS {



u32 FILE::ReadBar(const char*, void*) asm("_ZN2YS4FILE7ReadBarEPKcPv");

extern "C" u32 func_001682b8(...);
extern "C" u32 func_00168be8(...);

u32 FILE::ReadBar(const char* a0, void* a1) {
    u32 s0 = (u32)a1;
    u32 s1 = func_001682b8((u32)a0, (u32)a1);
    if (s1 != 0u) {
        func_00168be8(s0);
    }
    return s1;
}

}  // namespace YS

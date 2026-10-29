#include "../common/types.h"

// Agent R46p_108 (2026-10-29): FUN_00287720 (64 bytes, SLPM_666.75).
// Calls func_002878c8(a0), then obj = *a0 and calls vtable slot 5 on obj, then calls
// the LayFile destructor entry (0x23f848) with a0 + 12.
extern "C" void func_002878c8(void *a0);
extern "C" void func_0023f848(void *a0) asm("_ZN2Tz7LayFileD1Ev");

void func_00287720(void *a0) {
    char *s = (char *)a0;
    func_002878c8(a0);
    void *obj = *(void **)s;
    void (*fn)(void *) = (void (*)(void *))((*(void ***)obj)[5]);
    fn(obj);
    s += 12;
    func_0023f848(s);
    asm volatile("" ::: "memory");
}

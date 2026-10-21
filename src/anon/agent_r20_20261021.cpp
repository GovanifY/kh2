#include "../common/types.h"

// Callees. The linker symbols func_<addr> are referenced as extern "C" names.
extern "C" u32 func_0011ee98(u32 a0, u32 a1, u32 a2, u32 a3);
extern "C" u32 func_0011ef70(u32 a0, u32 a1);
extern "C" u32 func_0011f2f0(u32 a0);

// FUN_0011eef8 (36 bytes, MATCHED with -falign-functions=1 for this object): initializes list
// node a1 with owner a0 (zero at +8 and +12, a0 at +20), then tail-calls func_0011ee98(a0, a1).
// The asm "memory" barriers keep the store order: +8, then +20, then +12. The tail call keeps
// a2 and a3 in place.
u32 func_0011eef8(u32 a0, u32 a1, u32 a2, u32 a3) {
    ((u32*)(u32)a1)[2] = 0u;
    asm volatile("" ::: "memory");
    ((u32*)(u32)a1)[5] = a0;
    asm volatile("" ::: "memory");
    ((u32*)(u32)a1)[3] = 0u;
    return func_0011ee98(a0, a1, a2, a3);
}

// FUN_0011f3b8 (36 bytes, MATCHED with -falign-functions=1 for this object): calls slot 0 of
// the vtable of object a0 with a0 as this, and returns the callee's result. The register pin
// puts the function pointer in t5 ($13), as the original does.
u32 func_0011f3b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1; (void)a2; (void)a3;
    register u32 fn asm("$13");
    u32 vt = *(u32*)(u32)a0;
    fn = *(u32*)(u32)vt;
    return ((u32(*)(u32))fn)(a0);
}

// FUN_0011f3e0 (60 bytes, MATCHED with -falign-functions=1 for this object): walks a list
// headed at a0+8 via func_0011ef70 (given 0 it returns the head, otherwise the next link at
// +4). Each node's owner word at +20 is set to a0. Then it tail-calls func_0011f2f0(a0).
// The goto enters the loop straight at the call, so the store at the top runs with the
// latch's branch-likely (bnezl) delay slot; this gives the original shape without peeling
// the first call.
u32 func_0011f3e0(u32 a0) {
    u32 w = 0u;
    goto call_;
top:
    ((u32*)(u32)w)[5] = a0;
call_:
    w = func_0011ef70(a0, w);
    if (w != 0u) goto top;
    return func_0011f2f0(a0);
}

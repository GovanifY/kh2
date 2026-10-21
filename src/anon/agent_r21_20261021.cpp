#include "../common/types.h"

// Callee: FUN_00124748 (cxx, 64 bytes). Takes the object at a0 and an index, returns an object pointer.
// Its definition in agent_c1_20261019.cpp uses (u8*, s32); the declaration here must match that signature.
u32 func_00124748(u8* a0, s32 a1);

typedef u32 (*vfn1_t)(u32);
typedef u32 (*vfn2_t)(u32, u32);
typedef u32 (*vfn3_t)(u32, u32, u32);

// FUN_00123d10 (44 bytes)
// Code: obj = FUN_00124748(a0, 0); return obj->vtable[3](obj).
// Matching: the vtable pointer is pinned to t6 and the slot to t7, which is what the original
// uses. Without the pins gcc picks v0 for the slot and the bytes differ. The object stays in v0
// and goes to a0 in the jalr delay slot, as in the original. The trailing nop comes from
// -falign-functions=1 (see Makefile), which removes the padding that would follow a 44-byte function.
u32 func_00123d10(u8* a0) {
    register u32 vt asm("$14");     // t6: vtable pointer
    register u32 fn asm("$15");     // t7: slot function pointer
    u32 obj = func_00124748(a0, 0);
    vt = *(u32*)obj;
    fn = *(u32*)(vt + 12);
    return ((vfn1_t)fn)(obj);
}

// FUN_00123d40 (76 bytes)
// Code: saves a1 and a2 in s0 and s1 across the call. obj = FUN_00124748(a0, 0); return
// obj->vtable[4](obj, a1, a2).
// Matching: same pinned vtable (t6) and slot (t7) as FUN_00123d10. The a1 and a2 moves are placed
// by gcc in the original order, in the delay slots of the loads. -falign-functions=1 is set for this
// object so the 76-byte function gets no trailing padding.
u32 func_00123d40(u8* a0, u32 a1, u32 a2) {
    register u32 vt asm("$14");     // t6
    register u32 fn asm("$15");     // t7
    u32 obj = func_00124748(a0, 0);
    vt = *(u32*)obj;
    fn = *(u32*)(vt + 16);
    return ((vfn3_t)fn)(obj, a1, a2);
}

// FUN_00124100 (60 bytes)
// Code: saves a1 in s0 across the call. obj = FUN_00124748(a0, 0); return obj->vtable[11](obj, a1).
// Matching: pinned vtable (t6) and slot (t7). The a1 move goes in the jalr delay slot and the
// object goes to a0 there, as in the original.
u32 func_00124100(u8* a0, u32 a1) {
    register u32 vt asm("$14");     // t6
    register u32 fn asm("$15");     // t7
    u32 obj = func_00124748(a0, 0);
    vt = *(u32*)obj;
    fn = *(u32*)(vt + 44);
    return ((vfn2_t)fn)(obj, a1);
}

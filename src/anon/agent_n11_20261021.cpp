typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_0032b9cc[];
extern u8 D_0032ba20[];
extern u8 D_003a6a50[];

// FUN_00102ed8 (48 bytes): obj = *(u32*)0x32b9cc; vt = obj->vtable; return vt[1](obj, a0).
// Uses pinned registers so the vtable pointer lives in t6 and the slot in t7, as in the original.
u32 func_00102ed8(u32 a0) {
    register u32 vt asm("$14");
    register u32 fn asm("$15");
    u32 obj = *(u32*)D_0032b9cc;
    vt = *(u32*)obj;
    fn = *(u32*)(vt + 4);
    return ((u32(*)(u32, u32))fn)(obj, a0);
}

extern "C" u32 func_00103b38(...);

// FUN_00103500 (80 bytes): if func_00103b38(a0) is non-zero, store a0 into the global at 0x32ba20
// unless it already holds a0. Otherwise store a0 at 0x3a6a50 and -1 at 0x32ba20.
// Plain (non-volatile) pointer accesses let gcc put the -1 store in the delay slot of the
// branch to the shared epilogue, as the original does.
void func_00103500(u32 a0) {
    u32 r = ((u32(*)(u32))func_00103b38)(a0);
    if (r != 0) {
        if (*(u32*)D_0032ba20 != a0) {
            *(u32*)D_0032ba20 = a0;
        }
    } else {
        *(u32*)D_003a6a50 = a0;
        *(u32*)D_0032ba20 = (u32)-1;
    }
}

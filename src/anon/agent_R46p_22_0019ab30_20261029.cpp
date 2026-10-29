typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 func_00195700(u32 a);
extern u8 D_00350000[];

// Agent R46p_22: FUN_0019ab30 (80 bytes), SLPM_666.75.
// Calls FUN_00195700(D_00350000 - 3504). If it returns non-zero, returns 0 (out-of-line block
// that jumps back to the shared return). Otherwise bumps the word at +28 by one, stores the new
// value at +24 as well, and returns 1. The 1 is set in the bnez delay slot.
u32 func_0019ab30(u8 *self) {
    u32 v = func_00195700((u32)&D_00350000[-3504]);
    u32 r = 1;
    if (v != 0) {
        goto zero;
    }
    {
        u32 t = *(u32 *)(self + 28) + 1;
        *(u32 *)(self + 24) = t;
        asm volatile("" ::: "memory");
        *(u32 *)(self + 28) = t;
    }
done:
    return r;
zero:
    r = 0;
    goto done;
}

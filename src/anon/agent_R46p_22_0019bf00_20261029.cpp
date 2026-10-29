typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 func_0017a538(u8 *obj);

// Agent R46p_22: FUN_0019bf00 (80 bytes), SLPM_666.75.
// If bit 7 of the word at +1416 is set and func_0017a538(obj) returns non-zero, returns 1.
// Otherwise returns 1 when bit 20 of the word at +264 is set, else 0.
// The result is pinned to $4 (a0), and the word and mask to $15 and $14 to match the
// original register use.
u32 func_0019bf00(u8 *obj) {
    register u32 r asm("$4");
    if (*(u32 *)(obj + 1416) & 0x80) {
        u32 v = func_0017a538(obj);
        r = 1;
        if (v != 0) {
            goto done;
        }
    }
    {
        register u32 w asm("$15") = *(u32 *)(obj + 264);
        register u32 m asm("$14") = 0x100000;
        asm volatile("" : "+r"(m));
        asm("sltu %0,$0,%1" : "=r"(r) : "r"(w & m));
    }
done:
    return r;
}

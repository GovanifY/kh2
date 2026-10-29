typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 func_001c0cd8(u8 *obj);

// Agent R46p_22: FUN_0019bad8 (64 bytes), SLPM_666.75.
// Returns 0 unless the flag bit 0 of the word at +2040 is set and the flag bit 0 of the word
// at +264 is clear. In that case returns 1 when func_001c0cd8(obj) returns 0, else 0.
u32 func_0019bad8(u8 *obj) {
    u32 r = 0;
    u32 f;
    if ((*(u32 *)(obj + 2040) & 1) == 0) {
        goto done;
    }
    f = *(u32 *)(obj + 264) & 1;
    if (f) {
        goto done;
    }
    r = func_001c0cd8(obj);
    r = (r < 1);
done:
    return r;
}

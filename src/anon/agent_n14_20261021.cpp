typedef unsigned int u32;
typedef unsigned char u8;

extern u32 D_00340eac;
extern u32 D_003a8ea0[];

u32 func_001094e0(u32, u32);
u32 func_00133c60(u32, u32, u32, u32, u32);
u32 func_00133c78(u32, u32, u32, u32, u32);
u32 func_001b9bc8(u32);
u32 func_00112d28(u32);

// FUN_00109788 (96 bytes): if func_001094e0(a1, a1) is zero, calls func_00133c60(a0, a1, 0, 0, 0)
// and returns 1; otherwise returns 0. Written with the test inverted (if (!f) {...; return 1;}
// return 0;) so gcc emits the bnez to a shared "return 0" block, as the original does.
u32 func_00109788(u32 a0, u32 a1) {
    u32 s0 = a0, s1 = a1;
    if (!func_001094e0(a1, a1)) {
        func_00133c60(s0, s1, 0, 0, 0);
        return 1;
    }
    return 0;
}

// FUN_0010cce0 (80 bytes): repeatedly applies func_001b9bc8 to a value (starting at a0) until it
// returns 0. Stops early and returns the value when func_00112d28(value) is non-zero. Returns 0
// if the chain runs out. The while condition is the assignment, so the loop tests v0 directly.
u32 func_0010cce0(u32 a0) {
    u32 s0 = a0;
    while ((s0 = func_001b9bc8(s0)) != 0) {
        if (func_00112d28(s0)) break;
    }
    return s0;
}

// FUN_00109360 (104 bytes): sets the word at D_00340eac to a1 unless it already equals a1. Before
// storing, it reads an 8-byte record at D_003a8ea0 + a1*8. If the first word is non-zero and the
// second is non-zero, it calls func_00133c78(a0, record[0], record[1], 0, 0). The index is written
// as a byte offset (u8 * + a1<<3) so gcc emits the sll and addu the original uses.
void func_00109360(u32 a0, u32 a1) {
    if (D_00340eac == a1) return;
    u32 *e = (u32 *)((u8 *)D_003a8ea0 + (a1 << 3));
    u32 w0 = e[0];
    if (w0 != 0) {
        u32 w1 = e[1];
        if (w1 != 0) func_00133c78(a0, w0, w1, 0, 0);
    }
    D_00340eac = a1;
}

#include "../common/types.h"

extern u8 D_00350000;
extern u8 D_01e352c0;
extern u32 D_0036eaf8[];

// FUN_0019b328 (84 bytes)
// Code: keyed lookup in a packed table of variable-size records. The table
// starts at *(a0+44); the record count is the u16 at (*(a0+8))+8. Each record
// has a u16 key at +0 and a u16 sub-item count at +2; its size is 8 + 12 * count.
// Returns the first record whose key equals a1 (a negative a1 returns the first
// record), or 0 if not found / table empty.
// Written with gotos so p stays in v0 and every exit shares one jr. cnt is a
// copy of the count (empty asm) and tw the constant 12 pinned to t3.
u8* func_0019b328(u8* a0, s32 a1) {
    s32 i = 0;
    s32 n = *(u16*)(*(u8**)(a0 + 8) + 8);
    u8* p = *(u8**)(a0 + 44);
    if (n == 0) goto zero;
    {
    register s32 tw asm("$11") = 12;
    s32 cnt = n;
    __asm__("" : "+r"(tw));
    __asm__("" : "+r"(cnt));
    if (a1 < 0) goto out;
    do {
        if (*(u16*)p == a1) goto out;
        s32 k = *(u16*)(p + 2);
        i++;
        p = p + k * tw + 8;
    } while (i < cnt);
    }
zero:
    p = 0;
out:
    return p;
}

// FUN_001e3590 (96 bytes)
// Code: switch on the byte at a0+168; the odd values 1,3,5,7,9,11 map to
// 1..6 respectively, everything else (including 0) returns 0.
// Guess: converts a state/direction code of an object to a small index.
// The original jump table lives at 0x36eaf8 (D_0036eaf8, original data kept), so
// the dispatch is a computed goto through it instead of a compiler-made switch.
// The empty asm takes every label's address (in reverse order) so the blocks are
// kept and laid out as in the original: 1,2,3,4,5,0,6.
s32 func_001e3590(u8* a0) {
    u32 i = *(u8*)(a0 + 168);
    __asm__ volatile("" :: "X"(&&L6), "X"(&&L0), "X"(&&L5), "X"(&&L4), "X"(&&L3), "X"(&&L2), "X"(&&L1));
    if (i >= 12) goto L0;
    goto *(void*)D_0036eaf8[i];
L1: return 1;
L2: return 2;
L3: return 3;
L4: return 4;
L5: return 5;
L0: return 0;
L6: return 6;
}

// FUN_001b7fd0 (40 bytes)
// Code: if the byte at 0x3511c3 is nonzero return 0; otherwise return
// (byte at 0x3511c2 == 1).
// Guess: "flag A is set and flag B is not" query on two global state bytes.
u32 func_001b7fd0(void) {
    if (*(u8*)((u32)&D_00350000 + 4547) != 0) return 0;
    return *(u8*)((u32)&D_00350000 + 4546) == 1;
}

// FUN_002f42e8 (36 bytes)
// Code: VU0 clamp. Loads the vector at src, takes the per-component max with
// lo (a float arg, broadcast) then the per-component min with hi, stores the
// result to dst. The final sqc2 is a separate asm so the compiler places it in
// the jr delay slot.
void func_002f42e8(f32* dst, f32* src, f32 lo, f32 hi) {
    __asm__ volatile(
        "mfc1 $8,%1\n\t"
        "mfc1 $9,%2\n\t"
        "lqc2 $vf6,0(%0)\n\t"
        "qmtc2 $8,$vf4\n\t"
        "qmtc2 $9,$vf5\n\t"
        "vmaxx.wxyz $vf6,$vf6,$vf4x\n\t"
        "vminix.wxyz $vf6,$vf6,$vf5x\n\t"
        :
        : "r"(src), "f"(lo), "f"(hi)
        : "$8", "$9", "memory");
    __asm__ volatile("sqc2 $vf6,0(%0)" : : "r"(dst) : "memory");
}

// FUN_00306900 (36 bytes)
// Code: initialises the ring-buffer header at 0x1e352c0: stores a0 at +0,
// 0 at +4 (count), and header+16 at +8 and +12 (start and cursor); returns the
// header. (The companion FUN_00306928 advances this ring.)
// The lui is hand-written (with relocations) so the high half sits in v0 while the header pointer
// is pinned to v1, as in the original.
u32* func_00306900(u32 a0) {
    register u32 v asm("$2");
    register u32* g asm("$3");
    __asm__ volatile(
        "lui %0,%%hi(D_01e352c0)\n\t"
        "addiu %1,%0,%%lo(D_01e352c0)\n\t"
        "sw %2,%%lo(D_01e352c0)(%0)"
        : "=r"(v), "=r"(g) : "r"(a0) : "memory");
    a0 = (u32)(g + 4);
    __asm__ volatile("" ::: "memory");
    v = (u32)g;
    g[2] = a0;
    __asm__ volatile("" ::: "memory");
    g[1] = 0;
    __asm__ volatile("" ::: "memory");
    g[3] = a0;
    return (u32*)v;
}

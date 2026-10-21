#include "../common/types.h"

void func_00133f20(void);

// Agent R22 (2026-10-21): three functions from SLPM_666.75, decompiled byte-exact.
// Each comment says what the code does, then gives a guess at its role.
// The guesses are unverified. They are there to help place the function later.

// FUN_00127da0 (36 bytes; this object is built with -falign-functions=1, because the size is not
// a multiple of 8 and the default alignment adds a trailing nop).
// Code: vt = *(a0); fn = vt[0]; return fn(a0). It calls the object's virtual slot 0 with the
// object as `this`, and the callee's return value passes straight through (no move).
// Guess: a "run the first virtual step" wrapper for an object whose first word is its vtable.
// Tricks: the vtable pointer and the slot function are pinned to t6 and t5, matching the original.
u32 func_00127da0(u32 a0) {
    register u32 vt asm("$14") = *(u32*)a0;
    register u32 fn asm("$13") = *(u32*)vt;
    return ((u32 (*)(u32))fn)(a0);
}

// FUN_00132018 (80 bytes)
// Code: p = a0. Loops while p is non-null: a record whose s16 key at +0 is -1 is a link, so p
// advances by the word at (p + 4*w + 4), where w is the word at +4. A key of 0 ends the walk and
// returns p + word(+32) + 4*w. Any other key, or a null p, returns NULL.
// Guess: resolves a record in a linked table, following the -1 link records to the entry.
// Tricks: t7 holds -1 for the key compare (assigned after the null test so the li fills the
// beqz delay slot). The hit path is out of line (goto hit) so GCC emits the beql form.
// The shift and add of the hit path are done in place in t7 with a pinned copy of w.
u8* func_00132018(u8* a0) {
    register u8* p asm("$4") = a0;
    register s32 m1 asm("$15");
    s32 k;
    u8* r;
top:
    if (p == 0) goto nul;
    m1 = -1;
    k = *(s16*)p;
    if (k == m1) goto hit;
    if (k != 0) goto nul;
    {
        u32 t = *(u32*)(p + 32) + (*(u32*)(p + 4) << 2);
        r = p + t;
    }
    goto done;
hit:
    {
        register u32 w asm("$15") = *(u32*)(p + 4);
        asm volatile("" : "+r"(w));
        w = (w << 2) + (u32)p;
        u32 v = *(u32*)(w + 4);
        p = p + v;
    }
    goto top;
nul:
    r = 0;
done:
    return r;
}

// FUN_00134278 (48 bytes)
// Code: calls FUN_00134258(), keeps its return value in s0, calls FUN_00133f20(), then returns the
// saved value. The return value is that of the first call.
// Guess: a "call a helper, run a cleanup, return the helper's result" wrapper.
// Tricks: the first call is a .set noreorder asm block with an explicit nop in its delay slot.
// Plain C let GCC move the s0 save into the first jal's delay slot, while the original has a
// nop there. The result is copied out of $2 into a normal local.
u32 func_00134278(void) {
    register u32 v0 asm("$2");
    asm volatile(".set noreorder\n\tjal func_00134258\n\tnop\n\t.set reorder"
                 : "=r"(v0)
                 :
                 : "$1", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15",
                   "$24", "$25", "$31", "memory");
    u32 r = v0;
    func_00133f20();
    return r;
}

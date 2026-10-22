typedef unsigned int u32;

// Agent X02 (2026-10-22): FUN_0016b7a0, FUN_0016b800, FUN_0016c028 (SLPM_666.75).
// Each comment says what the code does, then the matching notes.

// Callees. func_001b9bc8 is the "next node" step, func_0016bff0 and func_0016a070 are
// per-node getters, func_001c0cd8 is a predicate (YS::OBJ::is_attach, takes the object).
extern "C" u32 func_001b9bc8(u32);
extern "C" u32 func_0016bff0(u32);
extern "C" u32 func_0016a070(u32);
extern "C" u32 func_001c0cd8(u32);

// FUN_0016b7a0 (92 bytes).
// Code: s0 = 0. Loop: s0 = func_001b9bc8(s0). Stop if s0 is 0. If func_0016bff0(s0) equals the
// argument, stop. Returns s0 in both cases, so a miss returns 0.
// Matching: plain C. The single "break" plus "return s0" gives one shared epilogue, and the
// while-assignment loop keeps the original branch shape. The trailing nop is the alignment pad.
u32 func_0016b7a0(u32 a0) {
    u32 s0 = 0;
    while ((s0 = func_001b9bc8(s0)) != 0) {
        if (func_0016bff0(s0) == a0) break;
    }
    return s0;
}

// FUN_0016b800 (92 bytes).
// Code: same loop as FUN_0016b7a0, but the per-node getter is func_0016a070.
// Matching: same shape as FUN_0016b7a0, plain C.
u32 func_0016b800(u32 a0) {
    u32 s0 = 0;
    while ((s0 = func_001b9bc8(s0)) != 0) {
        if (func_0016a070(s0) == a0) break;
    }
    return s0;
}

// FUN_0016c028 (52 bytes).
// Code: s0 = a0. Calls func_001c0cd8(a0). Returns s0 + 1344 if the call returned 0, otherwise
// s0 + 112 (a movz picks the first value). The result is a pointer into the object.
// Matching: the prologue, the call and the s0 = a0 move in the jal delay slot are C, with s0
// pinned to $16 and the result to $2. The tail is a noreorder asm block (addiu t7, ld ra,
// addiu, movz, move, ld s0, jr, addiu sp). Pure C gave ld ra after the movz, the original has
// it between the two addiu. gcc appends a dead epilogue after the asm (noreturn); the
// function is still laid out by its registry size.
u32 func_0016c028(u32 a0) __attribute__((noreturn));
u32 func_0016c028(u32 a0) {
    register u32 s0 asm("$16");
    s0 = a0;
    register u32 v asm("$2");
    v = func_001c0cd8(a0);
    asm volatile(
        ".set\tnoreorder\n\t"
        "addiu\t$15,$16,1344\n\t"
        "ld\t$31,8($29)\n\t"
        "addiu\t$16,$16,112\n\t"
        "movz\t$16,$15,$2\n\t"
        "move\t$2,$16\n\t"
        "ld\t$16,0($29)\n\t"
        "jr\t$31\n\t"
        "addiu\t$29,$29,16\n\t"
        ".set\treorder\n\t"
        : : "r"(s0), "r"(v) : "$15", "memory");
}

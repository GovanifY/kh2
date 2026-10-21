#include "../common/types.h"

// Data address for the end-of-table base of FUN_00101ce0. The entries are read
// at base-4, base-8, ... until the -1 sentinel.
extern u8 D_0037a6e4;

typedef void (*m10_fn_t)(void);

// FUN_00101ce0 (88 bytes)
// Code: walks a table backwards from base-4. Each entry is a function pointer that
// is called, and the walk stops at the -1 sentinel. Saves s0, s1 and ra.
// Guess: runs a global destructor or atexit-style function table.
void func_00101ce0(void) {
    u32* p = (u32*)&D_0037a6e4 - 1;
    while (*p != 0xffffffffu) {
        m10_fn_t f = (m10_fn_t)*p;
        p--;
        f();
    }
}

// FUN_00102180 (76 bytes) and FUN_00102210 (64 bytes): NOT MATCHED, not registered.
//
// Both walk the linked list whose head is the word at D_0038aa40 (0x38aa40); the
// next pointer is at +12 and the type word is at +28. The walk starts at node 0,
// so the first step loads the head and later steps load node->next. The original
// is a bnezl (branch-likely) with the next-load in its delay slot, followed by the
// head load in the fall-through.
//   FUN_00102180(out): stores each node whose type == 1 into out[] and returns the count.
//   FUN_00102210(void): returns the first node whose type == 1, or 0.
// The closest C form (per-object -fno-reorder-blocks) differs in the head-load
// placement and in the layout of the return block, and it has 8 mismatched words.
// Left out of the registry; see the report.

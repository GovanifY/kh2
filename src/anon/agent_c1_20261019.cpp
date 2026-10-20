#include "../common/types.h"

// FUN_00168b88 (96 bytes)
// Searches the 16-byte records that follow a 16-byte header (record count at +4). A record
// matches when its u16 key equals `key` (key == -1 matches any) and its u32 at +4 equals
// `val`. Returns the address of the (skip+1)-th match, or NULL.
struct C1Rec { u16 key; u16 pad; u32 val; u32 x[2]; };
struct C1Hdr { u32 a; s32 n; u32 b[2]; C1Rec r[1]; };

// The cast of a0 is repeated at each use: keeping it in a typed local changes register allocation.
#define C1H ((C1Hdr*)a0)
void* func_00168b88(u8* a0, s32 key, s32 val, s32 skip) {
    s32 i = 0;
    while (i < C1H->n) {
        if (key == -1 || C1H->r[i].key == key) {
            if (C1H->r[i].val == val) {
                if (--skip == -1) return &C1H->r[i];
            }
        }
        i++;
    }
    return 0;
}

// FUN_00124748 (64 bytes)
// base = *(a0+4); walks the zero-terminated u32 list at base+16, returning base + entry for
// index a1 (or the last entry reached; 0 if the list is empty). `w` is pinned to $13 so the
// walk keeps the previous entry in a separate register as the original does.
u32 func_00124748(u8* a0, s32 a1) {
    u8* base = *(u8**)(a0 + 4);
    u32* p = (u32*)(base + 16);
    u32 v = 0;
    u32 f = *p;
    if (f) {
        register u32 w asm("$13") = f;
        do {
            v = (u32)base + w;
            if (--a1 == -1) break;
            f = *++p;
            w = f;
        } while (f);
    }
    return v;
}

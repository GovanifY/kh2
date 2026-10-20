#include "../common/types.h"

// ---------------------------------------------------------------------------
// FUN_00259460 (84 bytes)
// Code: walks 6-byte records {s16 key, a, b} at 0x372B50 until a negative key.
//       On key == arg0 returns b (arg1 != 0) or a, otherwise 11.
// Guess: id -> value lookup with a variant flag.
// Matching tricks: index loop over a struct table (direct table indexing),
// r pinned to $2 so `li v0,11` lands in the bltz delay slot.
struct E259460 { s16 key, a, b; };
extern E259460 D_00372b50[];

s32 func_00259460(s32 a0, u8 a1) {
    register s32 r asm("$2") = 11;
    s32 i = 0;
    while (D_00372b50[i].key >= 0) {
        if (D_00372b50[i].key == a0) {
            if (a1) return D_00372b50[i].b;
            return D_00372b50[i].a;
        }
        i++;
    }
    return r;
}

// ---------------------------------------------------------------------------
// FUN_003015a8 (76 bytes)
// Code: newlib _vsprintf_r(reent, str, fmt, ap): builds a string-FILE on the
//       stack (flags 0x208, p/base = str, w/size = INT_MAX, _data = reent),
//       calls _vfprintf_r, then NUL-terminates at f._p.
struct FakeFile {
    u8* p; int r; int w; s16 flags; s16 file; u8* base; int size; u8 pad[60]; void* data;
};
extern "C" int func_002ffd78(void* reent, FakeFile* f, const char* fmt, void* ap);

int func_003015a8(void* reent, char* str, const char* fmt, void* ap) {
    FakeFile f;
    f.flags = 520;
    f.p = (u8*)str;
    f.base = (u8*)str;
    f.w = 0x7fffffff;
    f.size = 0x7fffffff;
    f.data = reent;
    int r = func_002ffd78(reent, &f, fmt, ap);
    *f.p = 0;
    return r;
}

// ---------------------------------------------------------------------------
// FUN_00315458 (64 bytes) = three functions in one layout entry:
//   0x315458: fn(); func_00315440();            (noreturn: calls fn then the 0x315440 handler)
//   0x315470: func_00315458(*(0x36 77ac));      (noreturn)
//   0x315488: old = *(0x3677a8); *(0x3677a8) = a0; return old;   (global swap)
typedef void (*Fn)();
void func_00315440() __attribute__((noreturn));
void func_00315458(Fn fn) __attribute__((noreturn, section(".text.func_00315458")));
void func_00315470() __attribute__((noreturn, section(".text.func_00315458")));
u32 func_00315488(u32 a0) __attribute__((section(".text.func_00315458")));

void func_00315458(Fn fn) {
    fn();
    func_00315440();
}

void func_00315470() {
    u32* p = (u32*)0x00360000;
    func_00315458((void (*)())p[0x77ac / 4]);
}

u32 func_00315488(u32 a0) {
    u32* p = (u32*)0x00360000;
    u32 old = p[0x77a8 / 4];
    p[0x77a8 / 4] = a0;
    return old;
}

// Layout entry 0x315458 spans all three functions (64 bytes), but the layout
// normalizer copies only the picked symbol's size. Provide a plain symbol named
// func_00315458 (exact registry-name hit) aliasing the first function with size 64.
__asm__(".globl\tfunc_00315458\n"
        "\t.type\tfunc_00315458,@function\n"
        "\t.equ\tfunc_00315458,_Z13func_00315458PFvvE\n"
        "\t.size\tfunc_00315458,64\n");

#include "../common/types.h"

// FUN_00173e38 (44 bytes). Loads the object pointer at +0 of arg0, the float at +8, the word at
// +4 of that object (+768 added), and the word at +4 of arg0. Tail-calls func_00188470(float, p, word).
// Matching: the asm "+f" and "+r" barriers fix the load order (float, then obj[1], then s[1]).
extern "C" void func_00188470(f32, u32, u32);

void func_00173e38(u32 *s) {
    u32 *obj = (u32 *)s[0];
    f32 f = *(f32 *)&s[2];
    asm volatile("" : "+f"(f));
    u32 p = obj[1];
    u32 q = s[1];
    asm volatile("" : "+r"(q));
    func_00188470(f, p + 768, q);
}

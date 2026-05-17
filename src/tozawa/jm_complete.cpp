#include "jm_complete.hpp"

namespace Tz {

extern void* D_0035f620 asm("D_0035f620");
extern void* D_0035f624 asm("D_0035f624");
extern void* D_0035f61c asm("D_0035f61c");
extern s8 D_0035f614 asm("D_0035f614");
extern u32 D_0035f618 asm("D_0035f618");
extern "C" void func_00106420(void*);
extern "C" void func_00106450(void*);
extern "C" void func_00293eb0();
extern "C" void func_00170c00(void*);
extern "C" u32 func_001d9e30(u32);
extern "C" s32 func_002764b0(u32);
extern "C" u32 func_001d9d48(void*);

void JmComplete::Exit() {
    void* t7 = D_0035f620;
    if (t7 != 0) {
        func_00106420(t7);
        D_0035f620 = 0;
    }

    t7 = D_0035f624;
    if (t7 != 0) {
        func_00106450(t7);
        D_0035f624 = 0;
    }

    if (D_0035f614 != 0) {
        func_00293eb0();
    }

    t7 = D_0035f61c;
    if (t7 != 0) {
        func_00170c00(t7);
        D_0035f61c = 0;
    }

    D_0035f614 = 0;
    D_0035f618 = 0;
}

u32 JmComplete::isPuzzleInfoComp(s32 a0) {
    u32 s0 = 0;
    s32 s1 = a0;
    u32 s2 = 1;

L_loop:
    {
        u32 v0 = func_001d9e30(s0);
        if (v0 == 0) {
            goto L_ret;
        }
        s0 = v0;

        v0 = (u32)func_002764b0(*(u8*)(s0 + 4));
        if (s1 >= 0) {
            if ((u32)s1 != v0) {
                goto L_loop;
            }
        }

        v0 = func_001d9d48((void*)s0);
        if (v0 != 0) {
            goto L_loop;
        }

        s2 = 0;
    }

L_ret:
    return s2;
}

}  // namespace Tz

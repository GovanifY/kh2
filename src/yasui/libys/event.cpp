#include "types.h"

namespace YS {

extern u32 D_0035037c asm("D_0035037c");

class EVENT {
public:
    static void ContinueControlOff();
    static u32 IsExec();
    static void* GetImage();
};

void EVENT::ContinueControlOff() {
    u32 t7 = (u32)(0x0035u << 16);
    u32 t6 = *(u32*)((u32)t7 + (s32)(892));
    if (t6 != 0u) {
        u32 t7v = *(u32*)((u32)t6 + (s32)(0));
        t7v = (u32)(t7v | 0x0020u);
        *(u32*)((u32)t6 + (s32)(0)) = t7v;
    }
}

u32 EVENT::IsExec() { return (D_0035037c != 0); }

void* EVENT::GetImage() {
    u32 p = D_0035037c;
    return (void*)((s32)p + 148);
}

}  // namespace YS

#include "types.h"

namespace dk {

extern u32 D_0035f5c0 asm("D_0035f5c0");
extern u32 D_0034b278 asm("D_0034b278");
extern u32 D_0034b27c asm("D_0034b27c");
extern "C" u32 func_00103eb0();
extern "C" void func_00102670(u32, u32);
extern "C" void func_0015df98();

class Glow {
public:
    static void menuDestroy();
};

void Glow::menuDestroy() {
    if (D_0035f5c0 == 0) {
        return;
    }

    u32 v0 = func_00103eb0();
    func_00102670(*(u32*)(v0 + 4), D_0035f5c0);
    func_0015df98();

    D_0035f5c0 = 0;
    D_0034b278 = D_0034b27c;
}

}  // namespace dk

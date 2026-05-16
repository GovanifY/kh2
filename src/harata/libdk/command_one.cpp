#include "types.h"

namespace dk {

extern u8 D_00348000 asm("D_00348000");
extern u8 D_0034805c asm("D_0034805c");

class COMMAND_ONE {
public:
    void update();
};

extern "C" u32 func_00138840(...);
extern "C" u32 func_0023acd8(...);
void COMMAND_ONE::update() {
    u32 s0 = (u32)this;
    func_00138840((u32)this);
    if (*(s32*)((u32)this + (s32)(780)) >= *(s32*)((u32)&D_0034805c + (s32)(0))) {
        func_0023acd8((u32)((s32)s0 + (436)));
        return;
    }
}

}  // namespace dk

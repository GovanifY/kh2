#include "../common/types.h"

extern u8 D_01da0000[];
extern "C" void func_001e65d0(void);
extern "C" void func_001e6630(void);
extern "C" void func_0021c9b0(void);

void func_001e6648(void) {
    func_001e65d0();
    func_001e6630();
    func_0021c9b0();
    *(u32*)&D_01da0000[-6476] = 0;
    *(u8*)&D_01da0000[-6480] = 0;
}

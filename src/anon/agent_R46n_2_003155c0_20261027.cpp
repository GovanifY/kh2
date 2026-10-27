#include "../common/types.h"

extern u8 D_00360000[];
extern u8 D_003785f8[];
extern "C" void func_00316d18(u32 a0, u32 a1);
extern "C" void func_00315440(void) __attribute__((noreturn));

// FUN_003155c0 (40 bytes): calls FUN_00316d18(0x003785f8, word at (*(D_00360000 + 23624)) + 12), then the noreturn FUN_00315440().
void func_003155c0(void) {
    u32* t6 = *(u32**)(D_00360000 + 23624);
    func_00316d18((u32)D_003785f8, t6[3]);
    func_00315440();
}

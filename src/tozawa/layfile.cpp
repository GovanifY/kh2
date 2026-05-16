#include "types.h"

namespace Tz {
extern "C" u32 func_00292630();
extern "C" void func_002a1c68();
extern u8* D_0035f5d4 asm("D_0035f5d4");
extern "C" u32 func_00293de8(u32);
extern "C" void func_00293bd0(u32, u32, u32);
extern "C" void func_002925c0();
extern u8 D_0035f5e1 asm("D_0035f5e1");
class LayFile {
public:
    static void free();
    s32 getFileAddress() const;
};

struct FileAddressLayout {
    char _pad0[4];
    s32 fileAddress;
};


void LayFile::free() {
    if (func_00292630() != 0) {
        return;
    }

    func_002a1c68();
    u32 r = func_00293de8((s8)D_0035f5d4[2]);
    func_00293bd0(4, r, 0);
    func_002925c0();
    D_0035f5e1 = 1;
}

s32 LayFile::getFileAddress() const {
    return reinterpret_cast<const FileAddressLayout*>(this)->fileAddress;
}
}  // namespace Tz

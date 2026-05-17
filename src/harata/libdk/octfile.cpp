#include "octfile.hpp"

namespace dk {


struct OctCollFileLayout {
    char _pad0[60];
    u16* hitCollPolygonTableAddress;
};

u32 OctCollFile::getAttr(u16 idx) {
    u32 r14 = *(u32*)((u32)this + 12);
    u32 r5 = ((u32)idx & 0xffffu) << 4;
    u32 r2 = *(u32*)((u32)this + 20);
    r14 = r14 + r5;
    u32 r15 = (u32)(*(u16*)((u32)r14 + 14));
    r15 = r15 << 2;
    r2 = r2 + r15;
    return r2;
}

void OctCollFile::sethitCollPolygonTableAddress(u16* v) {
    reinterpret_cast<OctCollFileLayout*>(this)->hitCollPolygonTableAddress = v;
}
}  // namespace dk

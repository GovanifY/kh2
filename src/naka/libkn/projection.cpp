#include "projection.hpp"

namespace kn {


Projection::~Projection() {}
u32 Projection::getViewClipGsMatrix() { return (u32)((s32)this + (192)); }
f32 Projection::getFOV(WorH a1) const {
    u32 p = (u32)a1;
    p <<= 2;
    p += (u32)this;
    return *(f32*)(p + 0x44);
}
f32 Projection::getScreenZ() const {
    return reinterpret_cast<const ProjectionLayout*>(this)->screenZ;
}
}  // namespace kn

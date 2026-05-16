#include "types.h"

namespace kn {
class Projection {
public:
    enum WorH { WOR_H0 = 0 };
    ~Projection();
    u32 getViewClipGsMatrix();
    f32 getFOV(WorH) const;
    f32 getScreenZ() const;
};

struct ProjectionLayout {
    char _pad0[64];
    f32 screenZ;
};

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

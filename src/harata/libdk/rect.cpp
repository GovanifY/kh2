#include "rect.hpp"

namespace dk {
void RectParamBase::setXY(s16 x, s16 y) {
    reinterpret_cast<RectParamBaseLayout*>(this)->x = x;
    reinterpret_cast<RectParamBaseLayout*>(this)->y = y;
}
void RectParamBase::setZ(u32 v) { reinterpret_cast<RectParamBaseLayout*>(this)->z = v; }
void RectBase::setGsPrim(u64 v) { reinterpret_cast<RectBaseGsPrimLayout*>(this)->gs_prim = v; }
void RectBase::setGsFrame(u64 v) { reinterpret_cast<RectBaseGsFrameLayout*>(this)->gs_frame = v; }
void RectBase::setGsZbuf(u64 v) { reinterpret_cast<RectBaseGsZbufLayout*>(this)->gs_zbuf = v; }
void RectBase::setGsTest(u64 v) { reinterpret_cast<RectBaseGsTestLayout*>(this)->gs_test = v; }
void RectBase::setGsAlpha(u64 v) { reinterpret_cast<RectBaseGsAlphaLayout*>(this)->gs_alpha = v; }
void RectBase::setGsTex0(u64 v) { reinterpret_cast<RectBaseGsTex0Layout*>(this)->gs_tex0 = v; }
void RectBase::setGsTex1(u64 v) { reinterpret_cast<RectBaseGsTex1Layout*>(this)->gs_tex1 = v; }
}  // namespace dk

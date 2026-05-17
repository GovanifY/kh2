#include "rect.hpp"

namespace dk {
struct RectParamBaseLayout {
    char _pad0[8];
    s16 x;
    s16 y;
    u32 z;
};

struct RectBaseGsPrimLayout {
    char _pad0[192];
    u64 gs_prim;
};

struct RectBaseGsFrameLayout {
    char _pad0[64];
    u64 gs_frame;
};

struct RectBaseGsZbufLayout {
    char _pad0[80];
    u64 gs_zbuf;
};

struct RectBaseGsTestLayout {
    char _pad0[128];
    u64 gs_test;
};

struct RectBaseGsAlphaLayout {
    char _pad0[144];
    u64 gs_alpha;
};

struct RectBaseGsTex0Layout {
    char _pad0[96];
    u64 gs_tex0;
};

struct RectBaseGsTex1Layout {
    char _pad0[112];
    u64 gs_tex1;
};

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

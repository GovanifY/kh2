#pragma once

#include "../../common/types.h"

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

class RectParamBase {
public:
    void setXY(s16 x, s16 y);
    void setZ(u32 v);
};

class RectBase {
public:
    void setGsPrim(u64 v);
    void setGsFrame(u64 v);
    void setGsZbuf(u64 v);
    void setGsTest(u64 v);
    void setGsAlpha(u64 v);
    void setGsTex0(u64 v);
    void setGsTex1(u64 v);
};

}  // namespace dk

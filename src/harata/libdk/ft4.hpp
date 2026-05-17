#pragma once

#include "../../common/types.h"

namespace dk {

struct Ft4BaseLayout {
    char _pad0[96];
    u64 gs_tex0;
    char _pad1[24];
    u64 gs_test;
    char _pad2[56];
    u64 gs_prim;
};

class Ft4Base {
public:
    void setRot(f32 v);
    void setCenterXY(s32 x, s32 y);
    void setGsTex0(u64 v);
    void setGsTest(u64 v);
    void setGsPrim(u64 v);
};

}  // namespace dk

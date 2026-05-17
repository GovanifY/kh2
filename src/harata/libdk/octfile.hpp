#pragma once

#include "../../common/types.h"

namespace dk {

struct OctCollFileLayout {
    char _pad0[60];
    u16* hitCollPolygonTableAddress;
};

    class OctCollFile {
    public:
        u32 getAttr(u16);
        void sethitCollPolygonTableAddress(u16* v);
    };

}  // namespace dk

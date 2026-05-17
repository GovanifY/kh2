#pragma once

#include "../../common/types.h"

namespace dk {

    class OctCollFile {
    public:
        u32 getAttr(u16);
        void sethitCollPolygonTableAddress(u16* v);
    };

}  // namespace dk


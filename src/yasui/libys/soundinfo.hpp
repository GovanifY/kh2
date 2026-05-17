#pragma once

#include "../../common/types.h"

class AREA;

namespace YS {

    class SOUNDINFO {
    public:
     void Init(void);
     void SetArea(AREA* a0);
     u32 Get(void);
    };

}  // namespace YS


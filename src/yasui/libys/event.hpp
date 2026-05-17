#pragma once

#include "../../common/types.h"

namespace YS {

    class EVENT {
    public:
        static void ContinueControlOff();
        static u32 IsExec();
        static void* GetImage();
    };

}  // namespace YS


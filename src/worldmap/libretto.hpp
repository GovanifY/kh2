#pragma once

#include "../common/types.h"

namespace worldmap {

    class Libretto {
    public:
        static bool isExec();
        void leaveAllObj();
        void waitFlush();
        static u32 isExistObj();
    };

}  // namespace worldmap


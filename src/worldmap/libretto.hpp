#ifndef KH2_SRC_WORLDMAP_LIBRETTO_HPP
#define KH2_SRC_WORLDMAP_LIBRETTO_HPP

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

#endif

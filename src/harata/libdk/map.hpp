#ifndef KH2_SRC_HARATA_LIBDK_MAP_HPP
#define KH2_SRC_HARATA_LIBDK_MAP_HPP

#include "../../common/types.h"

namespace dk {

    class Map {
    public:
        static u32 isPaxExist();
        static void* getPax();
    };

}  // namespace dk

#endif

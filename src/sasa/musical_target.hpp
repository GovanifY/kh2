#ifndef KH2_SRC_SASA_MUSICAL_TARGET_HPP
#define KH2_SRC_SASA_MUSICAL_TARGET_HPP

#include "../common/types.h"

namespace sa {

    class MUSICAL_TARGET {
    public:
        static void* getImage();
        static u32 init();
        static void free();
    };

}  // namespace sa

#endif

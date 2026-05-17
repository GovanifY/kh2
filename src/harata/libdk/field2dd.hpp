#ifndef KH2_SRC_HARATA_LIBDK_FIELD2DD_HPP
#define KH2_SRC_HARATA_LIBDK_FIELD2DD_HPP

#include "../../common/types.h"

namespace dk {

    class Field2DD {
    public:
        static void readConfigCommand();
        static void ensureMonochrome();
        static u32 getImd(s32);
        static u32 getSqd(s32);
        static u32 getSqdCommand();
    };

}  // namespace dk

#endif

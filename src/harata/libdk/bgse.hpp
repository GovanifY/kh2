#ifndef KH2_SRC_HARATA_LIBDK_BGSE_HPP
#define KH2_SRC_HARATA_LIBDK_BGSE_HPP

#include "../../common/types.h"

namespace dk {

    class BGSE {
    public:
        static void clearOff();
        static void free(void*);
    };

}  // namespace dk

#endif

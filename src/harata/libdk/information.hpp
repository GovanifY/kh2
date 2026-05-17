#ifndef KH2_SRC_HARATA_LIBDK_INFORMATION_HPP
#define KH2_SRC_HARATA_LIBDK_INFORMATION_HPP

#include "../../common/types.h"

namespace dk {

    class INFORMATION_WINDOW {
    public:
        void close();
        s32 getMessage();
    };

}  // namespace dk

#endif

#ifndef KH2_SRC_HARATA_LIBDK_LOCKON_HPP
#define KH2_SRC_HARATA_LIBDK_LOCKON_HPP

#include "../../common/types.h"

namespace dk {

    class LockOn {
    public:
        static void* getYIImage();
        void show();
    };

}  // namespace dk

#endif

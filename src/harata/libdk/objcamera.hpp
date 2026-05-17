#ifndef KH2_SRC_HARATA_LIBDK_OBJCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_OBJCAMERA_HPP

#include "../../common/types.h"

namespace dk {

class ObjCamera {
public:
    static ObjCamera* getInstance();
    static s32 getMode();
    void initRadius();
    void initLockRadius();
};

}  // namespace dk

#endif

#ifndef KH2_SRC_HARATA_LIBDK_LIGHTCYCLECAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_LIGHTCYCLECAMERA_HPP

#include "../../common/types.h"

class ObjCamera;

namespace dk {

    class LightCycleCamera {
    public:
     void update(ObjCamera* a0);
     s32 create(void);
    };

}  // namespace dk

#endif

#ifndef KH2_SRC_HARATA_LIBDK_DANGLECAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_DANGLECAMERA_HPP

#include "../../common/types.h"

class ObjCamera;
class PAD;

namespace dk {

    class DangleCamera {
    public:
     void calcEyeTarget(ObjCamera* a0);
     void control(PAD* a0, ObjCamera* a1);
     void update(ObjCamera* a0);
     s32 create(void);
     s32 destroy(void);
    };

}  // namespace dk

#endif

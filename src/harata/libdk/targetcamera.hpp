#ifndef KH2_SRC_HARATA_LIBDK_TARGETCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_TARGETCAMERA_HPP

#include "../../common/types.h"

class FVector;
class ObjCamera;
class PAD;
class TARGET;

namespace dk {

    class TargetCamera {
    public:
     u64 checkVisibleObject(FVector* a0, int* a1);
     void control(PAD* a0, ObjCamera* a1);
     void updateCollision(ObjCamera* a0);
     void checkEyeCollision(ObjCamera* a0);
     void updateTargetCamera(ObjCamera* a0, FVector* a1, f32 a2);
     void update(ObjCamera* a0);
     void change(TARGET* a0);
     void create(TARGET* a0);
     s32 destroy(void);
    };

}  // namespace dk

#endif

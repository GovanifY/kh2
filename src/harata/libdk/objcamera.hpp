#pragma once

#include "../../common/types.h"

namespace dk {

struct ObjCameraLayout {
    char _pad0[72];
    f32 radius;
    char _pad1[124];
    f32 defaultRadius;
    f32 defaultLockRadius;
};

class ObjCamera {
public:
    static ObjCamera* getInstance();
    static s32 getMode();
    void initRadius();
    void initLockRadius();
};

}  // namespace dk

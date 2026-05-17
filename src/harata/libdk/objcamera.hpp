#pragma once

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


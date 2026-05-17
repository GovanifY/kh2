#pragma once

#include "../../common/types.h"

class BINARC;
class CODE;
class PAX;

namespace YS {

    class MISSION_CAMERA {
    public:
     void set(BINARC* a0, CODE* a1);
     void start(PAX* a0, bool a1);
    };

}  // namespace YS


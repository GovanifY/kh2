#ifndef KH2_SRC_YASUI_LIBYS_MISSIONCAMERA_HPP
#define KH2_SRC_YASUI_LIBYS_MISSIONCAMERA_HPP

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

#endif

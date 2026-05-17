#ifndef KH2_SRC_HARATA_LIBDK_CAMERACONFIG_HPP
#define KH2_SRC_HARATA_LIBDK_CAMERACONFIG_HPP

#include "../../common/types.h"

class PAD;

namespace dk {

    class CameraConfig {
    public:
     bool isZoomIn(PAD* a0);
     bool isZoomOut(PAD* a0);
     bool isLeft(PAD* a0);
     bool isRight(PAD* a0);
     u64 isManual(PAD* a0);
    };

}  // namespace dk

#endif

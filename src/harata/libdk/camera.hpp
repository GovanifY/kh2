#ifndef KH2_SRC_HARATA_LIBDK_CAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_CAMERA_HPP

#include "../../common/types.h"

struct TASK;

namespace dk {

class Camera {
public:
    void setNoKick();
    void after1CameraTask(TASK*);
    void multiAfter2CameraTask(TASK*);
};

}  // namespace dk

#endif

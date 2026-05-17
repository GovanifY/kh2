#ifndef KH2_SRC_WORLDMAP_CAMERA_HPP
#define KH2_SRC_WORLDMAP_CAMERA_HPP

#include "../common/types.h"

namespace worldmap {

class Camera {
public:
    u64 update();
    void sleep();
    void initialize();
    ~Camera();
};

}  // namespace worldmap

#endif

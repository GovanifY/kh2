#ifndef KH2_SRC_WORLDMAP_CLOSEUPCAMERA_HPP
#define KH2_SRC_WORLDMAP_CLOSEUPCAMERA_HPP

#include "../common/types.h"

class FVector;
class TARGET;

namespace worldmap {

class CloseUpCamera {
public:
    ~CloseUpCamera();
    void start(TARGET*, FVector*, f32);
    void end();
    void update();
    CloseUpCamera(CloseUpCamera*, TARGET*, FVector*, f32);
};

}  // namespace worldmap

#endif

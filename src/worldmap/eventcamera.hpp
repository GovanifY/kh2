#ifndef KH2_SRC_WORLDMAP_EVENTCAMERA_HPP
#define KH2_SRC_WORLDMAP_EVENTCAMERA_HPP

#include "../common/types.h"

namespace worldmap {

class FVector;

class EventCamera {
public:
    void update(void);
    void start(FVector* a0, FVector* a1, f32 a2);
    EventCamera(EventCamera* a0, FVector* a1, FVector* a2, f32 a3);
    ~EventCamera();
};

}  // namespace worldmap

#endif

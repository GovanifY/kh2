#ifndef KH2_SRC_WORLDMAP_LOCKONCAMERA_HPP
#define KH2_SRC_WORLDMAP_LOCKONCAMERA_HPP

#include "../common/types.h"

class FVector;
class PLAYER;
class TARGET;

namespace worldmap {

class LockOnCamera {
public:
    ~LockOnCamera();
    bool update();
    void start(PLAYER*, TARGET*);
    void end();
    LockOnCamera(LockOnCamera*, PLAYER*, TARGET*);
    void getEyeAt(FVector*, FVector*);
};

}  // namespace worldmap

#endif

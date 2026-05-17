#pragma once

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


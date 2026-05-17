#pragma once

#include "../common/types.h"

class PAD;
class Player;

namespace worldmap {

class ObjCamera {
public:
    ~ObjCamera();
    u64 update();
    void start(Player*, PAD*);
    u32 getCurrent();
    ObjCamera(ObjCamera*, Player*, PAD*);
};

}  // namespace worldmap


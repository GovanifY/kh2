#ifndef KH2_SRC_WORLDMAP_OBJCAMERA_HPP
#define KH2_SRC_WORLDMAP_OBJCAMERA_HPP

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

#endif

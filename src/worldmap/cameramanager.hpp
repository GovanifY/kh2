#ifndef KH2_SRC_WORLDMAP_CAMERAMANAGER_HPP
#define KH2_SRC_WORLDMAP_CAMERAMANAGER_HPP

#include "../common/types.h"

namespace worldmap {

class CameraManager {
public:
    static void* get();
    void removeAll();
};

}  // namespace worldmap

#endif

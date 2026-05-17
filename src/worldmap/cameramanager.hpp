#pragma once

#include "../common/types.h"

namespace worldmap {

class CameraManager {
public:
    static void* get();
    void removeAll();
};

}  // namespace worldmap


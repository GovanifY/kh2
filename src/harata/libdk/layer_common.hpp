#pragma once

#include "../../common/types.h"

class MapFile;

namespace dk {

    class LAYER_COMMON {
    public:
     void init(MapFile* a0);
     void finalizer(void);
     void on(void);
     void off(void);
    };

}  // namespace dk


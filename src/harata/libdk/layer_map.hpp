#pragma once

#include "../../common/types.h"

class MapFile;

namespace dk {

    class LAYER_MAP {
    public:
     void init(MapFile* a0);
     void finalizer(void);
     void on(void);
     void off(void);
    };

}  // namespace dk


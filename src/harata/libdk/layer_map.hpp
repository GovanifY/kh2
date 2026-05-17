#ifndef KH2_SRC_HARATA_LIBDK_LAYER_MAP_HPP
#define KH2_SRC_HARATA_LIBDK_LAYER_MAP_HPP

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

#endif

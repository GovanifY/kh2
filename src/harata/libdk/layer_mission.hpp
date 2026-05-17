#ifndef KH2_SRC_HARATA_LIBDK_LAYER_MISSION_HPP
#define KH2_SRC_HARATA_LIBDK_LAYER_MISSION_HPP

#include "../../common/types.h"

namespace dk {

    class LAYER_MISSION {
    public:
     void init(void);
     void finalizer(void);
     void on(void);
     void off(void);
    };

}  // namespace dk

#endif

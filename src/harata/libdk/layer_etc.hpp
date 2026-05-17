#ifndef KH2_SRC_HARATA_LIBDK_LAYER_ETC_HPP
#define KH2_SRC_HARATA_LIBDK_LAYER_ETC_HPP

#include "../../common/types.h"

namespace dk {

    class LAYER_ETC {
    public:
     void init(void);
     void finalizer(void);
     void on(void);
     void off(void);
    };

}  // namespace dk

#endif

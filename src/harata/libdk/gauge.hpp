#ifndef KH2_SRC_HARATA_LIBDK_GAUGE_HPP
#define KH2_SRC_HARATA_LIBDK_GAUGE_HPP

#include "../../common/types.h"

namespace dk {

class GAUGE {
public:
    void init();
};

class GAUGE_DRAW {
public:
    static void* getImage();
    static u32 getFriend1();
    static void checkAlertOff();
};

class GAUGE_PARTY {
public:
    u32 getGroup();
    u32 isAlertStart();
    u32 isAlertEnd();
};

}  // namespace dk

#endif

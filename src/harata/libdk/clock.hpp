#ifndef KH2_SRC_HARATA_LIBDK_CLOCK_HPP
#define KH2_SRC_HARATA_LIBDK_CLOCK_HPP

#include "../../common/types.h"

namespace dk {

    class Clock {
    public:
        static u32 getPlayTimeToHMSMS(u32&, u32&, u32&, u32&);
    };

}  // namespace dk

#endif

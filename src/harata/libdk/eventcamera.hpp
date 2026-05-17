#ifndef KH2_SRC_HARATA_LIBDK_EVENTCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_EVENTCAMERA_HPP

#include "../../common/types.h"

namespace dk {

class EventCamera {
public:
    void resetEventInterpolation(void);
    void start(void);
    void end(bool a0);
    void getEventEye(void);
    void getEventAt(void);
    double getEventFov(void);
    double getEventRoll(void);
    u8 isEventInterpolation(void);
};

}  // namespace dk

#endif

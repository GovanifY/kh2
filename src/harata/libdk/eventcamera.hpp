#pragma once

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


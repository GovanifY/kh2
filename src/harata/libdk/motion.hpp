#ifndef KH2_SRC_HARATA_LIBDK_MOTION_HPP
#define KH2_SRC_HARATA_LIBDK_MOTION_HPP

#include "types.h"

namespace dk {

class BINARC;
class BgObj;

class Motion {
public:
    void setBoundingBox(void);
    Motion(Motion* a0, BgObj* a1);
    ~Motion();
    void setBoms(BINARC* a0);
    void calc(void);
    void start(s32 a0, f32 a1);
    void addTime(f32 a0);
};

}  // namespace dk

#endif

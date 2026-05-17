#ifndef KH2_SRC_HARATA_LIBDK_POINTLIGHT_HPP
#define KH2_SRC_HARATA_LIBDK_POINTLIGHT_HPP

#include "../../common/types.h"

class ALLOCATOR;
class FVector;
class uchar;

namespace dk {

    class PointLight {
    public:
     void setVisibleGroup(uchar a0);
     void draw(void);
     void init(void* a0, u64 a1, ALLOCATOR* a2);
     void exit(void);
     void setHideGroup(uchar a0);
     void getColor(uchar* a0, FVector* a1);
     void drawSphereAll(void);
     u64 isExistGroup(s32 a0);
    };

}  // namespace dk

#endif

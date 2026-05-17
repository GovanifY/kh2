#ifndef KH2_SRC_HARATA_LIBDK_CANNONCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_CANNONCAMERA_HPP

#include "../../common/types.h"

class OBJ;
class ObjCamera;

namespace dk {

    class CannonCamera {
    public:
     void update(ObjCamera* a0);
     s32 create(OBJ* a0);
    };

}  // namespace dk

#endif

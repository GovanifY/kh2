#ifndef KH2_SRC_HARATA_LIBDK_REACTIONCAMERA_HPP
#define KH2_SRC_HARATA_LIBDK_REACTIONCAMERA_HPP

#include "../../common/types.h"

class ObjCamera;
class TARGET;

namespace dk {

    class ReactionCamera {
    public:
     s32 update(ObjCamera* a0);
     s32 create(TARGET* a0);
    };

}  // namespace dk

#endif

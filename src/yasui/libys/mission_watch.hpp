#ifndef KH2_SRC_YASUI_LIBYS_MISSION_WATCH_HPP
#define KH2_SRC_YASUI_LIBYS_MISSION_WATCH_HPP

#include "../../common/types.h"

class MISSION_WATCH;

namespace YS {

    class MISSION_WATCH {
    public:
     void init(s32 a0);
     void set_param(s32 a0, s32 a1, s32 a2);
     void activate(void);
     void deactivate(void);
     ~MISSION_WATCH();
    };

}  // namespace YS

#endif

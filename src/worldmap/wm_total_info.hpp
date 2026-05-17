#ifndef KH2_SRC_WORLDMAP_WM_TOTAL_INFO_HPP
#define KH2_SRC_WORLDMAP_WM_TOTAL_INFO_HPP

#include "../common/types.h"

namespace dk {

    class WM_TOTAL_INFO {
    public:
        s32 getBaseNum(s32);
        void fadeout();
        void exit();
    };

}  // namespace dk

#endif

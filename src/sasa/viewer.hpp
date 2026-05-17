#ifndef KH2_SRC_SASA_VIEWER_HPP
#define KH2_SRC_SASA_VIEWER_HPP

#include "../common/types.h"

struct TASK;

namespace sa {

    class VIEWER {
    public:
     void hideAllTask(TASK* a0);
     void callMusicalSe(s32 a0);
     void checkMusicalhideAll(void);
     void isMusicalInputAllOk(void);
    };

}  // namespace sa

#endif

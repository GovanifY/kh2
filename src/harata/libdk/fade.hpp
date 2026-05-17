#ifndef KH2_SRC_HARATA_LIBDK_FADE_HPP
#define KH2_SRC_HARATA_LIBDK_FADE_HPP

#include "../../common/types.h"

class Fade;

namespace dk {

    class Fade {
    public:
     void fadeSetup(u32 a0);
     void update(void);
     void fadeOut(u32 a0, bool a1);
     void fadeIn(u32 a0, bool a1);
     ~Fade();
    };

}  // namespace dk

#endif

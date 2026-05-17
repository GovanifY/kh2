#ifndef KH2_SRC_HARATA_LIBDK_BATTLEPAUSE_HPP
#define KH2_SRC_HARATA_LIBDK_BATTLEPAUSE_HPP

#include "../../common/types.h"

struct TASK;

namespace dk {

    class BattlePause {
    public:
     void init(void);
     void pause_thread(TASK* a0);
    };

}  // namespace dk

#endif

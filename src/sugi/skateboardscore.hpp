#ifndef KH2_SRC_SUGI_SKATEBOARDSCORE_HPP
#define KH2_SRC_SUGI_SKATEBOARDSCORE_HPP

#include "../common/types.h"

struct TASK;

namespace Ts {

    class SKATEBOARDSCORE {
    public:
     void add_count(s32 a0, f32 a1);
     void stop(void);
     void ExecTask(TASK* a0);
     void ExecFinalize(TASK* a0);
    };

}  // namespace Ts

#endif

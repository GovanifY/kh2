#ifndef KH2_SRC_YASUI_LIBYS_BLUR_HPP
#define KH2_SRC_YASUI_LIBYS_BLUR_HPP

#include "../../common/types.h"

struct TASK;

namespace YS {

    class BLUR {
    public:
     void stop(void);
     void exec(void);
     void Exec(TASK* a0);
     void init(void);
     void start(f32 a0);
     void fadeout(f32 a0);
     void Init(void);
    };

}  // namespace YS

#endif

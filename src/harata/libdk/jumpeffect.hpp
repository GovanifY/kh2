#ifndef KH2_SRC_HARATA_LIBDK_JUMPEFFECT_HPP
#define KH2_SRC_HARATA_LIBDK_JUMPEFFECT_HPP

#include "../../common/types.h"

struct TASK;

namespace dk {

    class JumpEffect {
    public:
     void outInit(void);
     void inInit(void);
     void outFinal(void);
     void inFinal(void);
     void outInit_task(TASK* a0);
     s32 in(void);
     u8 outIsExist(void);
     void init(void);
     void outClear(void);
    };

}  // namespace dk

#endif

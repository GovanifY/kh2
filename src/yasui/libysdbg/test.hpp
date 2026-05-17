#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_HPP

#include "../../common/types.h"

struct TASK;

namespace YS {

    class TEST {
    public:
     void Init(void);
     void Test(s32 a0);
     void Thread(TASK* a0);
    };

}  // namespace YS

#endif

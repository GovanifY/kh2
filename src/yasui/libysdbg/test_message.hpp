#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_MESSAGE_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_MESSAGE_HPP

#include "../../common/types.h"

struct TASK;

namespace YS {

    class TEST_MESSAGE {
    public:
     void Open(s32 a0);
     void ExecThread(TASK* a0);
     void Init(void);
    };

}  // namespace YS

#endif

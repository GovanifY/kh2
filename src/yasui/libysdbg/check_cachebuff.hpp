#ifndef KH2_SRC_YASUI_LIBYSDBG_CHECK_CACHEBUFF_HPP
#define KH2_SRC_YASUI_LIBYSDBG_CHECK_CACHEBUFF_HPP

#include "../../common/types.h"

class AREA;
struct TASK;

namespace YS {

    class CHECK_CACHEBUFF {
    public:
     void Init(void);
     u64 IsExec(void);
     void Start(s32 a0);
     void CheckAllSet(TASK* a0, AREA* a1);
     void CheckAllAreaThread(TASK* a0);
     void CheckAllSetThread(TASK* a0);
     void CheckThreadFinalizer(TASK* a0);
     void CheckProgress(TASK* a0);
     void RepeatThread(TASK* a0);
    };

}  // namespace YS

#endif

#ifndef KH2_SRC_YASUI_LIBYS_CHANGEIN_HPP
#define KH2_SRC_YASUI_LIBYS_CHANGEIN_HPP

#include "../../common/types.h"

class CHANGEIN;
class FRIEND;
class OBJ;
struct TASK;

namespace YS {

    class CHANGEIN {
    public:
     void exec(TASK* a0);
     CHANGEIN(CHANGEIN* a0, s32 a1, FRIEND* a2, s32 a3);
     void Thread(TASK* a0);
     void ThreadFinalizer(TASK* a0);
     void Start(OBJ* a0);
     void Stop(void);
     u64 CanExec(void);
    };

}  // namespace YS

#endif

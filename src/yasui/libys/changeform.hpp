#ifndef KH2_SRC_YASUI_LIBYS_CHANGEFORM_HPP
#define KH2_SRC_YASUI_LIBYS_CHANGEFORM_HPP

#include "../../common/types.h"

class CHANGEFORM;
class SORA;
struct TASK;

namespace YS {

    class CHANGEFORM {
    public:
     void End(void);
     CHANGEFORM(CHANGEFORM* a0, SORA* a1, s32 a2, u32 a3);
     ~CHANGEFORM();
     void exec(TASK* a0);
     void Thread(TASK* a0);
     void ThreadFinalizer(TASK* a0);
     void RecovTask(TASK* a0);
     void Start(SORA* a0, s32 a1);
     void Capture(SORA* a0, u32 a1);
     void CaptureEnd(SORA* a0);
     void Dead(SORA* a0);
     u64 CanCaptureForm(void);
    };

}  // namespace YS

#endif

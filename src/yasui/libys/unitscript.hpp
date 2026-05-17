#ifndef KH2_SRC_YASUI_LIBYS_UNITSCRIPT_HPP
#define KH2_SRC_YASUI_LIBYS_UNITSCRIPT_HPP

#include "../../common/types.h"

class DAMAGE;
class OBJ;
struct TASK;

namespace YS {

    class UNITSCRIPT {
    public:
     void ExecTask(TASK* a0);
     void Stop(s32 a0);
     void Finalizer(TASK* a0);
     void Init(void);
     u64 Start(void* a0);
     void Signal(s32 a0, s32 a1);
     void DamageCallback(OBJ* a0, DAMAGE* a1);
    };

}  // namespace YS

#endif

#ifndef KH2_SRC_YASUI_LIBYS_ATTACKOBJ_HPP
#define KH2_SRC_YASUI_LIBYS_ATTACKOBJ_HPP

#include "../../common/types.h"

class ATTACK_OBJ;
class ATTACK_WORK_MANAGER;
class BTLOBJ;
class STDOBJ;

namespace YS {

    class ATTACK_OBJ {
    public:
     ATTACK_OBJ(ATTACK_OBJ* a0, BTLOBJ* a1, STDOBJ* a2, s32 a3, ATTACK_OBJ** a4, s32 a5, s32 a6);
     ~ATTACK_OBJ();
     void make_work(ATTACK_WORK_MANAGER* a0);
     void Exec(void);
    };

}  // namespace YS

#endif

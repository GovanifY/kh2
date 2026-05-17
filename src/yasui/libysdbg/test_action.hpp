#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_ACTION_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_ACTION_HPP

#include "../../common/types.h"

class WIDGET;

namespace YS {

    class TEST_ACTION {
    public:
     void ActionIdle(s32 a0);
     void ActionFly(s32 a0);
     void ActionHover(s32 a0);
     void ActionHop(s32 a0);
     void ActionCarpet(s32 a0);
     void ActionLightCycle(s32 a0);
     void CarpetWindowFinalizer(WIDGET* a0);
     void Init(void);
    };

}  // namespace YS

#endif

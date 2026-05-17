#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_DAMAGE_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_DAMAGE_HPP

#include "../../common/types.h"

class EVENT;
class OBJ;
class TEST_DAMAGE;

namespace YS {

    class TEST_DAMAGE {
    public:
     TEST_DAMAGE(TEST_DAMAGE* a0, OBJ* a1);
     void Open(s32 a0);
     void SelectCallback(EVENT a0, s32 a1, void* a2);
     void Init(void);
     ~TEST_DAMAGE();
    };

}  // namespace YS

#endif

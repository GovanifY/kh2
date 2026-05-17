#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_BONUSLEVEL_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_BONUSLEVEL_HPP

#include "../../common/types.h"

class TEST_BONUSLEVEL;

namespace YS {

    class TEST_BONUSLEVEL {
    public:
     void set_flag(s32 a0);
     void check_flag(s32 a0);
     void Open(s32 a0);
     void Init(void);
     ~TEST_BONUSLEVEL();
    };

}  // namespace YS

#endif

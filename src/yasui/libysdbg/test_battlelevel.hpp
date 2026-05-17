#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_BATTLELEVEL_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_BATTLELEVEL_HPP

#include "../../common/types.h"

namespace YS {

    class TEST_BATTLELEVEL {
    public:
     void Open(s32 a0);
     void Apply(void* a0);
     void Reset(void* a0);
     void Init(void);
     s32 GetLevel(s32 a0);
    };

}  // namespace YS

#endif

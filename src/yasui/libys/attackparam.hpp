#ifndef KH2_SRC_YASUI_LIBYS_ATTACKPARAM_HPP
#define KH2_SRC_YASUI_LIBYS_ATTACKPARAM_HPP

#include "../../common/types.h"

namespace YS {

    class ATTACKPARAM {
    public:
     void Init(void* a0);
     u64 Get(s32 a0, s32 a1);
     s32 get_reflect_act(void);
    };

}  // namespace YS

#endif

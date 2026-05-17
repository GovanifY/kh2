#ifndef KH2_SRC_YASUI_LIBYS_TEAMWORK_HPP
#define KH2_SRC_YASUI_LIBYS_TEAMWORK_HPP

#include "../../common/types.h"

namespace YS {

    class TEAMWORK {
    public:
     void Init(void);
     void Ensure(void);
     u64 Alloc(s32 a0, s32 a1);
    };

}  // namespace YS

#endif

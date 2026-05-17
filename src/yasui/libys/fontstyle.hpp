#ifndef KH2_SRC_YASUI_LIBYS_FONTSTYLE_HPP
#define KH2_SRC_YASUI_LIBYS_FONTSTYLE_HPP

#include "../../common/types.h"

namespace YS {

    class FONTSTYLE {
    public:
     void Init(void* a0);
     s32 Get(s32 a0, s32 a1);
     s32 Compare(void* a0, void* a1);
    };

}  // namespace YS

#endif

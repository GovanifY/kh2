#ifndef KH2_SRC_YASUI_LIBYS_PLACE_HPP
#define KH2_SRC_YASUI_LIBYS_PLACE_HPP

#include "../../common/types.h"

namespace YS {

    class PLACE {
    public:
     s32 GetElem(s32 a0, s32 a1);
     void Init(void);
     u64 Get(s32 a0, s32 a1);
    };

}  // namespace YS

#endif

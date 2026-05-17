#ifndef KH2_SRC_YASUI_LIBYS_GACHA_HPP
#define KH2_SRC_YASUI_LIBYS_GACHA_HPP

#include "../../common/types.h"

class AREA;

namespace YS {

    class GACHA {
    public:
     s32 reset(s32 a0);
     void Reset(s32 a0);
     u64 Check(AREA* a0);
    };

}  // namespace YS

#endif

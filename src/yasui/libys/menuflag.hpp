#ifndef KH2_SRC_YASUI_LIBYS_MENUFLAG_HPP
#define KH2_SRC_YASUI_LIBYS_MENUFLAG_HPP

#include "../../common/types.h"

namespace YS {

    class MENUFLAG {
    public:
     void Set(s32 a0);
     void Reset(s32 a0);
     bool Check(s32 a0);
    };

}  // namespace YS

#endif

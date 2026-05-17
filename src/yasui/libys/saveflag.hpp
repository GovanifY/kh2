#ifndef KH2_SRC_YASUI_LIBYS_SAVEFLAG_HPP
#define KH2_SRC_YASUI_LIBYS_SAVEFLAG_HPP

#include "../../common/types.h"

namespace YS {

    class SAVEFLAG {
    public:
     void Set(u32 a0);
     void Reset(u32 a0);
     bool Check(u32 a0);
    };

}  // namespace YS

#endif

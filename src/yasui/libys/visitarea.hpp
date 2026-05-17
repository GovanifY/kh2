#ifndef KH2_SRC_YASUI_LIBYS_VISITAREA_HPP
#define KH2_SRC_YASUI_LIBYS_VISITAREA_HPP

#include "../../common/types.h"

namespace YS {

    class VISITAREA {
    public:
     void Visit(s32 a0, s32 a1);
     u64 IsVisit(s32 a0, s32 a1);
     void Reset(void);
    };

}  // namespace YS

#endif
